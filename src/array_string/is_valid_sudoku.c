#include "utils/asserts.h"

extern bool array_string_isValidSudoku(int *partialAssignment[], int size);

void test_array_string_isValidSudoku()
{
        {
                int_darray partialSudoku = {(int *[]){
                                                    (int[]){5, 3, 0, 0, 7, 0, 0, 0, 0},
                                                    (int[]){6, 0, 0, 1, 9, 5, 0, 0, 0},
                                                    (int[]){0, 9, 8, 0, 0, 0, 0, 6, 0},
                                                    (int[]){8, 0, 0, 0, 6, 0, 0, 0, 3},
                                                    (int[]){4, 0, 0, 8, 0, 3, 0, 0, 1},
                                                    (int[]){7, 0, 0, 0, 2, 0, 0, 0, 6},
                                                    (int[]){0, 6, 0, 0, 0, 0, 2, 8, 0},
                                                    (int[]){0, 0, 0, 4, 1, 9, 0, 0, 5},
                                                    (int[]){0, 0, 0, 0, 8, 0, 0, 7, 9},
                                            },
                                            (int[]){9, 9, 9, 9, 9, 9, 9, 9, 9}, 9};
                ASSERT_FALSE(array_string_isValidSudoku(partialSudoku.data, partialSudoku.nr));
        }
        {
                int_darray completedSudoku = {(int *[]){
                                                      (int[]){5, 3, 4, 6, 7, 8, 9, 1, 2},
                                                      (int[]){6, 7, 2, 1, 9, 5, 3, 4, 8},
                                                      (int[]){1, 9, 8, 3, 4, 2, 5, 6, 7},
                                                      (int[]){8, 5, 9, 7, 6, 1, 4, 2, 3},
                                                      (int[]){4, 2, 6, 8, 5, 3, 7, 9, 1},
                                                      (int[]){7, 1, 3, 9, 2, 4, 8, 5, 6},
                                                      (int[]){9, 6, 1, 5, 3, 7, 2, 8, 4},
                                                      (int[]){2, 8, 7, 4, 1, 9, 6, 3, 5},
                                                      (int[]){3, 4, 5, 2, 8, 6, 1, 7, 9},
                                              },
                                              (int[]){9, 9, 9, 9, 9, 9, 9, 9, 9}, 9};
                ASSERT_TRUE(array_string_isValidSudoku(completedSudoku.data, completedSudoku.nr));
        }
        {
                int_darray completedSudoku = {(int *[]){
                                                      (int[]){5, 3, 4, 6, 7, 8, 9, 1, 2},
                                                      (int[]){6, 7, 2, 1, 9, 5, 3, 4, 8},
                                                      (int[]){1, 9, 8, 3, 4, 2, 5, 6, 7},
                                                      (int[]){8, 5, 9, 7, 6, 1, 4, 2, 3},
                                                      (int[]){4, 2, 6, 8, 5, 3, 7, 9, 1},
                                                      (int[]){7, 1, 3, 9, 2, 4, 8, 5, 6},
                                                      (int[]){9, 6, 1, 5, 3, 7, 2, 1, 4},
                                                      (int[]){2, 8, 7, 4, 1, 9, 6, 3, 5},
                                                      (int[]){3, 4, 5, 2, 8, 6, 1, 7, 9},
                                              },
                                              (int[]){9, 9, 9, 9, 9, 9, 9, 9, 9}, 9};
                ASSERT_FALSE(array_string_isValidSudoku(completedSudoku.data, completedSudoku.nr));
        }
}
