#include "utils/asserts.h"

extern float *heap_online_median(int size, int sequence[size]);

void test_heap_online_median()
{
        int sequence[] = {1, 0, 3, 5, 2, 0, 1};
        float expected[] = {1, 0.5, 1, 2, 2, 1.5, 1};
        float *actual = heap_online_median(ARRAY_SIZE(sequence), sequence);
        ASSERT_EQUAL(actual, expected, ARRAY_SIZE(expected));
}
