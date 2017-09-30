class Perceptron:

	def classify(self, featureVector):
		total = self.bias
		for index, feature in enumerate(featureVector):
			total += feature * self.weights[index]

		return -1 if total <= 0 else 1

	def train(self, trainingSet, numberOfFeatures, learningRate = 0.2):
		allPassed = False
		cycleCount = 0
		traningPassCount = 0
		bias = 0
		weights = [0 for x in range(numberOfFeatures)]

		while (allPassed == False):
			if cycleCount > 100:
				print ('100 cycles ran - probably no solutions. Aborting...')
				break
			allPassed = True
			traningPassCount += 1
			if (self.debug): print "Training Pass #" + str(traningPassCount)

			for trainingCase in trainingSet:
				cycleCount += 1
				sum = bias
				result = trainingCase[-1]

				for index, featureValue in enumerate(trainingCase):
					if index == len(trainingCase) - 1:
						continue
					sum += featureValue * weights[index]

				if result == 1:
					if sum <= 0:
						#add
						for index, weight in enumerate(weights):
							weights[index] = weight + (trainingCase[index] * learningRate)
						bias = bias + learningRate
						allPassed = False
						if self.debug:
							print "\tTraining Case #" + str(cycleCount) + ": " + str(sum) + " NOT > 0"
							print '\tNew Weights = ' + str(weights) + '\n\tNew Bias = ' + str(bias) + "\n"

				elif result == -1:
					if sum > 0:
						#subtract
						for index, weight in enumerate(weights):
							weights[index] = weight - (trainingCase[index] * learningRate)
						bias = bias - learningRate
						allPassed = False
						if self.debug:
							print "\tTraining Case #" + str(cycleCount) + ": " + str(sum) + " NOT <= 0"
							print '\tNew Weights = ' + str(weights) + '\n\tNew Bias = ' + str(bias) + "\n"

		if self.debug:
			print '\nTRAINING COMPLETE\nFinal Weights = ' + str(weights)
			print 'Final Bias = ' + str(bias) + "\n\n"
		return (weights, bias)

	def __init__(self, trainingSet, numberOfFeatures, debug=False):
		self.debug = debug
		self.weights, self.bias = self.train(trainingSet, numberOfFeatures)
