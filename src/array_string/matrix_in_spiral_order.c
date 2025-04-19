#include "utils/asserts.h"

extern int *array_string_matrixInSpiralOrder(int size, int *squareMatrix[size], int *oSize);

void test_array_string_matrixInSpiralOrder()
{
        {
                int_darray matrix = {(int *[]){
                                             (int[]){1, 2, 3},
                                             (int[]){4, 5, 6},
                                             (int[]){7, 8, 9},
                                     },
                                     (int[]){3, 3, 3}, 3};
                int_array actual;
                actual.data = array_string_matrixInSpiralOrder(matrix.nr, matrix.data, &actual.len);
                int_array expect = {(int[]){1, 2, 3, 6, 9, 8, 7, 4, 5}, 9};
                ASSERT_EQUAL(actual, expect);
                free(actual.data);
        }
        {
                int_darray matrix = {(int *[]){
                                             (int[]){1, 2, 3, 4},
                                             (int[]){5, 6, 7, 8},
                                             (int[]){9, 10, 11, 12},
                                             (int[]){13, 14, 15, 16},
                                     },
                                     (int[]){4, 4, 4, 4}, 4};
                int_array actual;
                actual.data = array_string_matrixInSpiralOrder(matrix.nr, matrix.data, &actual.len);
                int_array expect = {(int[]){1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10}, 16};
                ASSERT_EQUAL(actual, expect);
                free(actual.data);
        }
}
