import unittest
from test import matrix_in_spiral_order

class TestMatrixInSpiralOrder(unittest.TestCase):
    def test_matrix_in_spiral_order(self):
        matrix = [
            [1,2,3],
            [4,5,6],
            [7,8,9],
        ]
        self.assertEqual(matrix_in_spiral_order(matrix), [1,2,3,6,9,8,7,4,5])
        matrix = [
            [ 1, 2, 3, 4],
            [ 5, 6, 7, 8],
            [ 9,10,11,12],
            [13,14,15,16],
        ]
        self.assertEqual(matrix_in_spiral_order(matrix), [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10])
