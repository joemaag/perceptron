#include <string>

class Perceptron {
	private:
		float *weights;
		float bias;
		int numberOfFeatures;
		int numberOfTestCases;
		bool debug;
		int **readTrainingFile(std::string fileName, int &numberOfTestCases);
		void train(int **trainingData, int &numberOfTestCases);

	public:
		Perceptron(std::string trainingDataFileName, bool printDebug = false);
		int classify(int *featureSet);
		void print();

};