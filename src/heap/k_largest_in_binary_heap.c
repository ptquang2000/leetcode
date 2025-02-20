#include "utils/utils.h"

extern int *heap_k_largest_in_binary_heap(int size, const int A[size], int k);

void test_heap_k_largest_in_binary_heap()
{
        {
                int expected[] = {50, 30, 23};
                int A[] = {50, 23, 30, 1, 9, 2, 12};
                int k = ARRAY_SIZE(expected);
                int *actual = heap_k_largest_in_binary_heap(ARRAY_SIZE(A), A, k);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, k);
                free(actual);
        }
        {
                int expected[] = {44, 17};
                int A[] = {44, 12, 17, 5, 9, 11, 2};
                int k = ARRAY_SIZE(expected);
                int *actual = heap_k_largest_in_binary_heap(ARRAY_SIZE(A), A, k);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, k);
                free(actual);
        }
        {
                int expected[] = {561, 401, 359, 314};
                int A[] = {561, 314, 401, 28, 156, 359, 271, 11, 3};
                int k = ARRAY_SIZE(expected);
                int *actual = heap_k_largest_in_binary_heap(ARRAY_SIZE(A), A, k);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, k);
                free(actual);
        }
}
