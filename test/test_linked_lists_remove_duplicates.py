import unittest
from common.list_node import *
from test import remove_duplicates

class TestRemoveDuplicates(unittest.TestCase):
    def test_remove_duplicates(self):
        node = ListNode(2, None)
        node = ListNode(1, node)
        L = ListNode(1, node)
        head = remove_duplicates(L)
        self.assertEqual(to_list(self, head, 2), [1,2])

        node = ListNode(3, None)
        node = ListNode(3, node)
        node = ListNode(2, node)
        node = ListNode(1, node)
        L = ListNode(1, node)
        head = remove_duplicates(L)
        self.assertEqual(to_list(self, head, 3), [1,2,3])

        node = ListNode(11, None)
        node = ListNode(11, node)
        node = ListNode(7, node)
        node = ListNode(5, node)
        node = ListNode(3, node)
        node = ListNode(2, node)
        L = ListNode(2, node)
        head = remove_duplicates(L)
        self.assertEqual(to_list(self, head, 5), [2,3,5,7,11])
