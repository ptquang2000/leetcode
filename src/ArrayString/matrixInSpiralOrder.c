#include "utils.h"

#include <stdlib.h>

// Declaration:
int* ArrayString_matrixInSpiralOrder(int* squareMatrix[], int size, int* oSize);

void test_ArrayString_matrixInSpiralOrder()
{
    {
        int* matrix[3] = {
            (int[]){1, 2, 3},
            (int[]){4, 5, 6},
            (int[]){7, 8, 9},
        };
        int actualSize;
        int* actual = ArrayString_matrixInSpiralOrder(matrix, 3, &actualSize);
        UTILS_ASSERT_EQUAL(actualSize, 9);
        int expect[] = {1, 2, 3, 6, 9, 8, 7, 4, 5};
        UTILS_ASSERT_EQUAL(actual, expect, 3);
        free(actual);
    }
    {
        int* matrix[4] = {
            (int[]){1, 2, 3, 4},
            (int[]){5, 6, 7, 8},
            (int[]){9, 10, 11, 12},
            (int[]){13, 14, 15, 16},
        };
        int actualSize;
        int* actual = ArrayString_matrixInSpiralOrder(matrix, 4, &actualSize);
        UTILS_ASSERT_EQUAL(actualSize, 16);
        int expect[] = {1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10};
        UTILS_ASSERT_EQUAL(actual, expect, 4);
        free(actual);
    }
}
