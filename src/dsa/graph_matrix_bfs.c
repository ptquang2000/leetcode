#include "common.h"
#include "utils/asserts.h"

extern int *dsa_graph_matrix_bfs(int size, weighted_adj_matrix matrix[size], int source, int needle, int *o_len);

void test_dsa_graph_matrix_bfs()
{
        {
                int len;
                int *actual = dsa_graph_matrix_bfs(ARRAY_SIZE(matrix2), matrix2, 0, 6, &len);
                int expected[] = {0, 1, 4, 5, 6};
                ASSERT_EQUAL(len, ARRAY_SIZE(expected));
                ASSERT_EQUAL(actual, expected, ARRAY_SIZE(expected));
        }
        {
                int len;
                int *actual = dsa_graph_matrix_bfs(ARRAY_SIZE(matrix2), matrix2, 6, 0, &len);
                int expected[] = {};
                ASSERT_EQUAL(len, ARRAY_SIZE(expected));
                ASSERT_IS_NULL(actual);
        }
}
