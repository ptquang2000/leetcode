#include "utils/utils.h"

extern void heap_sort_k_increasing_decreasing_array(int size, int A[size]);

void test_heap_sort_k_increasing_decreasing_array()
{
        {
                int A[] = {57, 131, 493, 294, 221, 339, 418, 452, 442, 190};
                int expected[] = {57, 131, 190, 221, 294, 339, 418, 442, 458, 493};
                heap_sort_k_increasing_decreasing_array(ARRAY_SIZE(A), A);
                UTILS_ASSERT_EQUAL_ARRAY(A, expected, ARRAY_SIZE(expected));
        }
        {
                int A[] = {1, 2, 3, 4, 3, 2, 1};
                int expected[] = {1, 1, 2, 2, 3, 3, 4};
                heap_sort_k_increasing_decreasing_array(ARRAY_SIZE(A), A);
                UTILS_ASSERT_EQUAL_ARRAY(A, expected, ARRAY_SIZE(expected));
        }
}
