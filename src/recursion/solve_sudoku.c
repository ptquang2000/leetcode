#include "utils/utils.h"

#include <stdbool.h>

extern bool recursion_solve_sudoku(int size, int* partialAssignment[size]);

void test_recursion_solve_sudoku()
{
        int* partial_assigment[] = {
                (int[]){5, 3, 0, 0, 7, 0, 0, 0, 0}, (int[]){6, 0, 0, 1, 9, 5, 0, 0, 0},
                (int[]){0, 9, 8, 0, 0, 0, 0, 6, 0}, (int[]){8, 0, 0, 0, 6, 0, 0, 0, 3},
                (int[]){4, 0, 0, 8, 0, 3, 0, 0, 1}, (int[]){7, 0, 0, 0, 2, 0, 0, 0, 6},
                (int[]){0, 6, 0, 0, 0, 0, 2, 8, 0}, (int[]){0, 0, 0, 4, 1, 9, 0, 0, 5},
                (int[]){0, 0, 0, 0, 8, 0, 0, 7, 9},
        };
        int* completed[] = {
                (int[]){5, 3, 4, 6, 7, 8, 9, 1, 2}, (int[]){6, 7, 2, 1, 9, 5, 3, 4, 8},
                (int[]){1, 9, 8, 3, 4, 2, 5, 6, 7}, (int[]){8, 5, 9, 7, 6, 1, 4, 2, 3},
                (int[]){4, 2, 6, 8, 5, 3, 7, 9, 1}, (int[]){7, 1, 3, 9, 2, 4, 8, 5, 6},
                (int[]){9, 6, 1, 5, 3, 7, 2, 8, 4}, (int[]){2, 8, 7, 4, 1, 9, 6, 3, 5},
                (int[]){3, 4, 5, 2, 8, 6, 1, 7, 9},
        };
        UTILS_ASSERT_TRUE(recursion_solve_sudoku(ARRAY_SIZE(partial_assigment), partial_assigment));
        UTILS_ASSERT_EQUAL_ARRAY(partial_assigment[0], completed[0], ARRAY_SIZE(partial_assigment));
        UTILS_ASSERT_EQUAL_ARRAY(partial_assigment[1], completed[1], ARRAY_SIZE(partial_assigment));
        UTILS_ASSERT_EQUAL_ARRAY(partial_assigment[2], completed[2], ARRAY_SIZE(partial_assigment));
        UTILS_ASSERT_EQUAL_ARRAY(partial_assigment[3], completed[3], ARRAY_SIZE(partial_assigment));
        UTILS_ASSERT_EQUAL_ARRAY(partial_assigment[4], completed[4], ARRAY_SIZE(partial_assigment));
        UTILS_ASSERT_EQUAL_ARRAY(partial_assigment[5], completed[5], ARRAY_SIZE(partial_assigment));
        UTILS_ASSERT_EQUAL_ARRAY(partial_assigment[6], completed[6], ARRAY_SIZE(partial_assigment));
        UTILS_ASSERT_EQUAL_ARRAY(partial_assigment[7], completed[7], ARRAY_SIZE(partial_assigment));
        UTILS_ASSERT_EQUAL_ARRAY(partial_assigment[8], completed[8], ARRAY_SIZE(partial_assigment));
}
