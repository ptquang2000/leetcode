#include "array_string.h"
#include "utils/asserts.h"

extern int *array_string_nextPermutation(int permSize, int perm[permSize], int *size);

void test_array_string_nextPermutation()
{
        {
                int perm[] = {1, 0, 3, 2};
                int_array expect = {(int[]){1, 2, 0, 3}, 4};
                int_array actual;
                actual.data = array_string_nextPermutation(ARRAY_SIZE(perm), perm, &actual.len);
                ASSERT_EQUAL(actual, expect);
                if (actual.data != perm)
                        free(actual.data);
        }
        {
                int perm[] = {3, 2, 1, 0};
                int_array actual;
                actual.data = array_string_nextPermutation(ARRAY_SIZE(perm), perm, &actual.len);
                ASSERT_IS_NULL(actual);
                if (actual.data != perm)
                        free(actual.data);
        }
        {
                int perm[] = {6, 2, 1, 5, 4, 3, 0};
                int_array expect = {(int[]){6, 2, 3, 0, 1, 4, 5}, 7};
                int_array actual;
                actual.data = array_string_nextPermutation(ARRAY_SIZE(perm), perm, &actual.len);
                ASSERT_EQUAL(actual, expect);
                if (actual.data != perm)
                        free(actual.data);
        }
}
