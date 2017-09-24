#include "Perceptron.h"
#include <iostream>
#include <fstream>

Perceptron::Perceptron(std::string trainingDataFileName, bool printDebug) {
	debug = printDebug;
	bias = 0;
	int** trainingData = readTrainingFile(trainingDataFileName, numberOfTestCases);
	train(trainingData, numberOfTestCases);
	delete trainingData;
};

int** Perceptron::readTrainingFile(std::string fileName, int &numberOfTestCases) {
	// Text file should only contain integers in the format:
	//		<number of features>
	//		<number of test cases>
	//		<test case 1>
	//		<test case 2>
	//		etc.
	//
	// Each test case should be a list of the feature values with preceded by the classification of 1 or -1

	std::ifstream in(fileName);
	if (!in) {
		std::cout << "ERROR: Input file doesn't exist";
		exit(1);
	}

	int **trainingData;
	std::string inputString;
	in >> inputString;
	this->numberOfFeatures = std::stoi(inputString);
	in >> inputString;
	numberOfTestCases = std::stoi(inputString);
	trainingData = new int*[numberOfTestCases];
	for (int i = 0; i < numberOfTestCases; i++) {
	 	trainingData[i] = new int[this->numberOfFeatures + 1];
	}
	int currentCase = 0;
	int currentFeature = 0;

	while(in >> inputString){
		trainingData[currentCase][currentFeature] = std::stoi(inputString);
		currentFeature++;
		if (in.peek() == '\n') {
			currentFeature = 0;
			currentCase++;
		}
	}

	if (debug) {
		std::cout << "File data (read):";
		for (int i = 0; i < numberOfTestCases; i++) {
			std::cout << "\n";
			for (int x = 0; x < this->numberOfFeatures + 1; x++) {
				std::cout << trainingData[i][x] << " ";
			}
		}
		std::cout << "\n";
	}

	return trainingData;
}

void Perceptron::train(int** trainingData, int &numberOfTestCases) {
	int numberOfCycles = 0;
	bool allPassed = false;
	weights = new float[this->numberOfFeatures]();
	float learningRate = 0.5;

	while (!allPassed) {
		allPassed = true;
		numberOfCycles++;

		if (numberOfCycles == 100) {
			std::cout << "100 cycles ran - probably no solutions. Aborting...";
			break;
		}

		for (int testCase = 0; testCase < numberOfTestCases; testCase++) {
			float total = bias;
			int result = *trainingData[testCase];
			for (int caseWeightCounter = 0; caseWeightCounter < this->numberOfFeatures; caseWeightCounter++) {
				total += trainingData[testCase][caseWeightCounter + 1] * this->weights[caseWeightCounter];
			}

			if (result > 0) {
				if (total  <= 0) {
					//add
					if (debug) std::cout << "(" << numberOfCycles << ") " << total << " NOT > 0\nNew Weights = [";
					for (int weightCount = 0; weightCount < this->numberOfFeatures; weightCount++) {
						this->weights[weightCount] = this->weights[weightCount] + trainingData[testCase][weightCount + 1] * learningRate;
						if (debug) std::cout << this->weights[weightCount] << ", ";
					}
					bias += learningRate;
					if (debug) std::cout << "]\nNew bias = " << bias << "\n";
					allPassed = false;
				}
			} else if (result < 0) {
				if (total  > 0) {
					//subtract
					if (debug) std::cout << total << " NOT <= 0\nNew Weights = [";
					for (int weightCount = 0; weightCount < this->numberOfFeatures; weightCount++) {
						this->weights[weightCount] = this->weights[weightCount] - trainingData[testCase][weightCount + 1] * learningRate;
						if (debug) std::cout << this->weights[weightCount] << ", ";
					}
					bias -= learningRate;
					if (debug) std::cout << "]\nNew bias = " << bias << "\n";
					allPassed = false;
				}
			}
		}
	}
}

int Perceptron::classify(int *featureSet) {
	float total = bias;
	for (int i = 0; i < this->numberOfFeatures; i++) {
		total += this->weights[i] * featureSet[i];
	}
	return (total <= 0) ? -1 : 1;
}

void Perceptron::print() {
	std::cout << "Number of features: " << this->numberOfFeatures << "\n";
	std:: cout << "Weights: ";
	for (int i = 0; i < this->numberOfFeatures; i++) {
		std::cout << weights[i] << " ";
	}
	std::cout << "\nBias = " << this->bias << "\n";
}