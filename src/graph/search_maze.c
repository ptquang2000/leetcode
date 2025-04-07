#include "utils/logger.h"

extern int **graph_search_maze(int len, int **maze, int s[2], int e[2], int *o_size);

static int_darray __build_maze(int len, int **maze, int size, int path[size][2])
{
        int_darray res = {};
        res.data = malloc(len * sizeof *res.data);
        res.len = malloc(len * sizeof *res.len);
        res.nr = len;
        for (size_t i = 0; i < len; i++) {
                res.len[i] = len;
                res.data[i] = malloc(len * sizeof *res.data[i]);
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
        int_darray actual = __build_maze(maze.nr, maze.data, path.nr, (int(*)[])path.data);

        struct ADJ {
                int x;
                int y;
        } adjs[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        darray_zip(ai, ar, actual, ei, er, maze)
        {
                int X = ar - actual.data;
                int Y = ai - ar[0];
                if (!ei[0] && ai[0])
                        goto __invalid;
                if (ai[0] != 2)
                        goto __valid;
                for (struct ADJ *i = &adjs[0]; i < &adjs[4]; i++) {
                        int x = X + i[0].x;
                        int y = Y + i[0].y;
                        if (x < 0 || x >= actual.nr)
                                continue;
                        if (y < 0 || y >= actual.nr)
                                continue;
                        if (actual.data[x][y] == 2)
                                goto __valid;
                }
        __invalid:
                UTILS_LOG("Invalid path at path[{}][{}]={}, {}, {} for maze {}", (int_obj){X}, (int_obj){Y},
                          (int_obj){ai[0]}, actual, maze);
                __builtin_trap();
        __valid:
                continue;
        }

        free(path.data);
        free(actual.len);
        free_array(actual.data, actual.nr);
}
