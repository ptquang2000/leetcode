#include "common.h"

extern int *dsa_dijkstra_list(int source, int sink, int len, int size[len], weighted_adj_list list[len], int *o_len);

void test_dsa_dijkstra_list()
{
        int len;
        int *actual = dsa_dijkstra_list(0, 6, ARRAY_SIZE(list1), list1_len, list1, &len);
        int expected[] = {0, 1, 4, 5, 6};
        ASSERT_EQUAL(len, ARRAY_SIZE(expected));
        ASSERT_EQUAL(actual, expected, ARRAY_SIZE(expected));
}
