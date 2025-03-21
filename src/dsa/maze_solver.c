#include "common.h"
#include "utils/asserts.h"

extern struct dsa_point *dsa_solve(int row_size, int col_size, const char **maze, char wall, struct dsa_point start,
                                   struct dsa_point end, int *o_len);

void test_dsa_solve()
{
        char *maze[] = {
                "xxxxxxxxxx x", 
                "x        x x", 
                "x        x x",
                "x xxxxxxxx x",
                "x          x",
                "x xxxxxxxxxx",
        };

        int len;
        struct dsa_point *path = dsa_solve(6, 13, (const char **)maze, 'x', (struct dsa_point){.x = 10, .y = 0},
                                             (struct dsa_point){.x = 1, .y = 5}, &len);

        string_array expected = {(char*[]){
                "xxxxxxxxxx*x", 
                "x        x*x", 
                "x        x*x",
                "x xxxxxxxx*x",
                "x**********x",
                "x*xxxxxxxxxx",
        }, 6};

        string_array actual = {calloc(6, sizeof(*actual.data)), 6};
        for (size_t i = 0; i < 6; i++) {
                actual.data[i] = calloc(14, sizeof(**actual.data));
                strcpy(actual.data[i], maze[i]);
                actual.data[i][13] = 0;
        }
        for (size_t i = 0; i < len; i++)
                actual.data[path[i].y][path[i].x] = '*';

        ASSERT_EQUAL(actual, expected);
        free(path);
        free_array(actual.data, 6);
}
