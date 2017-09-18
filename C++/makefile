CC = g++
OBJS = Perceptron.o Tester.o
PERC_SRC = src
PERC_INCLUDE = include
PERC_TEST = test

PerceptronTest: $(OBJS)
	$(CC) -Wall $(OBJS) -o PerceptronTest

Tester.o: $(PERC_TEST)/Tester.cpp $(PERC_INCLUDE)/Perceptron.h
	$(CC) -Wall -c -I$(PERC_INCLUDE) $(PERC_TEST)/Tester.cpp

Perceptron.o: $(PERC_INCLUDE)/Perceptron.h $(PERC_SRC)/Perceptron.cpp
	$(CC) -Wall -I$(PERC_INCLUDE) -c $(PERC_SRC)/Perceptron.cpp