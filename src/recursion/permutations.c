#include "utils/asserts.h"

extern int **recursion_permutations(int i_size, int A[i_size], int **o_size, int *o_count);

void test_recursion_permutations()
{
        int_darray actual = {}, expected = {};
        {
                int A[] = {2, 3, 5, 7};
                expected = (int_darray){
                        (int *[]){
                                (int[]){2, 3, 5, 7}, (int[]){2, 3, 7, 5}, (int[]){2, 5, 3, 7}, (int[]){2, 5, 7, 3},
                                (int[]){2, 7, 3, 5}, (int[]){2, 7, 5, 3}, (int[]){3, 2, 5, 7}, (int[]){3, 2, 7, 5},
                                (int[]){3, 5, 2, 7}, (int[]){3, 5, 7, 2}, (int[]){3, 7, 2, 5}, (int[]){3, 7, 5, 2},
                                (int[]){5, 2, 3, 7}, (int[]){5, 2, 7, 3}, (int[]){5, 3, 2, 7}, (int[]){5, 3, 7, 2},
                                (int[]){5, 7, 3, 2}, (int[]){5, 7, 2, 3}, (int[]){7, 2, 3, 5}, (int[]){7, 2, 5, 3},
                                (int[]){7, 3, 2, 5}, (int[]){7, 3, 5, 2}, (int[]){7, 5, 2, 3}, (int[]){7, 5, 3, 2},
                        },
                        (int[]){4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}, 24};
                actual.data = recursion_permutations(ARRAY_SIZE(A), A, &actual.len, &actual.nr);
                ASSERT_COUNT_EQUAL(actual, expected);

                free(actual.len);
                free_array(actual.data, actual.nr);
        }
        {
                int A[] = {7, 3, 5};
                expected = (int_darray){(int *[]){(int[]){7, 3, 5}, (int[]){7, 5, 3}, (int[]){3, 7, 5},
                                                  (int[]){3, 5, 7}, (int[]){5, 3, 7}, (int[]){5, 7, 3}},
                                        (int[]){3, 3, 3, 3, 3, 3}, 6};
                actual.data = recursion_permutations(ARRAY_SIZE(A), A, &actual.len, &actual.nr);
                ASSERT_COUNT_EQUAL(actual, expected);

                free(actual.len);
                free_array(actual.data, actual.nr);
        }
        {
                int A[] = {1, 2, 3};
                expected = (int_darray){(int *[]){(int[]){1, 2, 3}, (int[]){1, 3, 2}, (int[]){2, 1, 3},
                                                  (int[]){2, 3, 1}, (int[]){3, 1, 2}, (int[]){3, 2, 1}},
                                        (int[]){3, 3, 3, 3, 3, 3}, 6};
                actual.data = recursion_permutations(ARRAY_SIZE(A), A, &actual.len, &actual.nr);
                ASSERT_COUNT_EQUAL(actual, expected);

                free(actual.len);
                free_array(actual.data, actual.nr);
        }
        {
                int A[] = {0, 1};
                expected = (int_darray){(int *[]){(int[]){0, 1}, (int[]){1, 0}}, (int[]){2, 2}, 2};
                actual.data = recursion_permutations(ARRAY_SIZE(A), A, &actual.len, &actual.nr);
                ASSERT_COUNT_EQUAL(actual, expected);

                free(actual.len);
                free_array(actual.data, actual.nr);
        }
        {
                int A[] = {1};
                expected = (int_darray){(int *[]){(int[]){1}}, (int[]){1}, 1};
                actual.data = recursion_permutations(ARRAY_SIZE(A), A, &actual.len, &actual.nr);
                ASSERT_COUNT_EQUAL(actual, expected);

                free(actual.len);
                free_array(actual.data, actual.nr);
        }
}
