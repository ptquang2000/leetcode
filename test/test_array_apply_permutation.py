import unittest
from test import apply_permutation

class TestApplyPermutation(unittest.TestCase):
    def test_apply_permutation(self):
        A = ['a','b','c','d']
        apply_permutation([3,2,1,0], A)
        self.assertEqual(A, ['d','c','b','a'])
        A = ['a','b','c','d']
        apply_permutation([2,0,1,3], A)
        self.assertEqual(A, ['b','c','a','d'])
