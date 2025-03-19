#include "utils/asserts.h"
#include <stdlib.h>

extern int** recursion_n_queens(int n, int** o_size, int* o_count);

void test_recursion_n_queens()
{
        {
                int n = 1;
                int* expected[1] = {
                        (int[]){0},
                };
                int expected_size[] = {1};
                int expected_count = ARRAY_SIZE(expected_size), actual_count, *actual_size;
                int** actual = recursion_n_queens(n, &actual_size, &actual_count);
                ASSERT_EQUAL(actual_count, expected_count);
                UTILS_ASSERT_COUNT_EQUAL(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free(actual_size);
                free_array(actual, actual_count);
        }
        {
                int n = 4;
                int* expected[4] = {
                        (int[]){1, 3, 0, 2},
                        (int[]){2, 0, 3, 1},
                };
                int expected_size[] = {4, 4};
                int expected_count = ARRAY_SIZE(expected_size), actual_count, *actual_size;
                int** actual = recursion_n_queens(n, &actual_size, &actual_count);
                ASSERT_EQUAL(actual_count, expected_count);
                UTILS_ASSERT_COUNT_EQUAL(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free(actual_size);
                free_array(actual, actual_count);
        }
}
