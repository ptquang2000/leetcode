#include "utils.h"

#include <stdlib.h>

// Declaration:
int** Recursion_generate_power_set(int i_size, int i_input_set[i_size], int** o_size, int* o_count);

void test_Recursion_generate_power_set()
{
        {
                int input_set[] = {1, 2, 3};
                const int expected[][3] = {
                        {0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {1, 2, 0}, {3, 0, 0}, {1, 3, 0}, {2, 3, 0}, {1, 2, 3},
                };
                const int expected_size[] = {0, 1, 1, 2, 1, 2, 2, 3};
                const int expected_count = ARRAY_SIZE(expected);
                int *actual_size, actual_count;
                int** actual =
                        Recursion_generate_power_set(ARRAY_SIZE(input_set), input_set, &actual_size, &actual_count);
                UTILS_ASSERT_EQUAL(actual_count, expected_count);
                UTILS_ASSERT_COUNT_EQUAL(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free_array(actual, actual_count);
                free(actual_size);
        }
}
