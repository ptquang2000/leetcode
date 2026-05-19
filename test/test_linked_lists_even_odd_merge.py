import unittest
from common.list_node import *
from test import even_odd_merge

class TestEvenOddMerge(unittest.TestCase):
    def test_even_odd_merge(self):
        node = ListNode(5, None)
        node = ListNode(4, node)
        node = ListNode(3, node)
        node = ListNode(2, node)
        L = ListNode(1, node)
        head = even_odd_merge(L)
        self.assertEqual(to_list(self, head, 5), [1,3,5,2,4])
        
        node = ListNode(7, None)
        node = ListNode(4, node)
        node = ListNode(6, node)
        node = ListNode(5, node)
        node = ListNode(3, node)
        node = ListNode(1, node)
        L = ListNode(2, node)
        head = even_odd_merge(L)
        self.assertEqual(to_list(self, head, 7), [2,3,6,7,1,5,4])

        head = even_odd_merge(None)
        self.assertIsNone(head)

