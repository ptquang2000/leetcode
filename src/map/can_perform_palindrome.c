#include "utils/asserts.h"

extern bool map_can_perform_paldinrome(const char *s);

void test_map_can_perform_palindrome()
{
        ASSERT_FALSE(map_can_perform_paldinrome("travel"));
        ASSERT_TRUE(map_can_perform_paldinrome("deified"));

        ASSERT_TRUE(map_can_perform_paldinrome(""));
        ASSERT_TRUE(map_can_perform_paldinrome("a"));
        ASSERT_TRUE(map_can_perform_paldinrome("aabb"));
        ASSERT_TRUE(map_can_perform_paldinrome("aabbc"));
        ASSERT_FALSE(map_can_perform_paldinrome("abc"));
        ASSERT_TRUE(map_can_perform_paldinrome("aaaaaa"));
        ASSERT_FALSE(map_can_perform_paldinrome("AaBb"));
        ASSERT_TRUE(map_can_perform_paldinrome("taco cat"));
        ASSERT_TRUE(map_can_perform_paldinrome("@@##!!@@##!!"));
}
