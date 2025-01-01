#include "utils.h"

#include <stdlib.h>

// Declaration:
int** Recursion_permutations(int i_size, int A[i_size], int** o_size, int* o_count);

void test_Recursion_permutations()
{
        {
                int A[] = {2, 3, 5, 7};
                int expected[][4] = {
                        {2, 3, 5, 7}, {2, 3, 7, 5}, {2, 5, 3, 7}, {2, 5, 7, 3}, {2, 7, 3, 5}, {2, 7, 5, 3},
                        {3, 2, 5, 7}, {3, 2, 7, 5}, {3, 5, 2, 7}, {3, 5, 7, 2}, {3, 7, 2, 5}, {3, 7, 5, 2},
                        {5, 2, 3, 7}, {5, 2, 7, 3}, {5, 3, 2, 7}, {5, 3, 7, 2}, {5, 7, 3, 2}, {5, 7, 2, 3},
                        {7, 2, 3, 5}, {7, 2, 5, 3}, {7, 3, 2, 5}, {7, 3, 5, 2}, {7, 5, 2, 3}, {7, 5, 3, 2},
                };
                int expected_size[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
                int expected_count = ARRAY_SIZE(expected);
                int *actual_size, actual_count;
                int** actual = Recursion_permutations(ARRAY_SIZE(A), A, &actual_size, &actual_count);
                UTILS_ASSERT_EQUAL(actual_count, expected_count);
                UTILS_ASSERT_EQUAL_ARRAY(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free(actual_size);
                free_array(actual, actual_count);
        }
        {
                int A[] = {7, 3, 5};
                int expected[][3] = {{7, 3, 5}, {7, 5, 3}, {3, 7, 5}, {3, 5, 7}, {5, 3, 7}, {5, 7, 3}};
                int expected_size[] = {3, 3, 3, 3, 3, 3};
                int expected_count = ARRAY_SIZE(expected);
                int *actual_size, actual_count;
                int** actual = Recursion_permutations(ARRAY_SIZE(A), A, &actual_size, &actual_count);
                UTILS_ASSERT_EQUAL(actual_count, expected_count);
                UTILS_ASSERT_EQUAL_ARRAY(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free(actual_size);
                free_array(actual, actual_count);
        }
        {
                int A[] = {1, 2, 3};
                int expected[][3] = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
                int expected_size[] = {3, 3, 3, 3, 3, 3};
                int expected_count = ARRAY_SIZE(expected);
                int *actual_size, actual_count;
                int** actual = Recursion_permutations(ARRAY_SIZE(A), A, &actual_size, &actual_count);
                UTILS_ASSERT_EQUAL(actual_count, expected_count);
                UTILS_ASSERT_EQUAL_ARRAY(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free(actual_size);
                free_array(actual, actual_count);
        }
        {
                int A[] = {0, 1};
                int expected[][2] = {{0, 1}, {1, 0}};
                int expected_size[] = {2, 2};
                int expected_count = ARRAY_SIZE(expected);
                int *actual_size, actual_count;
                int** actual = Recursion_permutations(ARRAY_SIZE(A), A, &actual_size, &actual_count);
                UTILS_ASSERT_EQUAL(actual_count, expected_count);
                UTILS_ASSERT_EQUAL_ARRAY(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free(actual_size);
                free_array(actual, actual_count);
        }
        {
                int A[] = {1};
                int expected[][1] = {{1}};
                int expected_size[] = {1};
                int expected_count = ARRAY_SIZE(expected);
                int *actual_size, actual_count;
                int** actual = Recursion_permutations(ARRAY_SIZE(A), A, &actual_size, &actual_count);
                UTILS_ASSERT_EQUAL(actual_count, expected_count);
                UTILS_ASSERT_EQUAL_ARRAY(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free(actual_size);
                free_array(actual, actual_count);
        }
}
