#include "utils/asserts.h"

#include <stdlib.h>

extern int** recursion_permutations(int i_size, int A[i_size], int** o_size, int* o_count);

void test_recursion_permutations()
{
        {
                int A[] = {2, 3, 5, 7};
                int* expected[] = {
                        (int[]){2, 3, 5, 7}, (int[]){2, 3, 7, 5}, (int[]){2, 5, 3, 7}, (int[]){2, 5, 7, 3},
                        (int[]){2, 7, 3, 5}, (int[]){2, 7, 5, 3}, (int[]){3, 2, 5, 7}, (int[]){3, 2, 7, 5},
                        (int[]){3, 5, 2, 7}, (int[]){3, 5, 7, 2}, (int[]){3, 7, 2, 5}, (int[]){3, 7, 5, 2},
                        (int[]){5, 2, 3, 7}, (int[]){5, 2, 7, 3}, (int[]){5, 3, 2, 7}, (int[]){5, 3, 7, 2},
                        (int[]){5, 7, 3, 2}, (int[]){5, 7, 2, 3}, (int[]){7, 2, 3, 5}, (int[]){7, 2, 5, 3},
                        (int[]){7, 3, 2, 5}, (int[]){7, 3, 5, 2}, (int[]){7, 5, 2, 3}, (int[]){7, 5, 3, 2},
                };
                int expected_size[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
                int expected_count = ARRAY_SIZE(expected_size);
                int *actual_size, actual_count;
                int** actual = recursion_permutations(ARRAY_SIZE(A), A, &actual_size, &actual_count);
                ASSERT_EQUAL(actual_count, expected_count);
                ASSERT_EQUAL(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free(actual_size);
                free_array(actual, actual_count);
        }
        {
                int A[] = {7, 3, 5};
                int* expected[] = {(int[]){7, 3, 5}, (int[]){7, 5, 3}, (int[]){3, 7, 5},
                                   (int[]){3, 5, 7}, (int[]){5, 3, 7}, (int[]){5, 7, 3}};
                int expected_size[] = {3, 3, 3, 3, 3, 3};
                int expected_count = ARRAY_SIZE(expected_size);
                int *actual_size, actual_count;
                int** actual = recursion_permutations(ARRAY_SIZE(A), A, &actual_size, &actual_count);
                ASSERT_EQUAL(actual_count, expected_count);
                ASSERT_EQUAL(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free(actual_size);
                free_array(actual, actual_count);
        }
        {
                int A[] = {1, 2, 3};
                int* expected[] = {(int[]){1, 2, 3}, (int[]){1, 3, 2}, (int[]){2, 1, 3},
                                   (int[]){2, 3, 1}, (int[]){3, 1, 2}, (int[]){3, 2, 1}};
                int expected_size[] = {3, 3, 3, 3, 3, 3};
                int expected_count = ARRAY_SIZE(expected_size);
                int *actual_size, actual_count;
                int** actual = recursion_permutations(ARRAY_SIZE(A), A, &actual_size, &actual_count);
                ASSERT_EQUAL(actual_count, expected_count);
                ASSERT_EQUAL(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free(actual_size);
                free_array(actual, actual_count);
        }
        {
                int A[] = {0, 1};
                int* expected[] = {(int[]){0, 1}, (int[]){1, 0}};
                int expected_size[] = {2, 2};
                int expected_count = ARRAY_SIZE(expected_size);
                int *actual_size, actual_count;
                int** actual = recursion_permutations(ARRAY_SIZE(A), A, &actual_size, &actual_count);
                ASSERT_EQUAL(actual_count, expected_count);
                ASSERT_EQUAL(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free(actual_size);
                free_array(actual, actual_count);
        }
        {
                int A[] = {1};
                int* expected[] = {(int[]){1}};
                int expected_size[] = {1};
                int expected_count = ARRAY_SIZE(expected_size);
                int *actual_size, actual_count;
                int** actual = recursion_permutations(ARRAY_SIZE(A), A, &actual_size, &actual_count);
                ASSERT_EQUAL(actual_count, expected_count);
                ASSERT_EQUAL(actual_size, expected_size, expected_count);
                UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, expected_count);

                free(actual_size);
                free_array(actual, actual_count);
        }
}
