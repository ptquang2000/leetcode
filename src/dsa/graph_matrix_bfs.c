#include "common.h"
#include "utils/utils.h"

extern int *dsa_graph_matrix_bfs(int size, weighted_adj_matrix matrix[size], int source, int needle, int *o_len);

void test_dsa_graph_matrix_bfs()
{
        {
                int len;
                int *actual = dsa_graph_matrix_bfs(ARRAY_SIZE(matrix2), matrix2, 0, 6, &len);
                int expected[] = {0, 1, 4, 5, 6};
                UTILS_ASSERT_EQUAL(len, ARRAY_SIZE(expected));
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, ARRAY_SIZE(expected));
        }
        {
                int len;
                int *actual = dsa_graph_matrix_bfs(ARRAY_SIZE(matrix2), matrix2, 6, 0, &len);
                int expected[] = {};
                UTILS_ASSERT_EQUAL(len, ARRAY_SIZE(expected));
                UTILS_ASSERT_IS_NONE(actual);
        }
}
