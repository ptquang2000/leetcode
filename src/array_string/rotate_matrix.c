#include "utils/asserts.h"

extern void array_string_rotateMatrix(int size, int *squareMatrix[size]);

void test_array_string_rotateMatrix()
{
        int_darray matrix = {(int *[]){
                                     (int[]){1, 2, 3, 4},
                                     (int[]){5, 6, 7, 8},
                                     (int[]){9, 10, 11, 12},
                                     (int[]){13, 14, 15, 16},
                             },
                             (int[]){4, 4, 4, 4}, 4};
        int_darray expected = {(int *[]){
                                       (int[]){13, 9, 5, 1},
                                       (int[]){14, 10, 6, 2},
                                       (int[]){15, 11, 7, 3},
                                       (int[]){16, 12, 8, 4},
                               },
                               (int[]){4, 4, 4, 4}, 4};
        array_string_rotateMatrix(4, matrix.data);
        ASSERT_EQUAL(matrix, expected);
}
