import unittest
from common.list_node import *
from test import add_two_numbers

class TestAddTwoNumbers(unittest.TestCase):
    def test_add_two_numbers(self):
        node = ListNode(4,None)
        node = ListNode(1,node)
        L1 = ListNode(3,node)
        node = ListNode(9,None)
        node = ListNode(0,node)
        L2 = ListNode(7,node)
        head = add_two_numbers(L1, L2)
        self.assertEqual(to_list(self, head, 4), [0,2,3,1])

        node = ListNode(3,None)
        node = ListNode(4,node)
        L1 = ListNode(2,node)
        node = ListNode(4,None)
        node = ListNode(6,node)
        L2 = ListNode(5,node)
        head = add_two_numbers(L1, L2)
        self.assertEqual(to_list(self, head, 3), [7,0,8])

        L1 = ListNode(0,None)
        L2 = ListNode(0,None)
        head = add_two_numbers(L1, L2)
        self.assertEqual(to_list(self, head, 1), [0])

        node = ListNode(9,None)
        node = ListNode(9,node)
        node = ListNode(9,node)
        node = ListNode(9,node)
        node = ListNode(9,node)
        node = ListNode(9,node)
        L1 = ListNode(9,node)
        node = ListNode(9,None)
        node = ListNode(9,node)
        node = ListNode(9,node)
        L2 = ListNode(9,node)
        head = add_two_numbers(L1, L2)
        self.assertEqual(to_list(self, head, 8), [8,9,9,9,0,0,0,1])
