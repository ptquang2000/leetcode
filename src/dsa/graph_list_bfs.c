#include "common.h"
#include "utils/utils.h"

extern int *dsa_graph_list_bfs(int size, weighted_adj_list list[size], int source, int needle, int *o_len);

void test_dsa_graph_list_bfs()
{
        {
                int len;
                int *actual = dsa_graph_list_bfs(ARRAY_SIZE(list1), list1, 0, 6, &len);
                int expected[] = {0, 1, 4, 5, 6};
                UTILS_ASSERT_EQUAL(len, ARRAY_SIZE(expected));
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, ARRAY_SIZE(expected));
        }
        {
                int len;
                int *actual = dsa_graph_list_bfs(ARRAY_SIZE(list1), list1, 6, 0, &len);
                int expected[] = {};
                UTILS_ASSERT_EQUAL(len, ARRAY_SIZE(expected));
                UTILS_ASSERT_IS_NONE(actual);
        }
}
