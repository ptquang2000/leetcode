import unittest
from test import rotate_matrix

class TestRotateMatrix(unittest.TestCase):
    def test_rotate_matrix(self):
        matrix = [
            [ 1, 2, 3, 4],
            [ 5, 6, 7, 8],
            [ 9,10,11,12],
            [13,14,15,16],
        ]
        rotated_matrix = [
            [13, 9, 5, 1],
            [14,10, 6, 2],
            [15,11, 7, 3],
            [16,12, 8, 4],
        ]
        rotate_matrix(matrix)
        self.assertEqual(matrix, rotated_matrix)
