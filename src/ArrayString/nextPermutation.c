#include "ArrayString.h"
#include "utils.h"

#include <stdlib.h>

// Declaration:
int ArrayString_nextPermutation(int* perm, int permSize, int* out);

void test_ArrayString_nextPermutation()
{
    {
        int perm[] = {1, 0, 3, 2};
        int expect[] = {1, 2, 0, 3};
        int* actual;
        int actualSize = ArrayString_nextPermutation(perm, 4, actual);
        UTILS_ASSERT_EQUAL(actualSize, 4);
        UTILS_ASSERT_EQUAL(actual, expect, 4);
        free(actual);
    }
    {
        int perm[] = {3, 2, 1, 0};
        int expect[] = {};
        int* actual;
        int actualSize = ArrayString_nextPermutation(perm, 4, actual);
        UTILS_ASSERT_EQUAL(actualSize, 0);
        UTILS_ASSERT_EQUAL(actual, expect, 0);
        free(actual);
    }
    {
        int perm[] = {6, 2, 1, 5, 4, 3, 0};
        int expect[] = {6, 2, 3, 0, 1, 4, 5};
        int* actual;
        int actualSize = ArrayString_nextPermutation(perm, 7, actual);
        UTILS_ASSERT_EQUAL(actualSize, 7);
        UTILS_ASSERT_EQUAL(actual, expect, 7);
        free(actual);
    }
}
