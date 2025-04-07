#include "utils/asserts.h"

extern void graph_filled_surrounded_region(int m, int n, char **board);

void test_graph_filled_surrounded_region()
{
        {
                char_darray actual = {
                        .data =
                                (char *[]){
                                        (char[]){'B', 'B', 'B', 'B'},
                                        (char[]){'W', 'B', 'W', 'B'},
                                        (char[]){'B', 'W', 'W', 'B'},
                                        (char[]){'B', 'B', 'B', 'B'},
                                },
                        .len = (int[]){4, 4, 4, 4},
                        .nr = 4,
                };
                char_darray expected = {
                        .data =
                                (char *[]){
                                        (char[]){'B', 'B', 'B', 'B'},
                                        (char[]){'W', 'B', 'B', 'B'},
                                        (char[]){'B', 'B', 'B', 'B'},
                                        (char[]){'B', 'B', 'B', 'B'},
                                },
                        .len = (int[]){4, 4, 4, 4},
                        .nr = 4,
                };
                graph_filled_surrounded_region(actual.nr, actual.nr, actual.data);
                ASSERT_EQUAL(actual, expected);
        }
        {
                char_darray actual = {
                        .data =
                                (char *[]){
                                        (char[]){'B', 'B', 'B', 'B'},
                                        (char[]){'B', 'W', 'W', 'B'},
                                        (char[]){'B', 'B', 'W', 'B'},
                                        (char[]){'B', 'W', 'B', 'B'},
                                },
                        .len = (int[]){4, 4, 4, 4},
                        .nr = 4,
                };
                char_darray expected = {
                        .data =
                                (char *[]){
                                        (char[]){'B', 'B', 'B', 'B'},
                                        (char[]){'B', 'B', 'B', 'B'},
                                        (char[]){'B', 'B', 'B', 'B'},
                                        (char[]){'B', 'W', 'B', 'B'},
                                },
                        .len = (int[]){4, 4, 4, 4},
                        .nr = 4,
                };
                graph_filled_surrounded_region(actual.nr, actual.nr, actual.data);
                ASSERT_EQUAL(actual, expected);
        }
        {
                char_darray actual = {
                        .data =
                                (char *[]){
                                        (char[]){'B'},
                                },
                        .len = (int[]){1},
                        .nr = 1,
                };
                char_darray expected = {
                        .data =
                                (char *[]){
                                        (char[]){'B'},
                                },
                        .len = (int[]){1},
                        .nr = 1,
                };
                graph_filled_surrounded_region(actual.nr, actual.nr, actual.data);
                ASSERT_EQUAL(actual, expected);
        }
}
