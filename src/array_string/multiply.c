#include "array_string.h"
#include "utils/asserts.h"

extern int *array_string_multiply(int num1Size, int num1[num1Size], int num2Size, int num2[num2Size], int *numSize);

void test_array_string_multiply()
{
        int num1[] = {1, 9, 3, 7, 0, 7, 7, 2, 1};
        int num2[] = {-7, 6, 1., 8, 3, 8, 2, 5, 7, 2, 8, 7};

        int_array actual;
        actual.data = array_string_multiply(ARRAY_SIZE(num1), num1, ARRAY_SIZE(num2), num2, &actual.len);

        int_array expect = {(int[]){-1, 4, 7, 5, 7, 3, 9, 5, 2, 5, 8, 9, 6, 7, 6, 4, 1, 2, 9, 2, 7}, 21};
        ASSERT_EQUAL(actual, expect);
        free(actual.data);
}
