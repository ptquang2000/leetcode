#include "ArrayString.h"
#include "utils.h"

#include <stdlib.h>

// Declaration:
int* ArrayString_multiply(int* num1, int num1Size, int* num2, int num2Size, int* numSize);

void test_ArrayString_multiply()
{
    int num1[] = {1, 9, 3, 7, 0, 7, 7, 2, 1};
    int num2[] = {-7, 6, 1., 8, 3, 8, 2, 5, 7, 2, 8, 7};

    int actualSize;
    int* actual = ArrayString_multiply(num1, 9, num2, 12, &actualSize);

    int expect[] = {-1, 4, 7, 5, 7, 3, 9, 5, 2, 5, 8, 9, 6, 7, 6, 4, 1, 2, 9, 2, 7};
    UTILS_ASSERT_EQUAL(actualSize, 21);
    UTILS_ASSERT_EQUAL(actual, expect, 21);
    free(actual);
}
