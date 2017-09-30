from Perceptron import Perceptron
import unittest

class PerceptronTest(unittest.TestCase):

    def testOR(self):
        print 'Running OR Test Case:'
        perc = Perceptron([[0,0,-1], [0,1,1], [1,0,1], [1,1,1]],2, True)
        self.assertEqual(perc.classify([0,0]), -1)
        self.assertEqual(perc.classify([1,0]), 1)
        self.assertEqual(perc.classify([0,1]), 1)
        self.assertEqual(perc.classify([1,1]), 1)

    def testAND(self):
        print 'Running AND Test Case:'
        perc = Perceptron([[0,0,-1], [0,1,-1], [1,0,-1], [1,1,1]],2, True)
        self.assertEqual(perc.classify([0,0]), -1)
        self.assertEqual(perc.classify([1,0]), -1)
        self.assertEqual(perc.classify([0,1]), -1)
        self.assertEqual(perc.classify([1,1]), 1)

    # 3 Feature

    def testOR3(self):
        print 'Running OR3 Test Case:'
        perc = Perceptron([[0,0,0,-1], [0,0,1,1], [0,1,0,1], [1,0,0,1], [1,0,1,1]],3, True)
        self.assertEqual(perc.classify([0,0,0]), -1)
        self.assertEqual(perc.classify([0,0,1]), 1)
        self.assertEqual(perc.classify([0,1,0]), 1)
        self.assertEqual(perc.classify([1,0,0]), 1)
        self.assertEqual(perc.classify([1,0,1]), 1)
        # Not defined
        self.assertEqual(perc.classify([0,1,1]), 1)
        self.assertEqual(perc.classify([1,1,0]), 1)
        self.assertEqual(perc.classify([1,1,1]), 1)

    def testAtLeastTwo3(self):
        print 'Running AtLeastTwo Test Case:'
        perc = Perceptron([[0,0,0,-1], [0,0,1,-1], [0,1,0,-1], [1,0,0,-1], [1,0,1,1], [0,1,1,1]],3, True)
        self.assertEqual(perc.classify([0,0,0]), -1)
        self.assertEqual(perc.classify([0,0,1]), -1)
        self.assertEqual(perc.classify([0,1,0]), -1)
        self.assertEqual(perc.classify([1,0,0]), -1)
        self.assertEqual(perc.classify([1,0,1]), 1)
        self.assertEqual(perc.classify([0,1,1]), 1)
        # Not defined
        self.assertEqual(perc.classify([1,1,0]), 1)
        self.assertEqual(perc.classify([1,1,1]), 1)

if __name__ == '__main__':
    unittest.main()