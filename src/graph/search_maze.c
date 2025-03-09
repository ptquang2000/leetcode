#include "utils/utils.h"

extern int **graph_search_maze(int len, int **maze, int s[2], int e[2], int *o_size);

static int **__build_maze(int len, int **maze, int size, int path[size][2])
{
        int **res = calloc(len, sizeof(*res));
        for (size_t i = 0; i < len; i++) {
                res[i] = calloc(len, sizeof(*res[i]));
                for (size_t j = 0; j < len; j++)
                        res[i][j] = maze[i][j];
        }
        for (size_t i = 0; i < size; i++)
                res[path[i][0]][path[i][1]] = 2;

        return res;
}

void test_graph_search_maze()
{
        int *maze[] = {
                (int[]){0, 1, 1, 1, 1, 1, 0, 0, 1, 1}, //
                (int[]){1, 1, 0, 1, 1, 1, 1, 1, 1, 1}, //
                (int[]){0, 1, 0, 1, 1, 0, 0, 1, 0, 0}, //
                (int[]){1, 1, 1, 0, 0, 0, 1, 1, 0, 1}, //
                (int[]){1, 0, 0, 1, 1, 1, 1, 1, 1, 1}, //
                (int[]){1, 0, 0, 1, 1, 0, 1, 0, 0, 1}, //
                (int[]){1, 1, 1, 1, 0, 1, 1, 1, 1, 1}, //
                (int[]){0, 1, 0, 1, 0, 1, 0, 1, 1, 1}, //
                (int[]){0, 1, 0, 0, 1, 1, 1, 0, 0, 0}, //
                (int[]){1, 1, 1, 1, 1, 1, 1, 0, 0, 1}, //
        };
        int maze_size[] = {10, 10, 10, 10, 10, 10, 10, 10, 10};

        int *expected1[] = {
                (int[]){0, 2, 2, 2, 2, 2, 0, 0, 2, 2}, //
                (int[]){1, 2, 0, 1, 1, 2, 2, 2, 2, 1}, //
                (int[]){0, 2, 0, 1, 1, 0, 0, 1, 0, 0}, //
                (int[]){2, 2, 1, 0, 0, 0, 1, 1, 0, 1}, //
                (int[]){2, 0, 0, 1, 1, 1, 1, 1, 1, 1}, //
                (int[]){2, 0, 0, 1, 1, 0, 1, 0, 0, 1}, //
                (int[]){2, 2, 1, 1, 0, 1, 1, 1, 1, 1}, //
                (int[]){0, 2, 0, 1, 0, 1, 0, 1, 1, 1}, //
                (int[]){0, 2, 0, 0, 1, 1, 1, 0, 0, 0}, //
                (int[]){2, 2, 1, 1, 1, 1, 1, 0, 0, 1}, //
        };

        int *expected2[] = {
                (int[]){0, 1, 1, 1, 1, 1, 0, 0, 2, 2}, //
                (int[]){1, 1, 0, 1, 1, 1, 1, 2, 2, 1}, //
                (int[]){0, 1, 0, 1, 1, 0, 0, 2, 0, 0}, //
                (int[]){1, 1, 1, 0, 0, 0, 1, 2, 0, 1}, //
                (int[]){1, 0, 0, 1, 1, 1, 2, 2, 1, 1}, //
                (int[]){1, 0, 0, 1, 1, 0, 2, 0, 0, 1}, //
                (int[]){1, 1, 1, 1, 0, 2, 2, 1, 1, 1}, //
                (int[]){0, 1, 0, 1, 0, 2, 0, 1, 1, 1}, //
                (int[]){0, 1, 0, 0, 1, 2, 1, 0, 0, 0}, //
                (int[]){2, 2, 2, 2, 2, 2, 1, 0, 0, 1}, //
        };

        int s[] = {9, 0};
        int e[] = {0, 9};
        int len;
        int **path = graph_search_maze(10, maze, s, e, &len);
        int **actual = __build_maze(10, maze, len, (int(*)[2])path);
        UTILS_ASSERT_EQUAL_MULTI_DIM_ARRAY(actual, expected1, maze_size, ARRAY_SIZE(maze_size));
        UTILS_ASSERT_EQUAL_MULTI_DIM_ARRAY(actual, expected2, maze_size, ARRAY_SIZE(maze_size));

        free_array(actual, len);
        free_array(path, len);
}
