#include "common.h"
#include "utils/asserts.h"

extern int *dsa_graph_matrix_bfs(int size, weighted_adj_matrix matrix[size], int source, int needle, int *o_len);

void test_dsa_graph_matrix_bfs()
{
        {
                int_array actual = {dsa_graph_matrix_bfs(ARRAY_SIZE(matrix2), matrix2, 0, 6, &actual.len)};
                int_array expected = {(int[]){0, 1, 4, 5, 6}, 5};
                ASSERT_EQUAL(actual, expected);
        }
        {
                int_array actual = {dsa_graph_matrix_bfs(ARRAY_SIZE(matrix2), matrix2, 6, 0, &actual.len)};
                int_array expected = {(int[]){}, 0};
                ASSERT_IS_NULL(actual);
        }
}
