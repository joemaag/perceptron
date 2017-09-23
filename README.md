#Perceptron

(For usage documentation, see the Python or C++ directories)

##What is this?
A class implementation of a useable Perceptron in Python and C++.

###What is a Perceptron?
https://en.wikipedia.org/wiki/Perceptron

###TL;DR?
A supervised learning binary classifier.

###Go On?
The perceptron can be used to classify data by learning from existing data. It can be taught to classify linearly separable data with pretty decent precision. Because this is a binary classifier, data can only be classified into two classes/categories. On a code level, this is `-1` or `1`. However to some degree this can represent any sort of real world classification like good or bad, hot or cold, rain or no rain. With the proper feature set derived from photo data, even something like facial detection in photos could be classified with ok-ish accuracy (If it isn't obvious, it is worth noting that there are more sophisticated algorithms for such classifiers. But it should not be understated how powerful the fundamental ideas of a supervised learning binary classifiers can be).

After the perceptron is trained, classification can be represented by the below function: 
![source: https://en.wikipedia.org/wiki/Perceptron][assets/classification.png]

Where `w` is the weight vector, `x` is the feature vector, and `b` is the bias. 

The training algorithm is a little more verbose, so I'll leave that to the wikipedia page. The goal of it is to determine a decision boundary that separates the data. The weight vector changes the slope of the boundary and the bias basically translates that boundary. You may notice it looks similar to the line function `y=mx+b`. You can visualize it similarly, but but because `x` has two variables, it would have to be graphed in a 3D space.

For more information on how it works, check out the wiki page:
https://en.wikipedia.org/wiki/Perceptron.


## Examples
Both implementations have runnable tests. Without the debug flag enabled, you won't see much. So basically they have a few sets of data used to train individual perceptrons. It then uses those to classify a number of feature data sets, and the test will determine if the perceptron correctly estimated those. The data sets used are not too complex but all represent logical conjunctions derivatives. The idea with them is to predict the boolean function that classifies the existing data correctly. Then when we throw new data sets at it that it has never seem, and see if it will properly classify it.

For example, one set of data has 3 inputs of either `0` or `1`. Looking at those three input values, we want to determine whether it should be classified as `1` or `-1`. We have a few pre-determined examples to work off of:

    0,0,0 -> -1
    0,0,1 -> -1
    0,1,0 -> -1
    1,0,1 ->  1
    0,1,1 ->  1

You can think of this as a three variable function that in the above examples will calculate to `-1` or `1`. So now we want to know, what would `1,1,0` equate to? `1` or `-1`? We can train the Perceptron off the above examples to determine that. Once trained, the test will throw `1,1,0` at the Perceptron and will see if it correctly spits out the correct classification (In this case the correct classification is `1`. The actual boolean function represented by this data is one that returns returns `1` if at least two variables are `1`).

##Multiclass Classifier?
In the works.

##Usage
See the Python and C++ directories for a usage doc.