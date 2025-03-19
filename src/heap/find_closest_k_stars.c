#include "utils/asserts.h"

extern int **heap_find_closest_k_stars(int size, int *stars[size], int k);

void test_heap_find_closest_k_stars()
{
        {
                int *stars[] = {
                        (int[]){1, 3},
                        (int[]){-2, 2},
                };
                int k = 1;
                int *expected[] = {
                        (int[]){-2, 2},
                };
                int **actual = heap_find_closest_k_stars(ARRAY_SIZE(stars), stars, k);
                ASSERT_EQUAL(actual[0], expected[0], 2);
                free_array(actual, k);
        }
        {
                int *stars[] = {
                        (int[]){3, 3},
                        (int[]){5, -1},
                        (int[]){-2, 4},
                };
                int k = 2;
                int *expected[] = {
                        (int[]){-2, 4},
                        (int[]){3, 3},
                };
                int **actual = heap_find_closest_k_stars(ARRAY_SIZE(stars), stars, k);
                ASSERT_EQUAL(actual[0], expected[0], 2);
                ASSERT_EQUAL(actual[1], expected[1], 2);
                free_array(actual, k);
        }
        {
                int *stars[] = {
                        (int[]){1, 3}, (int[]){-2, 2}, (int[]){5, -1}, (int[]){3, 2}, (int[]){1, 1},
                };
                int k = 3;
                int *expected[] = {
                        (int[]){1, 3},
                        (int[]){-2, 2},
                        (int[]){1, 1},
                };
                int **actual = heap_find_closest_k_stars(ARRAY_SIZE(stars), stars, k);
                ASSERT_EQUAL(actual[0], expected[0], 2);
                ASSERT_EQUAL(actual[1], expected[1], 2);
                ASSERT_EQUAL(actual[2], expected[2], 2);
                free_array(actual, k);
        }
        {
                int *stars[] = {
                        (int[]){2, 4},
                        (int[]){-1, -1},
                        (int[]){0, 0},
                };
                int k = 1;
                int *expected[] = {
                        (int[]){0, 0},
                };
                int **actual = heap_find_closest_k_stars(ARRAY_SIZE(stars), stars, k);
                ASSERT_EQUAL(actual[0], expected[0], 2);
                free_array(actual, k);
        }
}
