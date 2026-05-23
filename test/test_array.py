import unittest
from test import (
    apply_permutation,
    buy_and_sell_stock_once,
    buy_and_sell_stock_twice,
    can_reach_end,
    delete_duplicates,
    dutch_flag_partition,
    generate_primes,
    multiply,
    next_permutation,
    plus_one,
)


class TestArray(unittest.TestCase):
    def test_apply_permutation(self):
        A = ['a','b','c','d']
        apply_permutation([3,2,1,0], A)
        self.assertEqual(A, ['d','c','b','a'])
        A = ['a','b','c','d']
        apply_permutation([2,0,1,3], A)
        self.assertEqual(A, ['b','c','a','d'])

    def test_buy_and_sell_stock_once(self):
        A = [310,315,275,295,260,270,290,230,255,250]
        self.assertEqual(buy_and_sell_stock_once(A), 30)

    def test_buy_and_sell_stock_twice(self):
        A = [12,11,13,9,12,8,14,13,15]
        self.assertEqual(buy_and_sell_stock_twice(A), 10)

    def test_can_reach_end(self):
        self.assertTrue(can_reach_end([2,4,1,1,0,2,3]))
        self.assertTrue(can_reach_end([3,3,7,0,2,0,1]))
        self.assertFalse(can_reach_end([3,2,0,0,2,0,7]))

    def test_delete_duplicates(self):
        A = [2,3,5,5,7,11,11,11,13]
        self.assertEqual(delete_duplicates(A), 6)
        self.assertEqual(A[:6], [2,3,5,7,11,13])

    def _dutch_inner(self, pivot_idx, A):
        pivot = A[pivot_idx]
        dutch_flag_partition(pivot_idx, A)
        first = A.index(pivot)
        A.reverse()
        last = len(A) - 1 - A.index(pivot)
        A.reverse()
        self.assertEqual([i < pivot for i in A[0:first]], [True for _ in A[0:first]])
        self.assertEqual([i == pivot for i in A[first:last + 1]], [True for _ in A[first:last + 1]])
        self.assertEqual([i > pivot for i in A[last + 1:]], [True for _ in A[last + 1:]])

    def test_dutch_flag_partition(self):
        A = [0,1,2,0,2,1,1]
        self._dutch_inner(3, A[:])
        self._dutch_inner(2, A[:])

    def test_generate_primes(self):
        self.assertEqual(generate_primes(18), [2,3,5,7,11,13,17])

    def test_multiply(self):
        num1 = [1,9,3,7,0,7,7,2,1]
        num2 = [-7,6,1.,8,3,8,2,5,7,2,8,7]
        self.assertEqual(multiply(num1, num2), [-1,4,7,5,7,3,9,5,2,5,8,9,6,7,6,4,1,2,9,2,7])

    def test_next_permutation(self):
        self.assertEqual(next_permutation([1,0,3,2]), [1,2,0,3])
        self.assertEqual(next_permutation([3,2,1,0]), [])
        self.assertEqual(next_permutation([6,2,1,5,4,3,0]), [6,2,3,0,1,4,5])

    def test_plus_one(self):
        self.assertEqual(plus_one([1,2,9]), [1,3,0])
        self.assertEqual(plus_one([9,9,9]), [1,0,0,0])
