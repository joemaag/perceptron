#include <iostream>
#include <string>
#include <fstream>


void readTrainingFile(std::string, int**&, int&, int&);
void printSelf(int**&, int&, int&);
float* train(int**&, int&, int&);

int main() {
	std::cout << "this is a a test!";

	int **trainingData;
	int numberOfTestCases;
	int numberOfFeatures;

	readTrainingFile("input.txt", trainingData, numberOfTestCases, numberOfFeatures);
	printSelf(trainingData, numberOfTestCases, numberOfFeatures);
	float* weights = train(trainingData, numberOfTestCases, numberOfFeatures);

	std::cout << "--- Weights ---\n";
	for (int i = 0; i < numberOfFeatures; i++) {
		std::cout  << weights[i] << " ";
	}
	std::cout << "\n";


	// int** classification = (int**)malloc(sizeof(int*) * numberOfTestCases * numberOfFeatures);
	// int** c2 = new int*[numberOfTestCases];
	// for (int i = 0; i < numberOfFeatures; i++) {
	// 	c2[i] = new int[numberOfFeatures];
	// }



	return 0;
}

// int[] train(int trainingSet[][], int numberOfFeatures, int learningRate){
// 	int weights[];
// 	bool allPassed = false;

// 	while(!allPassed) {

// 	}
// }

void readTrainingFile(std::string fileName, int**& trainingData, int &numberOfTestCases, int &numberOfFeatures) {

	std::ifstream in(fileName);
	if (!in) {
		std::cout << "ERROR: Input file doesn't exist";
		exit(1);
	}

	std::string inputString;
	in >> inputString;
	numberOfFeatures = std::stoi(inputString);
	in >> inputString;
	numberOfTestCases = std::stoi(inputString);
	//trainingData = new (std::nothrow) int[numberOfTestCases][numberOfFeatures + 1];
	trainingData = new int*[numberOfTestCases];
	for (int i = 0; i < numberOfFeatures; i++) {
	 	trainingData[i] = new int[numberOfFeatures];
	}
	int caseCount = 0;
	int featureCount = 0;

	while(in >> inputString){
		std::cout << caseCount << " " << featureCount << "\n";
		trainingData[caseCount][featureCount] = std::stoi(inputString);
		featureCount++;
		if (in.peek() == '\n') {
			featureCount = 0;
			caseCount++;
		}
	}

	for (int i = 0; i < numberOfTestCases; i++) {
		for (int x = 0; x < numberOfFeatures + 1; x++) {
			std::cout << trainingData[i][x] << "\n";
		}
	}
}

void printSelf(int**& trainingData, int &numberOfTestCases, int &numberOfFeatures) {
	std::cout << "Test Cases = " << numberOfTestCases << "\n";
	std::cout << "Features = " << numberOfFeatures;
	for (int i = 0; i < numberOfTestCases; i++) {
		std::cout << "\n";
		for (int x = 0; x < numberOfFeatures + 1; x++) {
			std::cout << trainingData[i][x] << " ";
		}
	}
}

float* train(int**& trainingData, int &numberOfTestCases, int &numberOfFeatures) {
	int numberOfCycles = 0;
	bool allPassed = false;
	float *weights = new float[numberOfFeatures]();
	std::cout << "Numebr fo features: " << numberOfFeatures << "\n";
	int bias = 0;

	while (!allPassed) {
		allPassed = true;
		numberOfCycles++;

		for (int i = 0; i < numberOfFeatures; i++) {
			std::cout << weights[i] << " ";
		}
		std::cout << "\n";

		if (numberOfCycles == 20) {
			break;
		}
		for (int testCase = 0; testCase < numberOfTestCases; testCase++) {
			int* caseData = trainingData[testCase];
			int result = caseData[0];
			caseData++;
			int total = 0;
			for (int caseWeightCounter = 0; caseWeightCounter < numberOfFeatures; caseWeightCounter++) {
				total += caseData[caseWeightCounter] * weights[caseWeightCounter];
			}

			if (result > 0) {
				if (total  <= 0) {
					for (int weightCount = 0; weightCount < numberOfFeatures; weightCount++) {
						std::cout << "HEY " << weightCount << "==" << caseData[weightCount] << "\n";
						std::cout << "Weight was: " << weights[weightCount] << ", now: ";
						weights[weightCount] = weights[weightCount] + caseData[weightCount] * 0.5;
						std::cout << weights[weightCount] << " (" << caseData[weightCount] <<" * 0.5)\n";
					}
					bias += 0.5;
					allPassed = false;
					std::cout << "add\n";
				}
			} else if (result < 0) {
				if (total  > 0) {
					for (int weightCount = 0; weightCount < numberOfFeatures; weightCount++) {
						weights[weightCount] = weights[weightCount] - caseData[weightCount] * 0.5;
					}
					bias -= 0.5;
					allPassed = false;
					std::cout << "subtract\n";
				}
			}
		}
	}
	return weights;
}