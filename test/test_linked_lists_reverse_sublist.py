import unittest
from test import reverse_sublist
from common.list_node import *

class TestReverseSublist(unittest.TestCase):
    def test_reverse_sublist(self):
        node = ListNode(5)
        node = ListNode(4, node)
        node = ListNode(3, node)
        node = ListNode(2, node)
        L = ListNode(1, node)
        head = reverse_sublist(L, 2, 4)
        self.assertEqual(to_list(self, head, 5), [1,4,3,2,5])

        node = ListNode(2)
        node = ListNode(7, node)
        node = ListNode(5, node)
        node = ListNode(3, node)
        L = ListNode(11, node)
        head = reverse_sublist(L, 2, 4)
        self.assertEqual(to_list(self, head, 5), [11,7,5,3,2])

        L = ListNode(5, None)
        head = reverse_sublist(L, 1, 1)
        self.assertEqual(to_list(self, head, 1), [5])
