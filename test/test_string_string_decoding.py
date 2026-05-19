import unittest
from test import string_decoding

class TestStringDecoding(unittest.TestCase):
    def test_string_decoding(self):
        self.assertEqual(string_decoding("4a1b3c2a"), "aaaabcccaa")
        self.assertEqual(string_decoding("3e4f2e"), "eeeffffee")
