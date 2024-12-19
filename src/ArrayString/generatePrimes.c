#include "ArrayString.h"
#include "utils.h"

#include <stdlib.h>

// Declaration:
int* ArrayString_generatePrimes(int n, int* size);

void test_ArrayString_generatePrimes()
{
        int actualSize;
        int* actual = ArrayString_generatePrimes(18, &actualSize);

        int expect[] = {2, 3, 5, 7, 11, 13, 17};
        UTILS_ASSERT_EQUAL(actualSize, 7);
        UTILS_ASSERT_EQUAL(actual, expect, 7);

        free(actual);
}
