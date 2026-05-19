import unittest
from test import permutations

class TestPermutations(unittest.TestCase):
    def test_permutations(self):
        self.assertCountEqual(permutations([2,3,5,7]),
                         [[2,3,5,7],[2,3,7,5],[2,5,3,7],[2,5,7,3],[2,7,3,5],[2,7,5,3],
                          [3,2,5,7],[3,2,7,5],[3,5,2,7],[3,5,7,2],[3,7,2,5],[3,7,5,2],
                          [5,2,3,7],[5,2,7,3],[5,3,2,7],[5,3,7,2],[5,7,3,2],[5,7,2,3],
                          [7,2,3,5],[7,2,5,3],[7,3,2,5],[7,3,5,2],[7,5,2,3],[7,5,3,2]])
        self.assertCountEqual(permutations([7,3,5]),[[7,3,5],[7,5,3],[3,7,5],[3,5,7],[5,3,7],[5,7,3]])
        self.assertCountEqual(permutations([1,2,3]),[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]])
        self.assertCountEqual(permutations([0,1]),[[0,1],[1,0]])
        self.assertCountEqual(permutations([1]),[[1]])
