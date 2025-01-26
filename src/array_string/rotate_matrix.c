#include "utils.h"

// Declaration:
void array_string_rotateMatrix(int size, int* squareMatrix[size]);

void test_array_string_rotateMatrix()
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
        array_string_rotateMatrix(4, matrix);
        UTILS_ASSERT_EQUAL_ARRAY(matrix[0], expected[0], 4);
        UTILS_ASSERT_EQUAL_ARRAY(matrix[1], expected[1], 4);
        UTILS_ASSERT_EQUAL_ARRAY(matrix[2], expected[2], 4);
        UTILS_ASSERT_EQUAL_ARRAY(matrix[3], expected[3], 4);
}
