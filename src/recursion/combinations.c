#include "utils/asserts.h"
#include "utils/helper.h"
#include <stdlib.h>

extern int **recursion_combinations(int n, int k, int **o_size, int *o_count);

void test_recursion_combinations()
{
        int_darray actual = {}, expected = {};
        {
                const int n = 4, k = 2;
                expected = (int_darray){(int *[]){
                                                (int[]){1, 2},
                                                (int[]){1, 3},
                                                (int[]){1, 4},
                                                (int[]){2, 3},
                                                (int[]){2, 4},
                                                (int[]){3, 4},
                                        },
                                        (int[]){k, k, k, k, k, k}, 6};
                actual.data = recursion_combinations(n, k, &actual.len, &actual.nr);
                ASSERT_COUNT_EQUAL(actual, expected);

                free_array(actual.data, actual.nr);
                free(actual.len);
        }
        {
                const int n = 4, k = 3;
                expected = (int_darray){(int *[]){
                                                (int[]){1, 2, 3},
                                                (int[]){1, 2, 4},
                                                (int[]){1, 3, 4},
                                                (int[]){2, 3, 4},
                                        },
                                        (int[]){k, k, k, k}, 4};
                actual.data = recursion_combinations(n, k, &actual.len, &actual.nr);
                ASSERT_COUNT_EQUAL(actual, expected);

                free_array(actual.data, actual.nr);
                free(actual.len);
        }
        {
                const int n = 1, k = 1;
                expected = (int_darray){(int *[]){
                                                (int[]){1},
                                        },
                                        (int[]){k}, 1};
                actual.data = recursion_combinations(n, k, &actual.len, &actual.nr);
                ASSERT_COUNT_EQUAL(actual, expected);

                free_array(actual.data, actual.nr);
                free(actual.len);
        }
}
