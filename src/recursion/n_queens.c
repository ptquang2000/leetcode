#include "utils/asserts.h"
#include <stdlib.h>

extern int **recursion_n_queens(int n, int **o_size, int *o_count);

void test_recursion_n_queens()
{
        int_darray actual = {}, expected = {};
        {
                int n = 1;
                expected = (int_darray){(int *[]){
                                                (int[]){0},
                                        },
                                        (int[]){1}, 1};
                actual.data = recursion_n_queens(n, &actual.len, &actual.nr);
                ASSERT_COUNT_EQUAL(actual, expected);

                free(actual.len);
                free_array(actual.data, actual.nr);
        }
        {
                int n = 4;
                expected = (int_darray){(int *[]){
                                                (int[]){1, 3, 0, 2},
                                                (int[]){2, 0, 3, 1},
                                        },
                                        (int[]){4, 4}, 2};
                actual.data = recursion_n_queens(n, &actual.len, &actual.nr);
                ASSERT_COUNT_EQUAL(actual, expected);

                free(actual.len);
                free_array(actual.data, actual.nr);
        }
}
