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
        struct dsa_point *actual = dsa_solve(6, 13, (const char **)maze, 'x', (struct dsa_point){.x = 10, .y = 0},
                                             (struct dsa_point){.x = 1, .y = 5}, &len);

        const char *expected[] = {
                "xxxxxxxxxx*x", 
                "x        x*x", 
                "x        x*x",
                "x xxxxxxxx*x",
                "x**********x",
                "x*xxxxxxxxxx",
        };

        for (size_t i = 0; i < len; i++)
                maze[actual[i].y][actual[i].x] = '*';

        UTILS_ASSERT_EQUAL_ARRAY((const char**)maze, expected, ARRAY_SIZE(expected));
}
