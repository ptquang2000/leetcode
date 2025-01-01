#include "utils.h"

#include <stdlib.h>

// Declaration:
int* Stack_examineBuildingWithSunset(int size, int sequence[size], int* o_size);

void test_Stack_examineBuildingWithSunset()
{
        {
                int sequence[] = {15, 14, 13, 12, 11};
                int expected[] = {4, 3, 2, 1, 0};
                int actualSize;
                int* actual =
                        Stack_examineBuildingWithSunset(sizeof(sequence) / sizeof(*sequence), sequence, &actualSize);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected));
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, actualSize);
                free(actual);
        }
        {
                int sequence[] = {9, 2, 8, 4, 7};
                int expected[] = {4, 2, 0};
                int actualSize;
                int* actual =
                        Stack_examineBuildingWithSunset(sizeof(sequence) / sizeof(*sequence), sequence, &actualSize);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected));
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, actualSize);
                free(actual);
        }
}
