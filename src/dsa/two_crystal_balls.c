#include "utils/asserts.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

extern int dsa_two_crystal_balls(int size, bool breaks[size]);

void test_dsa_two_crystal_balls()
{
        srand(time(NULL));
        int idx = rand() / ((RAND_MAX + 1u) / 10000);
        bool data[10000] = {};

        for (size_t i = idx; i < 10000; i++)
                data[i] = true;

        ASSERT_EQUAL((int_obj){dsa_two_crystal_balls(ARRAY_SIZE(data), data)}, (int_obj){idx});

        bool foo[821] = {};
        ASSERT_EQUAL((int_obj){dsa_two_crystal_balls(ARRAY_SIZE(foo), foo)}, (int_obj){-1});
}
