#include "array_string.h"
#include "utils/utils.h"

#include <stdlib.h>

// Declaration:
int* array_string_nextPermutation(int permSize, int perm[permSize], int* size);

void test_array_string_nextPermutation()
{
        {
                int perm[] = {1, 0, 3, 2};
                int expect[] = {1, 2, 0, 3};
                int actualSize;
                int* actual = array_string_nextPermutation(4, perm, &actualSize);
                UTILS_ASSERT_EQUAL(actualSize, 4);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expect, 4);
                if (actual != perm)
                {
                        free(actual);
                }
        }
        {
                int perm[] = {3, 2, 1, 0};
                int actualSize;
                int* actual = array_string_nextPermutation(4, perm, &actualSize);
                UTILS_ASSERT_EQUAL(actualSize, 0);
                UTILS_ASSERT_EQUAL_ARRAY(actual, NULL, 0);
                if (actual != perm)
                {
                        free(actual);
                }
        }
        {
                int perm[] = {6, 2, 1, 5, 4, 3, 0};
                int expect[] = {6, 2, 3, 0, 1, 4, 5};
                int actualSize;
                int* actual = array_string_nextPermutation(7, perm, &actualSize);
                UTILS_ASSERT_EQUAL(actualSize, 7);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expect, 7);
                if (actual != perm)
                {
                        free(actual);
                }
        }
}
