#include "utils.h"

// Declaration:
void ArrayString_rotateMatrix(int* squareMatrix[], int size);

void test_ArrayString_rotateMatrix()
{
    int* matrix[] = {
        (int[]){1, 2, 3, 4},
        (int[]){5, 6, 7, 8},
        (int[]){9, 10, 11, 12},
        (int[]){13, 14, 15, 16},
    };
    int expected[][4] = {
        {13, 9, 5, 1},
        {14, 10, 6, 2},
        {15, 11, 7, 3},
        {16, 12, 8, 4},
    };
    ArrayString_rotateMatrix(matrix, 4);
    UTILS_ASSERT_EQUAL(matrix[0], expected[0], 4);
    UTILS_ASSERT_EQUAL(matrix[1], expected[1], 4);
    UTILS_ASSERT_EQUAL(matrix[2], expected[2], 4);
    UTILS_ASSERT_EQUAL(matrix[3], expected[3], 4);
}
