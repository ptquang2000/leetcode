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

    def test_is_linked_list_a_palindrome(self):
        node = ListNode(1, None)
        node = ListNode(2, node)
        node = ListNode(2, node)
        L = ListNode(1, node)
        self.assertTrue(is_linked_list_a_palindrome(L))

        node = ListNode(1, None)
        L = ListNode(2, node)
        self.assertFalse(is_linked_list_a_palindrome(L))

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

    def test_merge_two_sorted_lists(self):
        node = ListNode(4)
        node = ListNode(2, node)
        L1 = ListNode(1, node)
        node = ListNode(4)
        node = ListNode(3, node)
        L2 = ListNode(1, node)
        head = merge_two_sorted_lists(L1, L2)
        self.assertEqual(to_list(self, head, 6), [1,1,2,3,4,4])

        node = ListNode(7)
        node = ListNode(5, node)
        L1 = ListNode(2, node)
        node = ListNode(11)
        L2 = ListNode(3, node)
        head = merge_two_sorted_lists(L1, L2)
        self.assertEqual(to_list(self, head, 5), [2,3,5,7,11])

        head = merge_two_sorted_lists(None, None)
        self.assertEqual(head, None)

        L2 = ListNode(0)
        head = merge_two_sorted_lists(None, L2)
        self.assertEqual(to_list(self, head, 1), [0])

    def test_overlapping_lists(self):
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

        node = ListNode(0, None)
        node = ListNode(0, node)
        L1 = ListNode(0, node)
        B = ListNode(0, None)
        node = ListNode(0, B)
        node = ListNode(0, node)
        B.next = node
        L2 = ListNode(0, B)
        self.assertIs(overlapping_lists(L1, L2), None)

        B = ListNode(0, None)
        A = ListNode(0, B)
        node = ListNode(0, A)
        node = ListNode(0, node)
        B.next = node
        node = ListNode(0, B)
        L1 = ListNode(0, node)
        L2 = A
        self.assertIn(overlapping_lists(L1, L2), [A, B])

        B = ListNode(0, None)
        node = ListNode(0, B)
        node = ListNode(0, node)
        B.next = node
        A = ListNode(0, B)
        L1 = ListNode(0, A)
        L2 = ListNode(0, A)
        self.assertIs(overlapping_lists(L1, L2), A)

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

    def test_remove_duplicates(self):
        node = ListNode(2, None)
        node = ListNode(1, node)
        L = ListNode(1, node)
        head = remove_duplicates(L)
        self.assertEqual(to_list(self, head, 2), [1,2])

        node = ListNode(3, None)
        node = ListNode(3, node)
        node = ListNode(2, node)
        node = ListNode(1, node)
        L = ListNode(1, node)
        head = remove_duplicates(L)
        self.assertEqual(to_list(self, head, 3), [1,2,3])

        node = ListNode(11, None)
        node = ListNode(11, node)
        node = ListNode(7, node)
        node = ListNode(5, node)
        node = ListNode(3, node)
        node = ListNode(2, node)
        L = ListNode(2, node)
        head = remove_duplicates(L)
        self.assertEqual(to_list(self, head, 5), [2,3,5,7,11])

    def test_remove_kth_last(self):
        node = ListNode(5)
        node = ListNode(4, node)
        node = ListNode(3, node)
        node = ListNode(2, node)
        L = ListNode(1, node)
        head = remove_kth_last(L, 2)
        self.assertEqual(to_list(self, head, 4), [1,2,3,5])

        L = ListNode(1, None)
        head = remove_kth_last(L, 1)
        self.assertEqual(to_list(self, head, 0), [])

        node = ListNode(2, None)
        L = ListNode(1, node)
        head = remove_kth_last(L, 1)
        self.assertEqual(to_list(self, head, 1), [1])

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
