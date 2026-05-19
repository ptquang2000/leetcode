import unittest
from test import solve

def draw_path(data, path):
    data2 = [[c for c in line] for line in data]
    for p in path:
        if data2[p['y']] and data2[p['y']][p['x']]:
            data2[p['y']][p['x']] = '*'
    return [''.join(d) for d in data2]

class TestMazeSolver(unittest.TestCase):
    def test_solve(self):
        maze = [
            "xxxxxxxxxx x",
            "x        x x",
            "x        x x",
            "x xxxxxxxx x",
            "x          x",
            "x xxxxxxxxxx",
        ]

        maze_result = [
            { 'x': 10, 'y': 0 },
            { 'x': 10, 'y': 1 },
            { 'x': 10, 'y': 2 },
            { 'x': 10, 'y': 3 },
            { 'x': 10, 'y': 4 },
            { 'x': 9, 'y': 4 },
            { 'x': 8, 'y': 4 },
            { 'x': 7, 'y': 4 },
            { 'x': 6, 'y': 4 },
            { 'x': 5, 'y': 4 },
            { 'x': 4, 'y': 4 },
            { 'x': 3, 'y': 4 },
            { 'x': 2, 'y': 4 },
            { 'x': 1, 'y': 4 },
            { 'x': 1, 'y': 5 },
        ]


        result = solve(maze, 'x', { 'x': 10, 'y': 0 }, { 'x': 1, 'y': 5 })
        self.assertEqual(draw_path(maze, result), draw_path(maze, maze_result))
