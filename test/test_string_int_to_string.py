import unittest
from test import int_to_string

class TestIntToString(unittest.TestCase):
    def test_int_to_string(self):
        self.assertEqual(int_to_string(123), "123")
        self.assertEqual(int_to_string(-123), "-123")
        self.assertEqual(int_to_string(314), "314")
        self.assertEqual(int_to_string(-314), "-314")
        self.assertEqual(int_to_string(0), "0")
        self.assertEqual(int_to_string(3), "3")
