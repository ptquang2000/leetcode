import unittest
from test import is_palindrome

class TestIsPalindrome(unittest.TestCase):
    def test_is_palindrome(self):
        self.assertTrue(is_palindrome("A man, a plan, a canal Panama."))
        self.assertTrue(is_palindrome("Able was I, ere I saw Elba!"))
        self.assertFalse(is_palindrome("Ray a Ray"))
