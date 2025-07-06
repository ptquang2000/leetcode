#include "utils/asserts.h"

extern int bitwise_single_number_2(int len, int nums[len]);

void test_bitwise_single_number_2()
{
        int_obj actual = {}, expected = {};

        actual.data = bitwise_single_number_2(4, (int[]){2, 2, 3, 2});
        expected.data = 3;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_single_number_2(7, (int[]){0, 1, 0, 1, 0, 1, 99});
        expected.data = 99;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_single_number_2(10, (int[]){-2, -2, 1, 1, -3, 1, -3, -3, -4, -2});
        expected.data = -4;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_single_number_2(4, (int[]){300, 300, 300, -1000});
        expected.data = -1000;
        ASSERT_EQUAL(actual, expected);
}
