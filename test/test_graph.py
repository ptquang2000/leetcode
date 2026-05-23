import unittest
from test import (
    filled_surrounded_region,
    flip_color,
    search_maze,
)


class TestGraph(unittest.TestCase):
    def test_filled_surrounded_region(self):
        board = [
            ['B', 'B', 'B', 'B'],
            ['W', 'B', 'W', 'B'],
            ['B', 'W', 'W', 'B'],
            ['B', 'B', 'B', 'B'],
        ]
        filled_surrounded_region(board, 'W', 'B')
        self.assertEqual(board, [
            ['B', 'B', 'B', 'B'],
            ['W', 'B', 'B', 'B'],
            ['B', 'B', 'B', 'B'],
            ['B', 'B', 'B', 'B'],
        ])

        board = [
            ['B', 'B', 'B', 'B'],
            ['B', 'W', 'W', 'B'],
            ['B', 'B', 'W', 'B'],
            ['B', 'W', 'B', 'B'],
        ]
        filled_surrounded_region(board, 'W', 'B')
        self.assertEqual(board, [
            ['B', 'B', 'B', 'B'],
            ['B', 'B', 'B', 'B'],
            ['B', 'B', 'B', 'B'],
            ['B', 'W', 'B', 'B'],
        ])

        board = [['B']]
        filled_surrounded_region(board, 'W', 'B')
        self.assertEqual(board, [['B']])

    def test_flip_color(self):
        A = [
            [1, 0, 1, 0, 0, 0, 1, 1, 1, 1],
            [0, 0, 1, 0, 0, 1, 0, 0, 1, 1],
            [1, 1, 1, 0, 0, 1, 1, 0, 1, 1],
            [0, 1, 0, 1, 1, 1, 1, 0, 1, 0],
            [1, 0, 1, 0, 0, 0, 0, 1, 0, 0],
            [1, 0, 1, 0, 0, 1, 0, 1, 1, 1],
            [0, 0, 0, 0, 1, 0, 1, 0, 0, 1],
            [1, 0, 1, 0, 1, 0, 1, 0, 0, 0],
            [1, 0, 1, 1, 0, 0, 0, 1, 1, 1],
            [0, 0, 0, 0, 0, 0, 0, 1, 1, 0],
        ]
        flip_color(A, 5, 4)
        self.assertEqual(A, [
            [1, 0, 1, 0, 0, 0, 1, 1, 1, 1],
            [0, 0, 1, 0, 0, 1, 0, 0, 1, 1],
            [1, 1, 1, 0, 0, 1, 1, 0, 1, 1],
            [0, 1, 0, 1, 1, 1, 1, 0, 1, 0],
            [1, 1, 1, 1, 1, 1, 1, 1, 0, 0],
            [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1, 1, 0, 0, 1],
            [1, 1, 1, 1, 1, 1, 1, 0, 0, 0],
            [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1, 0],
        ])
        flip_color(A, 3, 6)
        self.assertEqual(A, [
            [1, 0, 0, 0, 0, 0, 1, 1, 1, 1],
            [0, 0, 0, 0, 0, 0, 0, 0, 1, 1],
            [0, 0, 0, 0, 0, 0, 0, 0, 1, 1],
            [0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        ])

    def test_search_maze(self):
        maze = [
            [0, 0, 1, 1, 1],
            [1, 0, 1, 1, 1],
            [1, 0, 0, 0, 1],
            [1, 1, 1, 0, 1],
            [1, 1, 1, 0, 0],
        ]
        start, end = (0, 0), (4, 4)
        path = search_maze(maze, start, end)
        self.assertIsNotNone(path)
        self.assertGreater(len(path), 0)
        self.assertEqual(path[0], start)
        self.assertEqual(path[-1], end)
        # verify each step is adjacent and passable
        for i in range(len(path)):
            r, c = path[i]
            self.assertEqual(maze[r][c], 0)
            if i > 0:
                pr, pc = path[i - 1]
                self.assertEqual(abs(r - pr) + abs(c - pc), 1)

        # no path exists
        maze2 = [
            [0, 1],
            [1, 0],
        ]
        self.assertEqual(search_maze(maze2, (0, 0), (1, 1)), [])
