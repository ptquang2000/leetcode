import unittest
from common.list_node import *
from test import cyclically_right_shift_list

class TestCyclicallyRightShiftList(unittest.TestCase):
    def test_cyclically_right_shift_list(self):
        node = ListNode(5, None)
        node = ListNode(4, node)
        node = ListNode(3, node)
        node = ListNode(2, node)
        L = ListNode(1, node)
        head = cyclically_right_shift_list(L, 2)
        self.assertEqual(to_list(self, head, 5), [4,5,1,2,3])

        node = ListNode(5, None)
        node = ListNode(4, node)
        node = ListNode(3, node)
        node = ListNode(2, node)
        L = ListNode(1, node)
        head = cyclically_right_shift_list(L, 12)
        self.assertEqual(to_list(self, head, 5), [4,5,1,2,3])

        node = ListNode(2, None)
        node = ListNode(1, node)
        L = ListNode(0, node)
        head = cyclically_right_shift_list(L, 4)
        self.assertEqual(to_list(self, head, 3), [2,0,1])

        head = cyclically_right_shift_list(None, 4)
        self.assertIsNone(head)
