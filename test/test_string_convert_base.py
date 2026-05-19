import unittest
from test import convert_base

class TestConvertBase(unittest.TestCase):
    def test_convert_base(self):
        self.assertEqual(convert_base("615", 7, 13), "1A7")
        self.assertEqual(convert_base("1A7", 13, 7), "615")
        self.assertEqual(convert_base("102", 3, 4), "23")
        self.assertEqual(convert_base("23", 4, 3), "102")
