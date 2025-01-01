#include "utils.h"

#include <stdlib.h>

// Declaration:
int** ArrayString_generatePascalTriangle(int n, int* rowSize, int** colSize);

void test_ArrayString_generatePascalTriangle()
{
        int rowSize, *colSize;
        int** actual = ArrayString_generatePascalTriangle(5, &rowSize, &colSize);
        int expected[][5] = {
                {1, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {1, 2, 1, 0, 0}, {1, 3, 3, 1, 0}, {1, 4, 6, 4, 1},
        };

        UTILS_ASSERT_EQUAL(rowSize, 5);

        UTILS_ASSERT_EQUAL(colSize[0], 1);
        UTILS_ASSERT_EQUAL(colSize[1], 2);
        UTILS_ASSERT_EQUAL(colSize[2], 3);
        UTILS_ASSERT_EQUAL(colSize[3], 4);
        UTILS_ASSERT_EQUAL(colSize[4], 5);

        UTILS_ASSERT_EQUAL_ARRAY(actual[0], expected[0], 1);
        UTILS_ASSERT_EQUAL_ARRAY(actual[1], expected[1], 2);
        UTILS_ASSERT_EQUAL_ARRAY(actual[2], expected[2], 3);
        UTILS_ASSERT_EQUAL_ARRAY(actual[3], expected[3], 4);
        UTILS_ASSERT_EQUAL_ARRAY(actual[4], expected[4], 5);
        free(actual[0]);
        free(actual[1]);
        free(actual[2]);
        free(actual[3]);
        free(actual[4]);

        free(actual);
        free(colSize);
}
