#include "utils/asserts.h"

extern int bitwise_range_bitwise_and(int left, int right);

void test_bitwise_range_bitwise_and()
{
        int_obj actual = {}, expected = {};

        actual.data = bitwise_range_bitwise_and(5, 7);
        expected.data = 4;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_range_bitwise_and(0, 0);
        expected.data = 0;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_range_bitwise_and(1, 2147483647);
        expected.data = 0;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_range_bitwise_and(12, 12);
        expected.data = 12;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_range_bitwise_and(8, 15);
        expected.data = 8;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_range_bitwise_and(600, 1023);
        expected.data = 0;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_range_bitwise_and(1024, 2047);
        expected.data = 1024;
        ASSERT_EQUAL(actual, expected);
}
