#include "utils/asserts.h"

extern void graph_filled_surrounded_region(int n, int m, int **actual);

void test_graph_filled_surrounded_region()
{
        {
                int_darray actual = {
                        .data =
                                (int *[]){
                                        (int[]){'B', 'B', 'B', 'B'},
                                        (int[]){'W', 'B', 'W', 'B'},
                                        (int[]){'B', 'W', 'W', 'B'},
                                        (int[]){'B', 'B', 'B', 'B'},
                                },
                        .len = (int[]){4, 4, 4, 4},
                        .nr = 4,
                };
                int_darray expected = {
                        .data =
                                (int *[]){
                                        (int[]){'B', 'B', 'B', 'B'},
                                        (int[]){'W', 'B', 'B', 'B'},
                                        (int[]){'B', 'B', 'B', 'B'},
                                        (int[]){'B', 'B', 'B', 'B'},
                                },
                        .len = (int[]){4, 4, 4, 4},
                        .nr = 4,
                };
                graph_filled_surrounded_region(actual.nr, actual.nr, actual.data);
                ASSERT_EQUAL(actual, expected);
        }
        {
                int_darray actual = {
                        .data =
                                (int *[]){
                                        (int[]){'B', 'B', 'B', 'B'},
                                        (int[]){'B', 'W', 'W', 'B'},
                                        (int[]){'B', 'B', 'W', 'B'},
                                        (int[]){'B', 'W', 'B', 'B'},
                                },
                        .len = (int[]){4, 4, 4, 4},
                        .nr = 4,
                };
                int_darray expected = {
                        .data =
                                (int *[]){
                                        (int[]){'B', 'B', 'B', 'B'},
                                        (int[]){'B', 'B', 'B', 'B'},
                                        (int[]){'B', 'B', 'B', 'B'},
                                        (int[]){'B', 'W', 'B', 'B'},
                                },
                        .len = (int[]){4, 4, 4, 4},
                        .nr = 4,
                };
                graph_filled_surrounded_region(actual.nr, actual.nr, actual.data);
                ASSERT_EQUAL(actual, expected);
        }
        {
                int_darray actual = {
                        .data =
                                (int *[]){
                                        (int[]){'B'},
                                },
                        .len = (int[]){1},
                        .nr = 1,
                };
                int_darray expected = {
                        .data =
                                (int *[]){
                                        (int[]){'B'},
                                },
                        .len = (int[]){1},
                        .nr = 1,
                };
                graph_filled_surrounded_region(actual.nr, actual.nr, actual.data);
                ASSERT_EQUAL(actual, expected);
        }
}
