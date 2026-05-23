import unittest
from test import (
    find_closest_k_stars,
    k_largest_in_binary_heap,
    merge_sorted_arrays,
    online_median,
    sort_approximately_sorted_array,
    sort_k_increasing_decreasing_array,
)


class TestHeap(unittest.TestCase):
    def test_merge_sorted_arrays(self):
        self.assertEqual(
            merge_sorted_arrays([[3, 5, 7], [0, 6], [0, 6, 28]]),
            [0, 0, 3, 5, 6, 6, 7, 28],
        )
        self.assertEqual(
            merge_sorted_arrays([[1, 4, 5], [1, 3, 4], [2, 6]]),
            [1, 1, 2, 3, 4, 4, 5, 6],
        )
        self.assertEqual(merge_sorted_arrays([]), [])
        self.assertEqual(merge_sorted_arrays([[1, 2, 3]]), [1, 2, 3])
        self.assertEqual(merge_sorted_arrays([[1], [2], [3]]), [1, 2, 3])
        self.assertEqual(merge_sorted_arrays([[5], [5]]), [5, 5])

    def test_sort_k_increasing_decreasing_array(self):
        A = [57, 131, 493, 294, 221, 339, 418, 452, 442, 190]
        sort_k_increasing_decreasing_array(A)
        self.assertEqual(A, [57, 131, 190, 221, 294, 339, 418, 442, 452, 493])

        A = [1, 2, 3, 4, 3, 2, 1]
        sort_k_increasing_decreasing_array(A)
        self.assertEqual(A, [1, 1, 2, 2, 3, 3, 4])

    def test_find_closest_k_stars(self):
        self.assertEqual(find_closest_k_stars([[1, 3], [-2, 2]], 1), [[-2, 2]])
        self.assertEqual(find_closest_k_stars([[3, 3], [5, -1], [-2, 4]], 2), [[-2, 4], [3, 3]])
        self.assertEqual(
            find_closest_k_stars([[1, 3], [-2, 2], [5, -1], [3, 2], [1, 1]], 3),
            [[1, 3], [-2, 2], [1, 1]],
        )
        self.assertEqual(find_closest_k_stars([[2, 4], [-1, -1], [0, 0]], 1), [[0, 0]])

    def test_sort_approximately_sorted_array(self):
        seq = [6, 5, 3, 2, 8, 10, 9]
        sort_approximately_sorted_array(seq, 3)
        self.assertEqual(seq, [2, 3, 5, 6, 8, 9, 10])

        seq = [1, 4, 5, 2, 3, 6, 7, 8, 9, 10]
        sort_approximately_sorted_array(seq, 2)
        self.assertEqual(seq, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])

        seq = [5]
        sort_approximately_sorted_array(seq, 0)
        self.assertEqual(seq, [5])

        seq = [1, 2, 3, 4]
        sort_approximately_sorted_array(seq, 1)
        self.assertEqual(seq, [1, 2, 3, 4])

    def test_online_median(self):
        self.assertEqual(online_median([1, 0, 3, 5, 2, 0, 1]), [1, 0.5, 1, 2, 2, 1.5, 1])
        self.assertEqual(online_median([5]), [5.0])
        self.assertEqual(online_median([3, 1]), [3.0, 2.0])
        self.assertEqual(online_median([2, 3]), [2.0, 2.5])
        self.assertEqual(online_median([1, 2, 3, 4, 5]), [1, 1.5, 2, 2.5, 3])

    def test_k_largest_in_binary_heap(self):
        self.assertEqual(k_largest_in_binary_heap([50, 23, 30, 1, 9, 2, 12], 3), [50, 30, 23])
        self.assertEqual(k_largest_in_binary_heap([44, 12, 17, 5, 9, 11, 2], 2), [44, 17])
        self.assertEqual(
            k_largest_in_binary_heap([561, 314, 401, 28, 156, 359, 271, 11, 3], 4),
            [561, 401, 359, 314],
        )
