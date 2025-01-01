#include "utils.h"
#include <stdlib.h>

// Declaration:
int** Recursion_combinations(int n, int k, int** o_size, int* o_count);

void test_Recursion_combinations()
{
        {
                const int n = 4, k = 2;
                int expected[][2] = {
                        {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4},
                };
                int expected_size[] = {k, k, k, k, k, k};
                int expected_count = ARRAY_SIZE(expected);
                int *actual_size, actual_count;
                int** actual = Recursion_combinations(n, k, &actual_size, &actual_count);
                UTILS_ASSERT_EQUAL(actual_count, expected_count);
                UTILS_ASSERT_EQUAL_ARRAY(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free_array(actual, actual_count);
                free(actual_size);
        }
        {
                const int n = 4, k = 3;
                int expected[][3] = {
                        {1, 2, 3},
                        {1, 2, 4},
                        {1, 3, 4},
                        {2, 3, 4},
                };
                int expected_size[] = {k, k, k};
                int expected_count = ARRAY_SIZE(expected);
                int *actual_size, actual_count;
                int** actual = Recursion_combinations(n, k, &actual_size, &actual_count);
                UTILS_ASSERT_EQUAL(actual_count, expected_count);
                UTILS_ASSERT_EQUAL_ARRAY(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free_array(actual, actual_count);
                free(actual_size);
        }
        {
                const int n = 1, k = 1;
                int expected[][1] = {
                        {1},
                };
                int expected_size[] = {k};
                int expected_count = ARRAY_SIZE(expected);
                int *actual_size, actual_count;
                int** actual = Recursion_combinations(n, k, &actual_size, &actual_count);
                UTILS_ASSERT_EQUAL(actual_count, expected_count);
                UTILS_ASSERT_EQUAL_ARRAY(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free_array(actual, actual_count);
                free(actual_size);
        }
}
