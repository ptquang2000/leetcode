#include "utils/asserts.h"

extern double *heap_online_median(int size, int sequence[size], int *o_size);

void test_heap_online_median()
{
        int_array sequence = {(int[]){1, 0, 3, 5, 2, 0, 1}, 7};
        double_array expected = {(double[]){1, 0.5, 1, 2, 2, 1.5, 1}, 7};
        double_array actual = (double_array){heap_online_median(sequence.len, sequence.data, &actual.len)};
        ASSERT_EQUAL(actual, expected);
}
