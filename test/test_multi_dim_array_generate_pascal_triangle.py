import unittest
from test import generate_pascal_triangle

class TestGeneratePascalTriangle(unittest.TestCase):
    def test_generate_pascal_triangle(self):
        result = [
            [1],
            [1,1],
            [1,2,1],
            [1,3,3,1],
            [1,4,6,4,1],
        ]
        self.assertEqual(generate_pascal_triangle(5), result)
