#include "utils/asserts.h"

extern bool map_test_collatz_conjecture(int n);

void test_map_test_collatz_conjecture()
{
        ASSERT_TRUE(map_test_collatz_conjecture(1));
        ASSERT_TRUE(map_test_collatz_conjecture(2));
        ASSERT_TRUE(map_test_collatz_conjecture(3));
        ASSERT_TRUE(map_test_collatz_conjecture(27));
        ASSERT_TRUE(map_test_collatz_conjecture(64));
        ASSERT_TRUE(map_test_collatz_conjecture(1000000));
        ASSERT_FALSE(map_test_collatz_conjecture(0));
        ASSERT_FALSE(map_test_collatz_conjecture(-5));
        ASSERT_TRUE(map_test_collatz_conjecture(10'000'000));
}
