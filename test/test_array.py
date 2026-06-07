import unittest
from test import (
    apply_permutation,
    buy_and_sell_stock_once,
    buy_and_sell_stock_twice,
    can_reach_end,
    delete_duplicates,
    dutch_flag_partition,
    generate_primes,
    merge,
    multiply,
    next_permutation,
    plus_one,
    remove_element,
)


class TestArray(unittest.TestCase):
    def test_apply_permutation(self):
        A = ['a','b','c','d']
        apply_permutation([3,2,1,0], A)
        self.assertEqual(A, ['d','c','b','a'])
        A = ['a','b','c','d']
        apply_permutation([2,0,1,3], A)
        self.assertEqual(A, ['b','c','a','d'])
        A = ['a','b','c','d']
        apply_permutation([0,1,2,3], A)
        self.assertEqual(A, ['a','b','c','d'])
        A = ['x']
        apply_permutation([0], A)
        self.assertEqual(A, ['x'])
        A = ['p','q']
        apply_permutation([1,0], A)
        self.assertEqual(A, ['q','p'])
        A = ['a','b']
        apply_permutation([0,1], A)
        self.assertEqual(A, ['a','b'])

    def test_buy_and_sell_stock_once(self):
        A = [310,315,275,295,260,270,290,230,255,250]
        self.assertEqual(buy_and_sell_stock_once(A), 30)
        self.assertEqual(buy_and_sell_stock_once([5,4,3,2,1]), 0)
        self.assertEqual(buy_and_sell_stock_once([1,2]), 1)
        self.assertEqual(buy_and_sell_stock_once([1,1,1,1]), 0)
        self.assertEqual(buy_and_sell_stock_once([2,1,4]), 3)
        self.assertEqual(buy_and_sell_stock_once([1]), 0)
        self.assertEqual(buy_and_sell_stock_once([7,1,5,3,6,4]), 5)
        self.assertEqual(buy_and_sell_stock_once([7,6,4,3,1]), 0)
        self.assertEqual(buy_and_sell_stock_once([1,2,3,4,5]), 4)
        self.assertEqual(buy_and_sell_stock_once([5,4,3,2,1,6]), 5)

    def test_buy_and_sell_stock_twice(self):
        A = [12,11,13,9,12,8,14,13,15]
        self.assertEqual(buy_and_sell_stock_twice(A), 10)
        self.assertEqual(buy_and_sell_stock_twice([3,3,5,0,0,3,1,4]), 6)
        self.assertEqual(buy_and_sell_stock_twice([1,2,3,4,5]), 4)
        self.assertEqual(buy_and_sell_stock_twice([7,6,4,3,1]), 0)
        self.assertEqual(buy_and_sell_stock_twice([1,2,4,2,5,7,2,4,9,0]), 13)
        self.assertEqual(buy_and_sell_stock_twice([1]), 0)
        self.assertEqual(buy_and_sell_stock_twice([1,2]), 1)
        self.assertEqual(buy_and_sell_stock_twice([2,1]), 0)
        self.assertEqual(buy_and_sell_stock_twice([1,5,2,4]), 6)
        self.assertEqual(buy_and_sell_stock_twice([1,3,1,3]), 4)

    def test_can_reach_end(self):
        self.assertTrue(can_reach_end([2,4,1,1,0,2,3]))
        self.assertTrue(can_reach_end([3,3,7,0,2,0,1]))
        self.assertFalse(can_reach_end([3,2,0,0,2,0,7]))
        self.assertTrue(can_reach_end([]))
        self.assertTrue(can_reach_end([0]))
        self.assertTrue(can_reach_end([1]))
        self.assertTrue(can_reach_end([1,0]))
        self.assertFalse(can_reach_end([0,1]))
        self.assertTrue(can_reach_end([3,0,0,0]))
        self.assertTrue(can_reach_end([2,0,0]))
        self.assertTrue(can_reach_end([2,3,0,0]))
        self.assertFalse(can_reach_end([0,0,0]))
        self.assertTrue(can_reach_end([5,0,0,0,0,0]))

    def test_delete_duplicates(self):
        A = [2,3,5,5,7,11,11,11,13]
        self.assertEqual(delete_duplicates(A), 6)
        self.assertEqual(A[:6], [2,3,5,7,11,13])
        A = []
        self.assertEqual(delete_duplicates(A), 0)
        A = [5]
        self.assertEqual(delete_duplicates(A), 1)
        A = [1,2,3,4,5]
        self.assertEqual(delete_duplicates(A), 5)
        self.assertEqual(A[:5], [1,2,3,4,5])
        A = [1,1,1,1,1]
        self.assertEqual(delete_duplicates(A), 1)
        self.assertEqual(A[:1], [1])
        A = [0,0,1,1,2,2,3,3]
        self.assertEqual(delete_duplicates(A), 4)
        self.assertEqual(A[:4], [0,1,2,3])
        A = [1,1,2,2,3,3]
        self.assertEqual(delete_duplicates(A), 3)
        self.assertEqual(A[:3], [1,2,3])

    def _dutch_inner(self, pivot_idx, A):
        pivot = A[pivot_idx]
        dutch_flag_partition(pivot_idx, A)
        first = A.index(pivot)
        A.reverse()
        last = len(A) - 1 - A.index(pivot)
        A.reverse()
        self.assertEqual([i < pivot for i in A[0:first]], [True for _ in A[0:first]],
                         f"Elements before pivot should be < {pivot}, got {A[0:first]}")
        self.assertEqual([i == pivot for i in A[first:last + 1]], [True for _ in A[first:last + 1]],
                         f"Elements from {first} to {last} should be == {pivot}, got {A[first:last + 1]}")
        self.assertEqual([i > pivot for i in A[last + 1:]], [True for _ in A[last + 1:]],
                         f"Elements after index {last} should be > {pivot}, got {A[last + 1:]}")

    def test_dutch_flag_partition(self):
        A = [0,1,2,0,2,1,1]
        self._dutch_inner(3, A[:])
        self._dutch_inner(2, A[:])
        self._dutch_inner(0, [2,2,2][:])
        self._dutch_inner(0, [0,0,1,1,2,2][:])
        self._dutch_inner(2, [0,0,1,1,2,2][:])
        self._dutch_inner(0, [5][:])
        self._dutch_inner(1, [3,1,4,1,5,9,2,6][:])
        self._dutch_inner(4, [3,1,4,1,5,9,2,6][:])
        self._dutch_inner(0, [1,0,2][:])
        self._dutch_inner(1, [1,0,2][:])
        self._dutch_inner(2, [1,0,2][:])
        self._dutch_inner(0, [3,3,3,3][:])
        self._dutch_inner(0, [0,0,0][:])
        self._dutch_inner(0, [7,3,5,3,7,5][:])
        self._dutch_inner(1, [2,2,1,1][:])
        self._dutch_inner(0, [1,2,0,2,0][:])
        self._dutch_inner(2, [5,4,3,2,1][:])

    def test_generate_primes(self):
        self.assertEqual(generate_primes(18), [2,3,5,7,11,13,17])
        self.assertEqual(generate_primes(1), [])
        self.assertEqual(generate_primes(2), [2])
        self.assertEqual(generate_primes(10), [2,3,5,7])
        self.assertEqual(generate_primes(30), [2,3,5,7,11,13,17,19,23,29])
        self.assertEqual(generate_primes(0), [])
        self.assertEqual(generate_primes(3), [2,3])
        self.assertEqual(generate_primes(50), [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47])
        self.assertEqual(generate_primes(100), [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97])

    def test_multiply(self):
        num1 = [1,9,3,7,0,7,7,2,1]
        num2 = [-7,6,1.,8,3,8,2,5,7,2,8,7]
        self.assertEqual(multiply(num1, num2), [-1,4,7,5,7,3,9,5,2,5,8,9,6,7,6,4,1,2,9,2,7])
        self.assertEqual(multiply([1,2], [3]), [3,6])
        self.assertEqual(multiply([-1,2], [3]), [-3,6])
        self.assertEqual(multiply([0], [9,9,9]), [0])
        self.assertEqual(multiply([9,9], [9,9]), [9,8,0,1])
        self.assertEqual(multiply([0], [0]), [0])
        self.assertEqual(multiply([1], [1]), [1])
        self.assertEqual(multiply([1], [9]), [9])
        self.assertEqual(multiply([9], [1]), [9])
        self.assertEqual(multiply([2,3], [4]), [9,2])
        self.assertEqual(multiply([5], [5]), [2,5])
        self.assertEqual(multiply([-1,2], [-3]), [3,6])
        self.assertEqual(multiply([-9], [9]), [-8,1])
        self.assertEqual(multiply([1,0,0], [1,0]), [1,0,0,0])

    def test_next_permutation(self):
        self.assertEqual(next_permutation([1,0,3,2]), [1,2,0,3])
        self.assertEqual(next_permutation([3,2,1,0]), [])
        self.assertEqual(next_permutation([6,2,1,5,4,3,0]), [6,2,3,0,1,4,5])
        self.assertEqual(next_permutation([1,2]), [2,1])
        self.assertEqual(next_permutation([2,1]), [])
        self.assertEqual(next_permutation([1,1,1]), [])
        self.assertEqual(next_permutation([1]), [])
        self.assertEqual(next_permutation([1,3,2]), [2,1,3])
        self.assertEqual(next_permutation([1,2,3]), [1,3,2])
        self.assertEqual(next_permutation([1,1,5,1]), [1,5,1,1])
        self.assertEqual(next_permutation([2,3,1]), [3,1,2])
        self.assertEqual(next_permutation([1,2,3,4]), [1,2,4,3])

    def test_plus_one(self):
        self.assertEqual(plus_one([1,2,9]), [1,3,0])
        self.assertEqual(plus_one([9,9,9]), [1,0,0,0])
        self.assertEqual(plus_one([0]), [1])
        self.assertEqual(plus_one([9]), [1,0])
        self.assertEqual(plus_one([1,9,9]), [2,0,0])
        self.assertEqual(plus_one([8,9,9,9]), [9,0,0,0])
        self.assertEqual(plus_one([1,0,0]), [1,0,1])
        self.assertEqual(plus_one([9,0,9]), [9,1,0])
        self.assertEqual(plus_one([1,2,3]), [1,2,4])

    def test_merge(self):
        nums1 = [1, 2, 3, 0, 0, 0]
        merge(nums1, 3, [2, 5, 6], 3)
        self.assertEqual(nums1, [1, 2, 2, 3, 5, 6])

        nums1 = [1]
        merge(nums1, 1, [], 0)
        self.assertEqual(nums1, [1])

        nums1 = [0]
        merge(nums1, 0, [1], 1)
        self.assertEqual(nums1, [1])
        nums1 = [4, 5, 6, 0, 0, 0]
        merge(nums1, 3, [1, 2, 3], 3)
        self.assertEqual(nums1, [1, 2, 3, 4, 5, 6])
        nums1 = [0, 0, 0]
        merge(nums1, 0, [1, 2, 3], 3)
        self.assertEqual(nums1, [1, 2, 3])
        nums1 = [1, 2, 3]
        merge(nums1, 3, [], 0)
        self.assertEqual(nums1, [1, 2, 3])

    def test_remove_element(self):
        nums = [3, 2, 2, 3]
        k = remove_element(nums, 3)
        self.assertEqual(k, 2)
        self.assertEqual(nums[:k], [2, 2])

        nums = [0, 1, 2, 2, 3, 0, 4, 2]
        k = remove_element(nums, 2)
        self.assertEqual(k, 5)
        self.assertEqual(sorted(nums[:k]), [0, 0, 1, 3, 4])
        nums = []
        k = remove_element(nums, 0)
        self.assertEqual(k, 0)
        nums = [1]
        k = remove_element(nums, 1)
        self.assertEqual(k, 0)
        self.assertEqual(nums[:k], [])
        nums = [1]
        k = remove_element(nums, 2)
        self.assertEqual(k, 1)
        self.assertEqual(nums[:k], [1])
        nums = [2, 2, 2, 2]
        k = remove_element(nums, 2)
        self.assertEqual(k, 0)
        nums = [1, 2, 3, 4, 5]
        k = remove_element(nums, 3)
        self.assertEqual(k, 4)
        self.assertEqual(sorted(nums[:k]), [1, 2, 4, 5])
        nums = [0, 1, 0, 3, 0]
        k = remove_element(nums, 0)
        self.assertEqual(k, 2)
        self.assertEqual(sorted(nums[:k]), [1, 3])
