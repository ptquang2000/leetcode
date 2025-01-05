#include "array_string.h"
#include "utils.h"

#include <stdlib.h>

// Declaration
int* array_string_plusOne(int ASize, int A[ASize], int* size);

void test_array_string_plusOne()
{
        {
                int A[] = {1, 2, 9};
                int actualSize;
                int* actual = array_string_plusOne(3, A, &actualSize);
                UTILS_ASSERT_EQUAL(actualSize, 3);
                int expected[] = {1, 3, 0};
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, 3);
                free(actual);
        }
        {
                int A[] = {9, 9, 9};
                int actualSize;
                int* actual = array_string_plusOne(3, A, &actualSize);
                UTILS_ASSERT_EQUAL(actualSize, 4);
                int expected[] = {1, 0, 0, 0};
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, 4);
                free(actual);
        }
}
