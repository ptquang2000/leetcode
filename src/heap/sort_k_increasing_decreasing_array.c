#include "utils/asserts.h"

extern void heap_sort_k_increasing_decreasing_array(int size, int A[size]);

void test_heap_sort_k_increasing_decreasing_array()
{
        {
                int_array A = {(int[]){57, 131, 493, 294, 221, 339, 418, 452, 442, 190}, 10};
                int_array expected = {(int[]){57, 131, 190, 221, 294, 339, 418, 442, 452, 493}, 10};
                heap_sort_k_increasing_decreasing_array(A.len, A.data);
                ASSERT_EQUAL(A, expected);
        }
        {
                int_array A = {(int[]){1, 2, 3, 4, 3, 2, 1}, 7};
                int_array expected = {(int[]){1, 1, 2, 2, 3, 3, 4}, 7};
                heap_sort_k_increasing_decreasing_array(A.len, A.data);
                ASSERT_EQUAL(A, expected);
        }
}
