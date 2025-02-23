#include "common.h"
#include "utils/utils.h"

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

        const char *expected[] = {
                "xxxxxxxxxx*x", 
                "x        x*x", 
                "x        x*x",
                "x xxxxxxxx*x",
                "x**********x",
                "x*xxxxxxxxxx",
        };

        char **actual = calloc(6, sizeof(*actual));
        for (size_t i = 0; i < 6; i++) {
                actual[i] = calloc(14, sizeof(**actual));
                strcpy(actual[i], maze[i]);
                actual[i][13] = 0;
        }
        for (size_t i = 0; i < len; i++)
                actual[path[i].y][path[i].x] = '*';

        UTILS_ASSERT_EQUAL_ARRAY((const char**)actual, expected, ARRAY_SIZE(expected));
        free(path);
        free_array(actual, 6);
}
