import unittest
from test import has_cycle
from common.list_node import *

class TestHasCycle(unittest.TestCase):
    def test_has_cycle(self):
        end = ListNode(-4, None)
        node = ListNode(0, end)
        expected = ListNode(2, node)
        L = ListNode(3, expected)
        end.next = expected
        result = has_cycle(L)
        self.assertIs(result, expected)

        end = ListNode(2, None)
        expected = ListNode(1, end)
        L = expected
        end.next = expected
        result = has_cycle(L)
        self.assertIs(result, expected)

        end = ListNode(2, None)
        self.assertIsNone(has_cycle(end))
