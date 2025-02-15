#include "utils/utils.h"

extern int *heap_k_largest_in_binary_heap(int size, const int A[size], int k);

void test_heap_k_largest_in_binary_heap()
{
        {
                int expected[] = {50, 30, 23};
                int A[] = {1, 23, 12, 9, 30, 2, 50};
                int k = ARRAY_SIZE(expected);
                int *actual = heap_k_largest_in_binary_heap(ARRAY_SIZE(A), A, k);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, k);
        }
        {
                int expected[] = {44, 17};
                int A[] = {11, 5, 12, 9, 44, 17, 2};
                int k = ARRAY_SIZE(expected);
                int *actual = heap_k_largest_in_binary_heap(ARRAY_SIZE(A), A, k);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, k);
        }
        {
                int expected[] = {561, 314, 401, 359};
                int A[] = {561, 314, 401, 28, 156, 359, 271, 11, 3};
                int k = ARRAY_SIZE(expected);
                int *actual = heap_k_largest_in_binary_heap(ARRAY_SIZE(A), A, k);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, k);
        }
}
