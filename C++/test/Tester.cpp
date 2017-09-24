#include "Perceptron.h"
#include <iostream>

void testOR(bool debug) {
	Perceptron perc = Perceptron("test/OR.txt", debug);
	bool pass = true;
	int ex[] = {0,0};
	// 0 0
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: 0 OR 0\n";
		pass = false;
	}
	// 0 1
	ex[1] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 0 OR 1\n";
		pass = false;
	}
	// 1 0
	ex[1] = 0;
	ex[0] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 1 OR 0\n";
		pass = false;
	}
	// 1 1
	ex[1] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 1 OR 1\n";
		pass = false;
	}

	if (pass) {
		std::cout << "OR test cases PASSED\n" << (debug ? "\n\n" : "");
	}
}

void testAND(bool debug) {
	Perceptron perc = Perceptron("test/AND.txt", debug);
	bool pass = true;
	int ex[] = {0,0};
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: 0 AND 0\n";
		pass = false;
	}
	// 0 1
	ex[1] = 1;
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: 0 AND 1\n";
		pass = false;
	}
	// 1 0
	ex[1] = 0;
	ex[0] = 1;
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: 1 AND 0\n";
		pass = false;
	}
	// 1 1
	ex[1] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 1 AND 1\n";
		pass = false;
	}

	if (pass) {
		std::cout << "AND test cases PASSED\n" << (debug ? "\n\n" : "");
	}
}

void testOR3(bool debug) {
	Perceptron perc = Perceptron("test/OR3.txt", debug);
	bool pass = true;
	int ex[] = {0,0,0};
	// 0 0 0
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: 0 OR 0 OR 0\n";
		pass = false;
	}
	// 0 0 1
	ex[2] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 0 OR 0 OR 1\n";
		pass = false;
	}
	// 0 1 0
	ex[2] = 0;
	ex[1] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 0 OR 1 OR 0\n";
		pass = false;
	}
	// 1 0 0
	ex[1] = 0;
	ex[0] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 1 OR 0 OR 0\n";
		pass = false;
	}
	// 1 0 1
	ex[2] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 1 OR 0 OR 1\n";
		pass = false;
	}
	// 0 1 1
	ex[0] = 0;
	ex[1] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 0 OR 1 OR 1\n";
		pass = false;
	}
	// 1 1 0
	ex[1] = 1;
	ex[2] = 0;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 1 OR 1 OR 0\n";
		pass = false;
	}
	// 1 1 1
	ex[0] = 1;
	ex[2] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 1 OR 1 OR 1\n";
		pass = false;
	}

	if (pass) {
		std::cout << "OR3 test cases PASSED\n" << (debug ? "\n\n" : "");
	}
}

void testAtLeastTwo3(bool debug) {
	Perceptron perc = Perceptron("test/atLeastTwo3.txt", debug);
	bool pass = true;
	int ex[] = {0,0,0};
	// 0 0 0
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: At least 2, 0 - 0 - 0\n";
		pass = false;
	}
	// 0 0 1
	ex[2] = 1;
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: At least 2, 0 - 0 - 1\n";
		pass = false;
	}
	// 0 1 0
	ex[2] = 0;
	ex[1] = 1;
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: At least 2, 0 - 1 - 0\n";
		pass = false;
	}
	// 1 0 0
	ex[1] = 0;
	ex[0] = 1;
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: At least 2, 1 - 0 - 0\n";
		pass = false;
	}
	// 1 0 1
	ex[2] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: At least 2, 1 - 0 - 1\n";
		pass = false;
	}
	// 0 1 1
	ex[0] = 0;
	ex[1] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: At least 2, 0 - 1 - 1\n";
		pass = false;
	}
	// 1 1 0
	ex[0] = 1;
	ex[2] = 0;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: At least 2, 1 - 1 - 0\n";
		pass = false;
	}
	// 1 1 1
	ex[2] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: At least 2, 1 - 1 - 1\n";
		pass = false;
	}

	if (pass) {
		std::cout << "AtLeastTwo test cases PASSED\n" << (debug ? "\n\n" : "");
	}
}

int main(int argc, const char* argv[]) {
	bool debug = false;

	if (argc > 1 && strcmp(argv[1], "-debug") == 0) {
		debug = true;
	}

	testOR(debug);
	testAND(debug);
	testOR3(debug);
	testAtLeastTwo3(debug);

	if (!debug) std::cout << "---- Enter \"./PerceptronTest -debug\" to see training logs ----\n";

	return 0;
}