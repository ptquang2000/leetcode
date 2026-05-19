import unittest
from test import roman_to_integer

class TestRomanToInteger(unittest.TestCase):
    def test_roman_to_integer(self):
        self.assertEqual(roman_to_integer("XXXXXIIIIIIIII"), 59)
        self.assertEqual(roman_to_integer("LVIIII"), 59)
        self.assertEqual(roman_to_integer("LIX"), 59)
        self.assertEqual(roman_to_integer("IC"), 99)
