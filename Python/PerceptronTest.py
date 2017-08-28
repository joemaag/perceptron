from Perceptron import Perceptron
import unittest

class PerceptronTest(unittest.TestCase):

    def testOR(self):
        print 'OR\n'
        perc = Perceptron([[0,0,-1], [0,1,1], [1,0,1], [1,1,1]],2)
        self.assertEqual(perc.classify([0,0]), -1)
        self.assertEqual(perc.classify([1,0]), 1)
        self.assertEqual(perc.classify([0,1]), 1)
        self.assertEqual(perc.classify([1,1]), 1)

    def testAND(self):
        print 'AND\n'
        perc = Perceptron([[0,0,-1], [0,1,-1], [1,0,-1], [1,1,1]],2)
        self.assertEqual(perc.classify([0,0]), -1)
        self.assertEqual(perc.classify([1,0]), -1)
        self.assertEqual(perc.classify([0,1]), -1)
        self.assertEqual(perc.classify([1,1]), 1)

    # 3 Feature

    def testOR3(self):
        print 'OR3\n'
        perc = Perceptron([[0,0,0,-1], [0,0,1,1], [0,1,0,1], [1,0,0,1], [1,0,1,1]],3)
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
        print 'AtLeastTwo\n'
        perc = Perceptron([[0,0,0,-1], [0,0,1,-1], [0,1,0,-1], [1,0,0,-1], [1,0,1,1], [0,1,1,1]],3)
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