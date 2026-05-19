import unittest
from test import string_to_int

class TestStringToInt(unittest.TestCase):
    def test_string_to_int(self):
        self.assertEqual(string_to_int("123"), 123)
        self.assertEqual(string_to_int("-123"), -123)
        self.assertEqual(string_to_int("-123"), -123)
        self.assertEqual(string_to_int("314"), 314)
        self.assertEqual(string_to_int("-314"), -314)
        self.assertEqual(string_to_int("0"), 0)
        self.assertEqual(string_to_int("3"), 3)
