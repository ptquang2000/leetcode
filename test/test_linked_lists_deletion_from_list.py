import unittest
from common.list_node import *
from test import deletion_from_list

class TestDeletionFromList(unittest.TestCase):
    def test_deletion_from_list(self):
        node = ListNode(9)
        node = ListNode(1, node)
        del_node = ListNode(5, node)
        L = ListNode(4, del_node)
        deletion_from_list(del_node)
        self.assertEqual(del_node.data, 1)
        self.assertEqual(del_node.next.data, 9)

        node = ListNode(9)
        del_node = ListNode(1, node)
        node = ListNode(5, del_node)
        L = ListNode(4, node)
        head = deletion_from_list(del_node)
        self.assertEqual(del_node.data, 9)
        self.assertIsNone(del_node.next)
