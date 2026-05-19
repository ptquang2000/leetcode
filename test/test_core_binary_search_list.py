import unittest
from test import binary_search

class TestBinarySearchList(unittest.TestCase):

    def test_binary_search(self):
        foo = [1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420]
        self.assertTrue(binary_search(foo, 69))
        self.assertFalse(binary_search(foo, 1336))
        self.assertTrue(binary_search(foo, 69420))
        self.assertFalse(binary_search(foo, 69421))
        self.assertTrue(binary_search(foo, 1))
        self.assertFalse(binary_search(foo, 0))
