#include "utils/asserts.h"

extern int *heap_k_largest_in_binary_heap(int size, const int A[size], int k);

void test_heap_k_largest_in_binary_heap()
{
        int_array actual = {}, expected = {};
        {
                expected = (int_array){(int[]){50, 30, 23}, 3};
                int A[] = {50, 23, 30, 1, 9, 2, 12};
                actual.data = heap_k_largest_in_binary_heap(ARRAY_SIZE(A), A, expected.len);
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                expected = (int_array){(int[]){44, 17}, 2};
                int A[] = {44, 12, 17, 5, 9, 11, 2};
                actual.data = heap_k_largest_in_binary_heap(ARRAY_SIZE(A), A, expected.len);
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                expected = (int_array){(int[]){561, 401, 359, 314}, 4};
                int A[] = {561, 314, 401, 28, 156, 359, 271, 11, 3};
                actual.data = heap_k_largest_in_binary_heap(ARRAY_SIZE(A), A, expected.len);
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
}
