#include "utils/utils.h"
#include <stdbool.h>

extern bool dsa_linear_search(int size, int haystack[size], int needle);

void test_dsa_linear_search()
{
        int foo[] = {1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};
        UTILS_ASSERT_TRUE(dsa_linear_search(ARRAY_SIZE(foo), foo, 69));
        UTILS_ASSERT_FALSE(dsa_linear_search(ARRAY_SIZE(foo), foo, 1336));
        UTILS_ASSERT_TRUE(dsa_linear_search(ARRAY_SIZE(foo), foo, 69420));
        UTILS_ASSERT_FALSE(dsa_linear_search(ARRAY_SIZE(foo), foo, 69421));
        UTILS_ASSERT_TRUE(dsa_linear_search(ARRAY_SIZE(foo), foo, 1));
        UTILS_ASSERT_FALSE(dsa_linear_search(ARRAY_SIZE(foo), foo, 0));
}
