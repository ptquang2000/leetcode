#include "common.h"

extern int *dsa_dijkstra_list(int source, int sink, int size, weighted_adj_list list[size], int *o_len);

void test_dsa_dijkstra_list()
{
        int len;
        int *actual = dsa_dijkstra_list(0, 6, ARRAY_SIZE(list1), list1, &len);
        int expected[] = {0, 1, 4, 5, 6};
        UTILS_ASSERT_EQUAL(len, ARRAY_SIZE(expected));
        UTILS_ASSERT_EQUAL_ARRAY(actual, expected, ARRAY_SIZE(expected));
}
