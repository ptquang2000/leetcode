#include "utils/asserts.h"

extern int **graph_search_maze(int len, int **maze, int s[2], int e[2], int *o_size);

static int_darray __build_maze(int len, int **maze, int size, int path[size][2])
{
        int_darray res = {};
        res.data = calloc(len, sizeof *res.data);
        res.len = calloc(len, sizeof *res.len);
        for (size_t i = 0; i < len; i++) {
                res.len[i] = len;
                res.data[i] = calloc(len, sizeof *res.data[i]);
                for (size_t j = 0; j < len; j++)
                        res.data[i][j] = maze[i][j];
        }

        for (size_t i = 0; i < size; i++)
                res.data[path[i][0]][path[i][1]] = 2;
        return res;
}

void test_graph_search_maze()
{
        int_darray maze = {(int *[]){
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
                           },
                           (int[]){10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, 10};

        int_darray expected1 = {(int *[]){
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
                                },
                                (int[]){10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, 10};

        int_darray expected2 = {(int *[]){
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
                                },
                                (int[]){10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, 10};

        int_darray path = {.data = graph_search_maze(maze.nr, maze.data, (int[]){9, 0}, (int[]){0, 9}, &path.nr)};
        int_darray actual = __build_maze(maze.nr, maze.data, path.nr, (int(*)[2])path.data);
        _Container expected = {.data = (void *[]){&expected1, &expected2}, .len = 2};
        ASSERT_IN(actual, expected);

        free(actual.len);
        free_array(actual.data, actual.nr);
        free(path.len);
        free_array(path.data, path.nr);
}
