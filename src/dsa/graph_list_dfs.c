#include "common.h"
#include "utils/asserts.h"

extern int *dsa_graph_list_dfs(int len, int size[len], weighted_adj_list list[len], int source, int needle, int *o_len);

void test_dsa_graph_list_dfs()
{
        {
                int len;
                int *actual = dsa_graph_list_dfs(ARRAY_SIZE(list2), list2_len, list2, 0, 6, &len);
                int expected[] = {0, 1, 4, 5, 6};
                ASSERT_EQUAL(len, ARRAY_SIZE(expected));
                ASSERT_EQUAL(actual, expected, ARRAY_SIZE(expected));
        }
        {
                int len;
                int *actual = dsa_graph_list_dfs(ARRAY_SIZE(list2), list2_len, list2, 6, 0, &len);
                int expected[] = {};
                ASSERT_EQUAL(len, ARRAY_SIZE(expected));
                UTILS_ASSERT_IS_NONE(actual);
        }
}
