#include "utils/asserts.h"

extern int **heap_find_closest_k_stars(int size, int *stars[size], int k);

void test_heap_find_closest_k_stars()
{
        int_darray actual = {}, expected = {};
        {
                int *stars[] = {
                        (int[]){1, 3},
                        (int[]){-2, 2},
                };
                expected = (int_darray){(int *[]){
                                                (int[]){-2, 2},
                                        },
                                        (int[]){2}, 1};
                actual = (int_darray){heap_find_closest_k_stars(ARRAY_SIZE(stars), stars, expected.nr), expected.len,
                                      expected.nr};
                ASSERT_EQUAL(actual, expected);
                free_array(actual.data, actual.nr);
        }
        {
                int *stars[] = {
                        (int[]){3, 3},
                        (int[]){5, -1},
                        (int[]){-2, 4},
                };
                expected = (int_darray){(int *[]){
                                                (int[]){-2, 4},
                                                (int[]){3, 3},
                                        },
                                        (int[]){2, 2}, 2};
                actual = (int_darray){heap_find_closest_k_stars(ARRAY_SIZE(stars), stars, expected.nr), expected.len,
                                      expected.nr};
                ASSERT_EQUAL(actual, expected);
                free_array(actual.data, actual.nr);
        }
        {
                int *stars[] = {
                        (int[]){1, 3}, (int[]){-2, 2}, (int[]){5, -1}, (int[]){3, 2}, (int[]){1, 1},
                };
                expected = (int_darray){(int *[]){
                                                (int[]){1, 3},
                                                (int[]){-2, 2},
                                                (int[]){1, 1},
                                        },
                                        (int[]){2, 2, 2}, 3};
                actual = (int_darray){heap_find_closest_k_stars(ARRAY_SIZE(stars), stars, expected.nr), expected.len,
                                      expected.nr};
                ASSERT_EQUAL(actual, expected);
                free_array(actual.data, actual.nr);
        }
        {
                int *stars[] = {
                        (int[]){2, 4},
                        (int[]){-1, -1},
                        (int[]){0, 0},
                };
                expected = (int_darray){(int *[]){
                                                (int[]){0, 0},
                                        },
                                        (int[]){2}, 1};
                actual = (int_darray){heap_find_closest_k_stars(ARRAY_SIZE(stars), stars, expected.nr), expected.len,
                                      expected.nr};
                ASSERT_EQUAL(actual, expected);
                free_array(actual.data, actual.nr);
        }
}
