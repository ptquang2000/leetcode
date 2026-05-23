import unittest
from test import (
    combinations,
    generate_balanced_parentheses,
    generate_power_set,
    n_queens,
    permutations,
    solve_sudoku,
)


class TestRecursion(unittest.TestCase):
    def test_combinations(self):
        self.assertCountEqual(combinations(4, 2), [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]])
        self.assertCountEqual(combinations(4, 3), [[1,2,3],[1,2,4],[1,3,4],[2,3,4]])
        self.assertCountEqual(combinations(1, 1), [[1]])

    def test_generate_balanced_parentheses(self):
        self.assertCountEqual(generate_balanced_parentheses(3), ["((()))","(()())","(())()","()(())","()()()"])
        self.assertCountEqual(generate_balanced_parentheses(2), ["(())", "()()"])
        self.assertCountEqual(generate_balanced_parentheses(1), ["()"])

    def test_generate_power_set(self):
        self.assertCountEqual(generate_power_set([1,2,3]), [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]])
        self.assertCountEqual(generate_power_set([0]), [[],[0]])
        self.assertCountEqual(generate_power_set([]), [[]])
        self.assertCountEqual(generate_power_set([1,2]), [[],[1],[2],[1,2]])

    def test_n_queens(self):
        self.assertCountEqual(n_queens(1), [[0]])
        self.assertCountEqual(n_queens(2), [])
        self.assertCountEqual(n_queens(3), [])
        self.assertCountEqual(n_queens(4), [[1,3,0,2],[2,0,3,1]])
        self.assertEqual(len(n_queens(5)), 10)
        self.assertEqual(len(n_queens(6)), 4)

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

    def test_solve_sudoku(self):
        partial_assignment = [
            [5,3,0,0,7,0,0,0,0],
            [6,0,0,1,9,5,0,0,0],
            [0,9,8,0,0,0,0,6,0],
            [8,0,0,0,6,0,0,0,3],
            [4,0,0,8,0,3,0,0,1],
            [7,0,0,0,2,0,0,0,6],
            [0,6,0,0,0,0,2,8,0],
            [0,0,0,4,1,9,0,0,5],
            [0,0,0,0,8,0,0,7,9]
        ]
        complete = [
            [5,3,4,6,7,8,9,1,2],
            [6,7,2,1,9,5,3,4,8],
            [1,9,8,3,4,2,5,6,7],
            [8,5,9,7,6,1,4,2,3],
            [4,2,6,8,5,3,7,9,1],
            [7,1,3,9,2,4,8,5,6],
            [9,6,1,5,3,7,2,8,4],
            [2,8,7,4,1,9,6,3,5],
            [3,4,5,2,8,6,1,7,9]
        ]
        solve_sudoku(partial_assignment)
        self.assertEqual(partial_assignment, complete)
