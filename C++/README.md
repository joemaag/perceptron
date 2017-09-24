# Perceptron - C++

### Quick Test Run
You can compile and run the test using `make` to produce the executable.

    cd /path/to/Perceptron/C++
    make

The resulting PerceptronTest executable can then be run:

```
./PerceptronTest
```

## Usage
When creating a Perceptron object, you must supply a directory string to where the training data file is. The training data must be in a .txt file in the following format (without '<>' characters):

    <number_of_features>
    <number_of_test_cases>
    <classification_case1> <feature1_case1> <feature2_case1> etc.
    <classification_case2> <feature1_case2> <feature2_case2> etc.
    etc.

Where:

* `number_of_features` = integer
* `number_of_test_cases` = integer
* `classification` = `1` or `-1`
* `feature_case` = floating point

Example for training the AND function:

```
Perceptron perc = Perceptron("OR.txt");
```
Where OR.txt has:

    2
    4
    -1 0 0
    1 0 1
    1 1 0
    1 1 1

Supplying the training file in the constructor will immediately train the perceptron upon initialization. No further action is required, and the perceptron is ready for classification usage.

### Classifying
Once the perceptron has been trained, you can have it classify your own data by supplying an array of feature values:

    int ex[] = {feature1_value, feature2_value, etc.};
    int exClassification = perc.classify(ex);

Where:

* `feature_value` = floating point

This will return a classification of `1` or `-1`.

## Debug Print Statements
In Perceptron.cpp there is a `debug` variable set to `false` by default. You can optionally set it to `true` in the constructor to see some insight into the weight training process in the console:

```
Perceptron perc = Perceptron("OR.txt", false);
```

To see debug statements in the tests, manually set these in the Perceptron constructors in the test file, Tester.cpp. Then run `make` again.