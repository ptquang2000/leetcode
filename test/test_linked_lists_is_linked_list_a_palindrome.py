import unittest
from common.list_node import *
from test import is_linked_list_a_palindrome

class TestIsLinkedListAPalindrome(unittest.TestCase):
    def test_is_linked_list_a_palindrome(self):
        node = ListNode(1, None)
        node = ListNode(2, node)
        node = ListNode(2, node)
        L = ListNode(1, node)
        self.assertTrue(is_linked_list_a_palindrome(L))

        node = ListNode(1, None)
        L = ListNode(2, node)
        self.assertFalse(is_linked_list_a_palindrome(L))
