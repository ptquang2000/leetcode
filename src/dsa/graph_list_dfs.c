#include "common.h"
#include "utils/asserts.h"

extern int *dsa_graph_list_dfs(int len, int size[len], weighted_adj_list list[len], int source, int needle, int *o_len);

void test_dsa_graph_list_dfs()
{
        {
                int_array actual = {dsa_graph_list_dfs(ARRAY_SIZE(list2), list2_len, list2, 0, 6, &actual.len)};
                int_array expected = {(int[]){0, 1, 4, 5, 6}, 5};
                ASSERT_EQUAL(actual, expected);
        }
        {
                int_array actual = {dsa_graph_list_dfs(ARRAY_SIZE(list2), list2_len, list2, 6, 0, &actual.len)};
                int_array expected = {(int[]){}, 0};
                ASSERT_IS_NULL(actual);
        }
}
