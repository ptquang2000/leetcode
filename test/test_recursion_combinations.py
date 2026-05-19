import unittest
from test import combinations

class TestCombinations(unittest.TestCase):
    def test_combinations(self):
        self.assertCountEqual(combinations(4, 2), [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]])
        self.assertCountEqual(combinations(4, 3), [[1,2,3],[1,2,4],[1,3,4],[2,3,4]])
        self.assertCountEqual(combinations(1, 1), [[1]])
