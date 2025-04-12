#include "utils/asserts.h"

extern bool map_can_perform_paldinrome(const char *s);

void test_map_can_perform_palindrome()
{
        ASSERT_TRUE(map_can_perform_paldinrome("mmo"));
        ASSERT_TRUE(map_can_perform_paldinrome("yakak"));
        ASSERT_FALSE(map_can_perform_paldinrome("travel"));
        ASSERT_TRUE(map_can_perform_paldinrome("deified"));
}
