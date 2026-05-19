import unittest
from common.list_node import *
from test import overlapping_lists

class TestOverlappingLists(unittest.TestCase):
    def test_overlapping_lists(self):
        # Note: None is cyclic
        node = ListNode(0, None)
        node = ListNode(0, node)
        A = ListNode(0, node)
        node = ListNode(0, A)
        L1 = ListNode(0, node)
        node = ListNode(0, A)
        L2 = ListNode(0, node)
        self.assertIs(overlapping_lists(L1, L2), A)

        node = ListNode(0, None)
        node = ListNode(0, node)
        L1 = ListNode(0, node)
        node = ListNode(0, None)
        node = ListNode(0, node)
        L2 = ListNode(0, node)
        self.assertIs(overlapping_lists(L1, L2), None)

        # Note: Different cyclic
        A = ListNode(0, None)
        node = ListNode(0, A)
        node = ListNode(0, node)
        A.next = node
        L1 = ListNode(0, A)
        B = ListNode(0, None)
        node = ListNode(0, B)
        node = ListNode(0, node)
        B.next = node
        L2 = ListNode(0, B)
        self.assertIs(overlapping_lists(L1, L2), None)

        # Note: Only one is cycle
        node = ListNode(0, None)
        node = ListNode(0, node)
        L1 = ListNode(0, node)
        B = ListNode(0, None)
        node = ListNode(0, B)
        node = ListNode(0, node)
        B.next = node
        L2 = ListNode(0, B)
        self.assertIs(overlapping_lists(L1, L2), None)

        # Note: Merge at nodes on cycle
        B = ListNode(0, None) 
        A = ListNode(0, B) 
        node = ListNode(0, A)
        node = ListNode(0, node)
        B.next = node
        node = ListNode(0, B)
        L1 = ListNode(0, node)
        L2 = A
        self.assertIn(overlapping_lists(L1, L2), [A, B])

        # Note: Merge before on cycle
        B = ListNode(0, None)
        node = ListNode(0, B)
        node = ListNode(0, node)
        B.next = node
        A = ListNode(0, B)
        L1 = ListNode(0, A)
        L2 = ListNode(0, A)
        self.assertIs(overlapping_lists(L1, L2), A)
