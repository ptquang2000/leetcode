import unittest
from common.list_node import *
from test import list_pivoting

class TestListPivoting(unittest.TestCase):
    def test_list_pivoting(self):
        node = ListNode(11, None)
        node = ListNode(5, node)
        node = ListNode(7, node)
        node = ListNode(11, node)
        node = ListNode(2, node)
        node = ListNode(2, node)
        L = ListNode(3, node)
        head = list_pivoting(L, 7)
        self.assertEqual(to_list(self, head, 7), [3,2,2,5,7,11,11])

        node = ListNode(2, None)
        node = ListNode(5, node)
        node = ListNode(2, node)
        node = ListNode(3, node)
        node = ListNode(4, node)
        L = ListNode(1, node)
        head = list_pivoting(L, 3)
        self.assertEqual(to_list(self, head, 6), [1,2,2,3,4,5])

        node = ListNode(1, None)
        L = ListNode(2, node)
        head = list_pivoting(L, 2)
        self.assertEqual(to_list(self, head, 2), [1,2])
