import unittest
from test import (
    generate_pascal_triangle,
    is_valid_sudoku,
    matrix_in_spiral_order,
    rotate_matrix,
)


class TestMultiDimArray(unittest.TestCase):
    def test_generate_pascal_triangle(self):
        result = [
            [1],
            [1,1],
            [1,2,1],
            [1,3,3,1],
            [1,4,6,4,1],
        ]
        self.assertEqual(generate_pascal_triangle(5), result)
        self.assertEqual(generate_pascal_triangle(0), [])
        self.assertEqual(generate_pascal_triangle(1), [[1]])
        self.assertEqual(generate_pascal_triangle(2), [[1],[1,1]])
        self.assertEqual(generate_pascal_triangle(3), [[1],[1,1],[1,2,1]])

    def test_is_valid_sudoku(self):
        partial_sudoku = [
            [5,3,0,0,7,0,0,0,0],
            [6,0,0,1,9,5,0,0,0],
            [0,9,8,0,0,0,0,6,0],
            [8,0,0,0,6,0,0,0,3],
            [4,0,0,8,0,3,0,0,1],
            [7,0,0,0,2,0,0,0,6],
            [0,6,0,0,0,0,2,8,0],
            [0,0,0,4,1,9,0,0,5],
            [0,0,0,0,8,0,0,7,9],
        ]
        self.assertFalse(is_valid_sudoku(partial_sudoku))
        completed_sudoku = [
            [5,3,4,6,7,8,9,1,2],
            [6,7,2,1,9,5,3,4,8],
            [1,9,8,3,4,2,5,6,7],
            [8,5,9,7,6,1,4,2,3],
            [4,2,6,8,5,3,7,9,1],
            [7,1,3,9,2,4,8,5,6],
            [9,6,1,5,3,7,2,8,4],
            [2,8,7,4,1,9,6,3,5],
            [3,4,5,2,8,6,1,7,9],
        ]
        self.assertTrue(is_valid_sudoku(completed_sudoku))
        completed_sudoku = [
            [5,3,4,6,7,8,9,1,2],
            [6,7,2,1,9,5,3,4,8],
            [1,9,8,3,4,2,5,6,7],
            [8,5,9,7,6,1,4,2,3],
            [4,2,6,8,5,3,7,9,1],
            [7,1,3,9,2,4,8,5,6],
            [9,6,1,5,3,7,2,1,4],
            [2,8,7,4,1,9,6,3,5],
            [3,4,5,2,8,6,1,7,9],
        ]
        self.assertFalse(is_valid_sudoku(completed_sudoku))

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
        self.assertEqual(matrix_in_spiral_order([[7]]), [7])
        self.assertEqual(matrix_in_spiral_order([[1,2,3]]), [1,2,3])
        self.assertEqual(matrix_in_spiral_order([[1],[2],[3]]), [1,2,3])
        self.assertEqual(matrix_in_spiral_order([[1,2],[3,4]]), [1,2,4,3])

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

        matrix = [[1]]
        rotate_matrix(matrix)
        self.assertEqual(matrix, [[1]])

        matrix = [[1,2],[3,4]]
        rotate_matrix(matrix)
        self.assertEqual(matrix, [[3,1],[4,2]])

        matrix = [
            [1,2,3],
            [4,5,6],
            [7,8,9],
        ]
        rotate_matrix(matrix)
        self.assertEqual(matrix, [[7,4,1],[8,5,2],[9,6,3]])
