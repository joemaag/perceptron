#include "Perceptron.h"
#include <iostream>

void testOR() {
	Perceptron perc = Perceptron("OR.txt");
	bool pass = true;
	int ex[] = {0,0};
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: 0 OR 0\n";
		pass = false;
	}
	ex[1] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 0 OR 1\n";
		pass = false;
	}
	ex[1] = 0;
	ex[0] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 1 OR 0\n";
		pass = false;
	}
	ex[1] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 1 OR 1\n";
		pass = false;
	}

	if (pass) {
		std::cout << "OR test cases PASSED\n";
	}
}

void testAND() {
	Perceptron perc = Perceptron("AND.txt");
	bool pass = true;
	int ex[] = {0,0};
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: 0 AND 0\n";
		pass = false;
	}
	ex[1] = 1;
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: 0 AND 1\n";
		pass = false;
	}
	ex[1] = 0;
	ex[0] = 1;
	if (perc.classify(ex) != -1) {
		std::cout << "Test Case FAIL: 1 AND 0\n";
		pass = false;
	}
	ex[1] = 1;
	if (perc.classify(ex) != 1) {
		std::cout << "Test Case FAIL: 1 AND 1\n";
		pass = false;
	}

	if (pass) {
		std::cout << "AND test cases PASSED\n";
	}
}

void testOR3() {
	Perceptron perc = Perceptron("OR3.txt");
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

	// Undefined
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
		std::cout << "OR3 test cases PASSED\n";
	}
}

void testAtLeastTwo3() {
	Perceptron perc = Perceptron("atLeastTwo3.txt");
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

	//Undefined
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
		std::cout << "AtLeastTwo test cases PASSED\n";
	}
}

int main() {
	testOR();
	testAND();
	testOR3();
	testAtLeastTwo3();
	return 0;
}