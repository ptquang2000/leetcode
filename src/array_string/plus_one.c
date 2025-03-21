#include "array_string.h"
#include "utils/asserts.h"

#include <stdlib.h>

extern int *array_string_plusOne(int ASize, int A[ASize], int *size);

void test_array_string_plusOne()
{
        {
                int A[] = {1, 2, 9};
                int_array actual;
                actual.data = array_string_plusOne(3, A, &actual.len);
                int_array expected = {(int[]){1, 3, 0}, 3};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                int A[] = {9, 9, 9};
                int_array actual;
                actual.data = array_string_plusOne(3, A, &actual.len);
                int_array expected = {(int[]){1, 0, 0, 0}, 4};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
}
