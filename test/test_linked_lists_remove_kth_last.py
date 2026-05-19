import unittest
from common.list_node import *
from test import remove_kth_last

class TestRemoveKthLast(unittest.TestCase):
    def test_remove_kth_last(self):
        node = ListNode(5)
        node = ListNode(4, node)
        node = ListNode(3, node)
        node = ListNode(2, node)
        L = ListNode(1, node)
        head = remove_kth_last(L, 2)
        self.assertEqual(to_list(self, head, 4), [1,2,3,5])

        L = ListNode(1, None)
        head = remove_kth_last(L, 1)
        self.assertEqual(to_list(self, head, 0), [])

        node = ListNode(2, None)
        L = ListNode(1, node)
        head = remove_kth_last(L, 1)
        self.assertEqual(to_list(self, head, 1), [1])
        
