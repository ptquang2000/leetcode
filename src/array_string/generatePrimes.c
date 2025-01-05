#include "array_string.h"
#include "utils.h"

#include <stdlib.h>

// Declaration:
int* array_string_generatePrimes(int n, int* size);

void test_array_string_generatePrimes()
{
        int actualSize;
        int* actual = array_string_generatePrimes(18, &actualSize);

        int expect[] = {2, 3, 5, 7, 11, 13, 17};
        UTILS_ASSERT_EQUAL(actualSize, 7);
        UTILS_ASSERT_EQUAL_ARRAY(actual, expect, 7);

        free(actual);
}

