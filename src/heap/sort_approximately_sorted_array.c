#include "utils/asserts.h"

extern void heap_sort_approximately_sorted_array(int size, int sequence[size], int k);

void test_heap_sort_approximately_sorted_array()
{
        {
                int sequence[] = {6, 5, 3, 2, 8, 10, 9};
                int k = 3;
                heap_sort_approximately_sorted_array(ARRAY_SIZE(sequence), sequence, k);
                int expected[] = {2, 3, 5, 6, 8, 9, 10};
                ASSERT_EQUAL(sequence, expected, ARRAY_SIZE(expected));
        }
        {
                int sequence[] = {1, 4, 5, 2, 3, 6, 7, 8, 9, 10};
                int k = 2;
                heap_sort_approximately_sorted_array(ARRAY_SIZE(sequence), sequence, k);
                int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
                ASSERT_EQUAL(sequence, expected, ARRAY_SIZE(expected));
        }
}
