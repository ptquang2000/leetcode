#include "utils/asserts.h"

extern int **recursion_generate_power_set(int i_size, int i_input_set[i_size], int **o_size, int *o_count);

void test_recursion_generate_power_set()
{
        int_darray actual = {}, expected = {};
        {
                int input_set[] = {0};
                expected = (int_darray){
                        (int *[]){
                                (int[]){},
                                (int[]){0},
                        },
                        (int[]){0, 1},
                        2,
                };
                actual.data = recursion_generate_power_set(ARRAY_SIZE(input_set), input_set, &actual.len, &actual.nr);
                ASSERT_COUNT_EQUAL(actual, expected);

                free_array(actual.data, actual.nr);
                free(actual.len);
        }
        {
                int input_set[] = {1, 2, 3};
                expected = (int_darray){(int *[]){
                                                (int[]){0, 0, 0},
                                                (int[]){1, 0, 0},
                                                (int[]){2, 0, 0},
                                                (int[]){1, 2, 0},
                                                (int[]){3, 0, 0},
                                                (int[]){1, 3, 0},
                                                (int[]){2, 3, 0},
                                                (int[]){1, 2, 3},
                                        },
                                        (int[]){0, 1, 1, 2, 1, 2, 2, 3}, 8};
                actual.data = recursion_generate_power_set(ARRAY_SIZE(input_set), input_set, &actual.len, &actual.nr);
                ASSERT_COUNT_EQUAL(actual, expected);

                free_array(actual.data, actual.nr);
                free(actual.len);
        }
}
