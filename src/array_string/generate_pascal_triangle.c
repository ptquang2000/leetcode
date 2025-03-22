#include "utils/asserts.h"

extern int **array_string_generatePascalTriangle(int n, int *rowSize, int **colSize);

void test_array_string_generatePascalTriangle()
{
        int_darray actual = {};
        actual.data = array_string_generatePascalTriangle(5, &actual.nr, &actual.len);
        int_darray expected = {(int *[]){
                                       (int[]){1},
                                       (int[]){1, 1},
                                       (int[]){1, 2, 1},
                                       (int[]){1, 3, 3, 1},
                                       (int[]){1, 4, 6, 4, 1},
                               },
                               (int[]){1, 2, 3, 4, 5}, 5};
        ASSERT_EQUAL(actual, expected);
        free(actual.len);
        free_array(actual.data, 5);
}
