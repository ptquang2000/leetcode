#include "utils/asserts.h"

extern int *heap_merge_sorted_arrays(int size, int *sorted_arrays[size], int sorted_arrays_size[size], int *o_size);

void test_heap_merge_sorted_arrays()
{
        {
                int *sorted_arrays[] = {
                        (int[]){3, 5, 7},
                        (int[]){0, 6},
                        (int[]){0, 6, 28},
                };
                int sorted_arrays_size[] = {3, 2, 3};
                int expected[] = {0, 0, 3, 5, 6, 6, 7, 28};
                int expected_size;
                int *actual = heap_merge_sorted_arrays(ARRAY_SIZE(sorted_arrays_size), sorted_arrays,
                                                       sorted_arrays_size, &expected_size);
                ASSERT_EQUAL(expected_size, ARRAY_SIZE(expected));
                ASSERT_EQUAL(actual, expected, ARRAY_SIZE(expected));
        }
        {
                int *sorted_arrays[] = {
                        (int[]){1, 4, 5},
                        (int[]){1, 3, 4},
                        (int[]){2, 6},
                };
                int sorted_arrays_size[] = {3, 3, 2};
                int expected[] = {1, 1, 2, 3, 4, 4, 5, 6};
                int expected_size;
                int *actual = heap_merge_sorted_arrays(ARRAY_SIZE(sorted_arrays_size), sorted_arrays,
                                                       sorted_arrays_size, &expected_size);
                ASSERT_EQUAL(expected_size, ARRAY_SIZE(expected));
                ASSERT_EQUAL(actual, expected, ARRAY_SIZE(expected));
        }
        {
                int *sorted_arrays[] = {};
                int sorted_arrays_size[] = {};
                int expected[] = {};
                int expected_size;
                int *actual = heap_merge_sorted_arrays(ARRAY_SIZE(sorted_arrays_size), sorted_arrays,
                                                       sorted_arrays_size, &expected_size);
                ASSERT_EQUAL(expected_size, ARRAY_SIZE(expected));
                ASSERT_EQUAL(actual, expected, ARRAY_SIZE(expected));
        }
}
