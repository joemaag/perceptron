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
When creating a Perceptron object, you must include 1.) training data and 2.) number of features.

### Constructing With Training data
```
Perceptron([feature1_instance1, feature2_instance1, featureX_instance1, classification1], [feature1_instance2, feature2_instance2, featureX_instance1, classification2], ..., Xnumber_of_features)
```
Where:

* `feature_instance` = floating point
* `classification` = `1` or `-1`
* `number_of_features` = integer

Example for training the AND function:
```
perc = Perceptron([[0,0,-1], [0,1,-1], [1,0,-1], [1,1,1]], 2)
```

### Classifying
Once the perceptron has been trained, you can classify your own data by supplying a list of feature values:
```
Perceptron.classify([feature1_instance, feature2_instance, featureX_instance, ...])
```
Where:

* `feature_instance` = floating point

This will return a classification of `1` or `-1`.

## Debug Print Statements
In Perceptron.py you'll see a `debug` variable set to `False`. Set this to `True` to see some insight into the weight training process.