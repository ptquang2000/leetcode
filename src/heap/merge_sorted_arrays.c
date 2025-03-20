#include "utils/asserts.h"

extern int *heap_merge_sorted_arrays(int size, int *sorted_arrays[size], int sorted_arrays_size[size], int *o_size);

void test_heap_merge_sorted_arrays()
{
        int_array actual = {}, expected = {};
        {
                int *sorted_arrays[] = {
                        (int[]){3, 5, 7},
                        (int[]){0, 6},
                        (int[]){0, 6, 28},
                };
                int sorted_arrays_size[] = {3, 2, 3};
                expected = (int_array){(int[]){0, 0, 3, 5, 6, 6, 7, 28}, 8};
                actual.data = heap_merge_sorted_arrays(ARRAY_SIZE(sorted_arrays_size), sorted_arrays,
                                                       sorted_arrays_size, &actual.len);
                ASSERT_EQUAL(actual, expected);
        }
        {
                int *sorted_arrays[] = {
                        (int[]){1, 4, 5},
                        (int[]){1, 3, 4},
                        (int[]){2, 6},
                };
                int sorted_arrays_size[] = {3, 3, 2};
                expected = (int_array){(int[]){1, 1, 2, 3, 4, 4, 5, 6}, 8};
                actual.data = heap_merge_sorted_arrays(ARRAY_SIZE(sorted_arrays_size), sorted_arrays,
                                                       sorted_arrays_size, &actual.len);
                ASSERT_EQUAL(actual, expected);
        }
        {
                int *sorted_arrays[] = {};
                int sorted_arrays_size[] = {};
                expected = (int_array){(int[]){}, 0};
                actual.data = heap_merge_sorted_arrays(ARRAY_SIZE(sorted_arrays_size), sorted_arrays,
                                                       sorted_arrays_size, &actual.len);
                ASSERT_EQUAL(actual, expected);
        }
}
