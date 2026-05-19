import unittest
from test import next_permutation

class TestNextPermutation(unittest.TestCase):
    def test_next_permutation(self):
        self.assertEqual(next_permutation([1,0,3,2]), [1,2,0,3])
        self.assertEqual(next_permutation([3,2,1,0]), [])
        self.assertEqual(next_permutation([6,2,1,5,4,3,0]), [6,2,3,0,1,4,5])
