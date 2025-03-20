#include "utils/asserts.h"

extern int *stack_examine_building_with_sunset(int size, int sequence[size], int *o_size);

void test_stack_examine_building_with_sunset()
{
        int_array actual = {}, expected = {};
        {
                int sequence[] = {15, 14, 13, 12, 11};
                expected = (int_array){(int[]){4, 3, 2, 1, 0}, 5};
                actual.data = stack_examine_building_with_sunset(ARRAY_SIZE(sequence), sequence, &actual.len);
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                int sequence[] = {9, 2, 8, 4, 7};
                expected = (int_array){(int[]){4, 2, 0}, 3};
                actual.data = stack_examine_building_with_sunset(ARRAY_SIZE(sequence), sequence, &actual.len);
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
}
