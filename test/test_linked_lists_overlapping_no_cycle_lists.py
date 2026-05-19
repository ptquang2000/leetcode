import unittest
from test import overlapping_no_cycle_lists
from common.list_node import *

class TestOverlappingNoCycleLists(unittest.TestCase):
    def test_overlapping_no_cycle_lists(self):
        node = ListNode(5)
        node = ListNode(4, node)
        L3 = ListNode(8, node)
        node = ListNode(1, L3)
        L1 = ListNode(4, node)
        node = ListNode(1, L3)
        node = ListNode(6, node)
        L2 = ListNode(5, node)
        result = overlapping_no_cycle_lists(L1, L2)
        self.assertIs(result, L3)

        node = ListNode(4)
        L3 = ListNode(2, node)
        node = ListNode(1, L3)
        node = ListNode(9, node)
        L1 = ListNode(1, node)
        L2 = ListNode(3, L3)
        result = overlapping_no_cycle_lists(L1, L2)
        self.assertIs(result, L3)

        node = ListNode(4)
        node = ListNode(6)
        L1 = ListNode(2, node)
        node = ListNode(5)
        L2 = ListNode(1, node)
        result = overlapping_no_cycle_lists(L1, L2)
        self.assertIsNone(result)
