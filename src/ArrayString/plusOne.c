#include "ArrayString.h"
#include "utils.h"

#include <stdlib.h>

// Declaration
int* ArrayString_plusOne(int ASize, int A[ASize], int* size);

void test_ArrayString_plusOne()
{
        {
                int A[] = {1, 2, 9};
                int actualSize;
                int* actual = ArrayString_plusOne(3, A, &actualSize);
                UTILS_ASSERT_EQUAL(actualSize, 3);
                int expected[] = {1, 3, 0};
                UTILS_ASSERT_EQUAL(actual, expected, 3);
                free(actual);
        }
        {
                int A[] = {9, 9, 9};
                int actualSize;
                int* actual = ArrayString_plusOne(3, A, &actualSize);
                UTILS_ASSERT_EQUAL(actualSize, 4);
                int expected[] = {1, 0, 0, 0};
                UTILS_ASSERT_EQUAL(actual, expected, 4);
                free(actual);
        }
}
