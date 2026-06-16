import unittest
from common.list_node import *
from test import (
    add_two_numbers,
    cyclically_right_shift_list,
    deletion_from_list,
    even_odd_merge,
    has_cycle,
    is_linked_list_a_palindrome,
    list_pivoting,
    merge_two_sorted_lists,
    overlapping_lists,
    overlapping_no_cycle_lists,
    remove_duplicates,
    remove_kth_last,
    reverse_sublist,
)


class TestLinkedLists(unittest.TestCase):
    def test_add_two_numbers(self):
        node = ListNode(None, 4)
        node = ListNode(node, 1)
        L1 = ListNode(node, 3)
        node = ListNode(None, 9)
        node = ListNode(node, 0)
        L2 = ListNode(node, 7)
        head = add_two_numbers(L1, L2)
        self.assertEqual(to_list(self, head, 4), [0,2,3,1])

        node = ListNode(None, 3)
        node = ListNode(node, 4)
        L1 = ListNode(node, 2)
        node = ListNode(None, 4)
        node = ListNode(node, 6)
        L2 = ListNode(node, 5)
        head = add_two_numbers(L1, L2)
        self.assertEqual(to_list(self, head, 3), [7,0,8])

        L1 = ListNode(None, 0)
        L2 = ListNode(None, 0)
        head = add_two_numbers(L1, L2)
        self.assertEqual(to_list(self, head, 1), [0])

        node = ListNode(None, 9)
        node = ListNode(node, 9)
        node = ListNode(node, 9)
        node = ListNode(node, 9)
        node = ListNode(node, 9)
        node = ListNode(node, 9)
        L1 = ListNode(node, 9)
        node = ListNode(None, 9)
        node = ListNode(node, 9)
        node = ListNode(node, 9)
        L2 = ListNode(node, 9)
        head = add_two_numbers(L1, L2)
        self.assertEqual(to_list(self, head, 8), [8,9,9,9,0,0,0,1])

    def test_cyclically_right_shift_list(self):
        node = ListNode(None, 5)
        node = ListNode(node, 4)
        node = ListNode(node, 3)
        node = ListNode(node, 2)
        L = ListNode(node, 1)
        head = cyclically_right_shift_list(L, 2)
        self.assertEqual(to_list(self, head, 5), [4,5,1,2,3])

        node = ListNode(None, 5)
        node = ListNode(node, 4)
        node = ListNode(node, 3)
        node = ListNode(node, 2)
        L = ListNode(node, 1)
        head = cyclically_right_shift_list(L, 12)
        self.assertEqual(to_list(self, head, 5), [4,5,1,2,3])

        node = ListNode(None, 2)
        node = ListNode(node, 1)
        L = ListNode(node, 0)
        head = cyclically_right_shift_list(L, 4)
        self.assertEqual(to_list(self, head, 3), [2,0,1])

        head = cyclically_right_shift_list(None, 4)
        self.assertIsNone(head)

    def test_deletion_from_list(self):
        node = ListNode(data=9)
        node = ListNode(node, 1)
        del_node = ListNode(node, 5)
        L = ListNode(del_node, 4)
        deletion_from_list(del_node)
        self.assertEqual(del_node.data, 1)
        self.assertEqual(del_node.next.data, 9)

        node = ListNode(data=9)
        del_node = ListNode(node, 1)
        node = ListNode(del_node, 5)
        L = ListNode(node, 4)
        head = deletion_from_list(del_node)
        self.assertEqual(del_node.data, 9)
        self.assertIsNone(del_node.next)

    def test_even_odd_merge(self):
        node = ListNode(None, 5)
        node = ListNode(node, 4)
        node = ListNode(node, 3)
        node = ListNode(node, 2)
        L = ListNode(node, 1)
        head = even_odd_merge(L)
        self.assertEqual(to_list(self, head, 5), [1,3,5,2,4])

        node = ListNode(None, 7)
        node = ListNode(node, 4)
        node = ListNode(node, 6)
        node = ListNode(node, 5)
        node = ListNode(node, 3)
        node = ListNode(node, 1)
        L = ListNode(node, 2)
        head = even_odd_merge(L)
        self.assertEqual(to_list(self, head, 7), [2,3,6,7,1,5,4])

        head = even_odd_merge(None)
        self.assertIsNone(head)

    def test_has_cycle(self):
        end = ListNode(None, -4)
        node = ListNode(end, 0)
        expected = ListNode(node, 2)
        L = ListNode(expected, 3)
        end.next = expected
        result = has_cycle(L)
        self.assertIs(result, expected)

        end = ListNode(None, 2)
        expected = ListNode(end, 1)
        L = expected
        end.next = expected
        result = has_cycle(L)
        self.assertIs(result, expected)

        end = ListNode(None, 2)
        self.assertIsNone(has_cycle(end))

    def test_is_linked_list_a_palindrome(self):
        node = ListNode(None, 1)
        node = ListNode(node, 2)
        node = ListNode(node, 2)
        L = ListNode(node, 1)
        self.assertTrue(is_linked_list_a_palindrome(L))

        node = ListNode(None, 1)
        L = ListNode(node, 2)
        self.assertFalse(is_linked_list_a_palindrome(L))

    def test_list_pivoting(self):
        node = ListNode(None, 11)
        node = ListNode(node, 5)
        node = ListNode(node, 7)
        node = ListNode(node, 11)
        node = ListNode(node, 2)
        node = ListNode(node, 2)
        L = ListNode(node, 3)
        head = list_pivoting(L, 7)
        self.assertEqual(to_list(self, head, 7), [3,2,2,5,7,11,11])

        node = ListNode(None, 2)
        node = ListNode(node, 5)
        node = ListNode(node, 2)
        node = ListNode(node, 3)
        node = ListNode(node, 4)
        L = ListNode(node, 1)
        head = list_pivoting(L, 3)
        self.assertEqual(to_list(self, head, 6), [1,2,2,3,4,5])

        node = ListNode(None, 1)
        L = ListNode(node, 2)
        head = list_pivoting(L, 2)
        self.assertEqual(to_list(self, head, 2), [1,2])

    def test_merge_two_sorted_lists(self):
        node = ListNode(data=4)
        node = ListNode(node, 2)
        L1 = ListNode(node, 1)
        node = ListNode(data=4)
        node = ListNode(node, 3)
        L2 = ListNode(node, 1)
        head = merge_two_sorted_lists(L1, L2)
        self.assertEqual(to_list(self, head, 6), [1,1,2,3,4,4])

        node = ListNode(data=7)
        node = ListNode(node, 5)
        L1 = ListNode(node, 2)
        node = ListNode(data=11)
        L2 = ListNode(node, 3)
        head = merge_two_sorted_lists(L1, L2)
        self.assertEqual(to_list(self, head, 5), [2,3,5,7,11])

        head = merge_two_sorted_lists(None, None)
        self.assertEqual(head, None)

        L2 = ListNode(data=0)
        head = merge_two_sorted_lists(None, L2)
        self.assertEqual(to_list(self, head, 1), [0])

    def test_overlapping_lists(self):
        node = ListNode(None, 0)
        node = ListNode(node, 0)
        A = ListNode(node, 0)
        node = ListNode(A, 0)
        L1 = ListNode(node, 0)
        node = ListNode(A, 0)
        L2 = ListNode(node, 0)
        self.assertIs(overlapping_lists(L1, L2), A)

        node = ListNode(None, 0)
        node = ListNode(node, 0)
        L1 = ListNode(node, 0)
        node = ListNode(None, 0)
        node = ListNode(node, 0)
        L2 = ListNode(node, 0)
        self.assertIs(overlapping_lists(L1, L2), None)

        A = ListNode(None, 0)
        node = ListNode(A, 0)
        node = ListNode(node, 0)
        A.next = node
        L1 = ListNode(A, 0)
        B = ListNode(None, 0)
        node = ListNode(B, 0)
        node = ListNode(node, 0)
        B.next = node
        L2 = ListNode(B, 0)
        self.assertIs(overlapping_lists(L1, L2), None)

        node = ListNode(None, 0)
        node = ListNode(node, 0)
        L1 = ListNode(node, 0)
        B = ListNode(None, 0)
        node = ListNode(B, 0)
        node = ListNode(node, 0)
        B.next = node
        L2 = ListNode(B, 0)
        self.assertIs(overlapping_lists(L1, L2), None)

        B = ListNode(None, 0)
        A = ListNode(B, 0)
        node = ListNode(A, 0)
        node = ListNode(node, 0)
        B.next = node
        node = ListNode(B, 0)
        L1 = ListNode(node, 0)
        L2 = A
        self.assertIn(overlapping_lists(L1, L2), [A, B])

        B = ListNode(None, 0)
        node = ListNode(B, 0)
        node = ListNode(node, 0)
        B.next = node
        A = ListNode(B, 0)
        L1 = ListNode(A, 0)
        L2 = ListNode(A, 0)
        self.assertIs(overlapping_lists(L1, L2), A)

    def test_overlapping_no_cycle_lists(self):
        node = ListNode(data=5)
        node = ListNode(node, 4)
        L3 = ListNode(node, 8)
        node = ListNode(L3, 1)
        L1 = ListNode(node, 4)
        node = ListNode(L3, 1)
        node = ListNode(node, 6)
        L2 = ListNode(node, 5)
        result = overlapping_no_cycle_lists(L1, L2)
        self.assertIs(result, L3)

        node = ListNode(data=4)
        L3 = ListNode(node, 2)
        node = ListNode(L3, 1)
        node = ListNode(node, 9)
        L1 = ListNode(node, 1)
        L2 = ListNode(L3, 3)
        result = overlapping_no_cycle_lists(L1, L2)
        self.assertIs(result, L3)

        node = ListNode(data=4)
        node = ListNode(data=6)
        L1 = ListNode(node, 2)
        node = ListNode(data=5)
        L2 = ListNode(node, 1)
        result = overlapping_no_cycle_lists(L1, L2)
        self.assertIsNone(result)

    def test_remove_duplicates(self):
        node = ListNode(None, 2)
        node = ListNode(node, 1)
        L = ListNode(node, 1)
        head = remove_duplicates(L)
        self.assertEqual(to_list(self, head, 2), [1,2])

        node = ListNode(None, 3)
        node = ListNode(node, 3)
        node = ListNode(node, 2)
        node = ListNode(node, 1)
        L = ListNode(node, 1)
        head = remove_duplicates(L)
        self.assertEqual(to_list(self, head, 3), [1,2,3])

        node = ListNode(None, 11)
        node = ListNode(node, 11)
        node = ListNode(node, 7)
        node = ListNode(node, 5)
        node = ListNode(node, 3)
        node = ListNode(node, 2)
        L = ListNode(node, 2)
        head = remove_duplicates(L)
        self.assertEqual(to_list(self, head, 5), [2,3,5,7,11])

    def test_remove_kth_last(self):
        node = ListNode(data=5)
        node = ListNode(node, 4)
        node = ListNode(node, 3)
        node = ListNode(node, 2)
        L = ListNode(node, 1)
        head = remove_kth_last(L, 2)
        self.assertEqual(to_list(self, head, 4), [1,2,3,5])

        L = ListNode(None, 1)
        head = remove_kth_last(L, 1)
        self.assertEqual(to_list(self, head, 0), [])

        node = ListNode(None, 2)
        L = ListNode(node, 1)
        head = remove_kth_last(L, 1)
        self.assertEqual(to_list(self, head, 1), [1])

    def test_reverse_sublist(self):
        node = ListNode(data=5)
        node = ListNode(node, 4)
        node = ListNode(node, 3)
        node = ListNode(node, 2)
        L = ListNode(node, 1)
        head = reverse_sublist(L, 2, 4)
        self.assertEqual(to_list(self, head, 5), [1,4,3,2,5])

        node = ListNode(data=2)
        node = ListNode(node, 7)
        node = ListNode(node, 5)
        node = ListNode(node, 3)
        L = ListNode(node, 11)
        head = reverse_sublist(L, 2, 4)
        self.assertEqual(to_list(self, head, 5), [11,7,5,3,2])

        node = ListNode(None, 5)
        node = ListNode(node, 4)
        node = ListNode(node, 3)
        node = ListNode(node, 2)
        L = ListNode(node, 1)
        head = reverse_sublist(L, 2, 3)
        self.assertEqual(to_list(self, head, 5), [1,3,2,4,5])

        node = ListNode(None, 5)
        node = ListNode(node, 4)
        node = ListNode(node, 3)
        node = ListNode(node, 2)
        L = ListNode(node, 1)
        head = reverse_sublist(L, 3, 5)
        self.assertEqual(to_list(self, head, 5), [1,2,5,4,3])

        node = ListNode(None, 5)
        node = ListNode(node, 4)
        node = ListNode(node, 3)
        node = ListNode(node, 2)
        L = ListNode(node, 1)
        head = reverse_sublist(L, 4, 4)
        self.assertEqual(to_list(self, head, 5), [1,2,3,4,5])

        head = reverse_sublist(None, 1, 1)
        self.assertIsNone(head)

        L = ListNode(None, 5)
        head = reverse_sublist(L, 1, 1)
        self.assertEqual(to_list(self, head, 1), [5])
