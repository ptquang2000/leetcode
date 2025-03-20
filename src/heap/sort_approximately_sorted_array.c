#include "utils/asserts.h"

extern void heap_sort_approximately_sorted_array(int size, int sequence[size], int k);

void test_heap_sort_approximately_sorted_array()
{
        {
                int_array sequence = {(int[]){6, 5, 3, 2, 8, 10, 9}, 7};
                int k = 3;
                heap_sort_approximately_sorted_array(sequence.len, sequence.data, k);
                int_array expected = {(int[]){2, 3, 5, 6, 8, 9, 10}, 7};
                ASSERT_EQUAL(sequence, expected);
        }
        {
                int_array sequence = {(int[]){1, 4, 5, 2, 3, 6, 7, 8, 9, 10}, 10};
                int k = 2;
                heap_sort_approximately_sorted_array(sequence.len, sequence.data, k);
                int_array expected = {(int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10};
                ASSERT_EQUAL(sequence, expected);
        }
}
