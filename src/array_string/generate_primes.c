#include "array_string.h"
#include "utils/asserts.h"

extern int *array_string_generatePrimes(int n, int *size);

void test_array_string_generatePrimes()
{
        int_array actual;
        actual.data = array_string_generatePrimes(18, &actual.len);

        int_array expected = {(int[]){2, 3, 5, 7, 11, 13, 17}, 7};
        ASSERT_EQUAL(actual, expected);

        free(actual.data);
}
