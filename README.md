#Perceptron

###What is this?
A class implementation of a usuable Perceptron in Python and C++.

###What is a Perceptron?
https://en.wikipedia.org/wiki/Perceptron

###TL;DR?
A supervised learning binary classifier.

###What?
The perceptron can be used to classify data by learning from existing data. It can be taught to classify linearbly separable data with pretty decent precision.

A common example is logical conjunctions. Take the OR function for example. If you wanted to implement a function that replaticated the behavior, we would start with the below known solutions:

Input	Output
--------------
A B 	A ^ B

0 0 	F
1 0 	T
0 1 	T
1 1 	t
	
We could implement an algorithm from this such as the following:
if A == 0 && B== 0:
	return False
else:
	return True

Or instead, we could feed the examples to the perceptron and it will make its own function. After that we can feed an input of A and B to it just like any other function and it will return 1 (True) or -1 (False).
The classifer code above and the classifier learned by the Perceptron will all grow linearbly with the number of features used. In the OR example there are two features: A and B. 
So if the complexity is around the same, why would you use a Percpetron instead of making your own function to classify data? Because the Percpetron can esitmate classifer functions better than you can. This is a foundational machine learning variation. Imagine for example if not only are we classifying with an A and a B input, but much more. A, B, C, D, E, F, etc. And imagine these features aren't just 1 or 0, but represetnations of image data. A could be a variable representing whether there is a face in the image and B could be whether the hair of that face is long or short. Using example data of images, you could use perceptrons to determine if an image of a face is that of a boy or girl. Or suppsoe the features are represntative of atmospheric conditions: A could be cloudy or not cloudy, B could be humid or not humid, C could be hot or cold, etc. Theorritically you could use the percptron to make a classifer to predict whether it wil lrain or not.

###How Does It Work?
The wikipedia page explains:
https://en.wikipedia.org/wiki/Perceptron
