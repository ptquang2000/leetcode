import unittest
from test import linear_search

class TestLinearSearchList(unittest.TestCase):

    def test_linear_search(self):
        foo = [1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420]
        self.assertTrue(linear_search(foo, 69))
        self.assertFalse(linear_search(foo, 1336))
        self.assertTrue(linear_search(foo, 69420))
        self.assertFalse(linear_search(foo, 69421))
        self.assertTrue(linear_search(foo, 1))
        self.assertFalse(linear_search(foo, 0))
