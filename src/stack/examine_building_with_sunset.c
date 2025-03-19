#include "utils/asserts.h"

#include <stdlib.h>

extern int* stack_examine_building_with_sunset(int size, int sequence[size], int* o_size);

void test_stack_examine_building_with_sunset()
{
        {
                int sequence[] = {15, 14, 13, 12, 11};
                int expected[] = {4, 3, 2, 1, 0};
                int actualSize;
                int* actual =
                        stack_examine_building_with_sunset(sizeof(sequence) / sizeof(*sequence), sequence, &actualSize);
                ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected));
                ASSERT_EQUAL(actual, expected, actualSize);
                free(actual);
        }
        {
                int sequence[] = {9, 2, 8, 4, 7};
                int expected[] = {4, 2, 0};
                int actualSize;
                int* actual =
                        stack_examine_building_with_sunset(sizeof(sequence) / sizeof(*sequence), sequence, &actualSize);
                ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected));
                ASSERT_EQUAL(actual, expected, actualSize);
                free(actual);
        }
}
