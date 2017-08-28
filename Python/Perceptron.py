class Perceptron:

	debug = False

	def classify(self, featureVector):
		total = self.bias
		for index, feature in enumerate(featureVector):
			total += feature * self.weights[index]

		return -1 if total <= 0 else 1

	def train(self, trainingSet, numberOfFeatures, learningRate = 0.5):
		allPassed = False
		cycleCount = 0
		bias = 0
		weights = [0 for x in range(numberOfFeatures)]

		while (allPassed == False):
			if cycleCount > 100:
				print ('100 cycles ran - probably no solutions. Aborting...')
				break
			allPassed = True

			for instance in trainingSet:
				cycleCount += 1
				sum = bias
				result = instance[-1]

				for index, featureValue in enumerate(instance):
					if index == len(instance) - 1:
						continue
					sum += featureValue * weights[index]

				if result == 1:
					if sum <= 0:
						#add
						for index, weight in enumerate(weights):
							weights[index] = weight + (instance[index] * learningRate)
						bias = bias + learningRate
						allPassed = False
						if self.debug:
							print str(sum) + ' NOT > 0'
							print 'New Weights = ' + str(weights) + '\nNew Bias = ' + str(bias)

				elif result == -1:
					if sum > 0:
						#subtract
						for index, weight in enumerate(weights):
							weights[index] = weight - (instance[index] * learningRate)
						bias = bias - learningRate
						allPassed = False
						if self.debug:
							print str(sum) + ' NOT < 0'
							print 'New Weights = ' + str(weights) + '\nNew Bias = ' + str(bias)

		if self.debug:
			print 'Done!\nWeights = ' + str(weights)
			print 'Bias = ' + str(bias)
			print 'Ran ' + str(cycleCount) + ' cycles\n'
		return (weights, bias)


	def __init__(self, trainingSet, numberOfFeatures):
		self.weights, self.bias = self.train(trainingSet, numberOfFeatures)
