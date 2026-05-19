import unittest
from test import dutch_flag_partition

class TestDutchFlagPartition(unittest.TestCase):
    def inner(self, pivot_idx, A):
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
        self.inner(3, A[:])
        self.inner(2, A[:])
