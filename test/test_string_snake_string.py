import unittest
from test import snake_string

class TestSnakeString(unittest.TestCase):
    def test_snake_string(self):
        self.assertEqual(snake_string("Hello World!"), "e lHloWrdlo!")
