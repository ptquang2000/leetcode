import unittest
from test import n_queens

class TestNQueens(unittest.TestCase):
    def test_n_queens(self):
        self.assertCountEqual(n_queens(1), [[0]])
        self.assertCountEqual(n_queens(4), [[1,3,0,2],[2,0,3,1]])
