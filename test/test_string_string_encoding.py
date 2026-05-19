import unittest
from test import string_encoding

class TestStringEncoding(unittest.TestCase):
    def test_string_encoding(self):
        self.assertEqual(string_encoding("aaaabcccaa"), "4a1b3c2a")
        self.assertEqual(string_encoding("eeeffffee"), "3e4f2e")
