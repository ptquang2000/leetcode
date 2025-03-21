#include "common.h"
#include "utils/asserts.h"

extern int *dsa_dijkstra_list(int source, int sink, int len, int size[len], weighted_adj_list list[len], int *o_len);

void test_dsa_dijkstra_list()
{
        int_array actual = {dsa_dijkstra_list(0, 6, ARRAY_SIZE(list1), list1_len, list1, &actual.len)};
        int_array expected = {(int[]){0, 1, 4, 5, 6}, 5};
        ASSERT_EQUAL(actual, expected);
}
