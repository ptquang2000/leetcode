#include "ArrayString.h"
#include "utils.h"

#include <stdlib.h>

// Declaration
int ArrayString_plusOne(int* A, int ASize, int* out);

void test_ArrayString_plusOne()
{
    {
        int A[] = {1, 2, 9};
        int expected[] = {1, 3, 0};
        int* actual;
        int actualSize = ArrayString_plusOne(A, 3, actual);
        UTILS_ASSERT_EQUAL(actualSize, 3);
        UTILS_ASSERT_EQUAL(actual, expected, 3);
        free(actual);
    }
    {
        int A[] = {9, 9, 9};
        int expected[] = {1, 0, 0, 0};
        int* actual;
        int actualSize = ArrayString_plusOne(A, 3, actual);
        UTILS_ASSERT_EQUAL(actualSize, 4);
        UTILS_ASSERT_EQUAL(actual, expected, 4);
        free(actual);
    }
}
