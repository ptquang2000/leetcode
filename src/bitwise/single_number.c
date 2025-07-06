#include "utils/asserts.h"

extern int bitwise_single_number(int len, int nums[len]);

void test_bitwise_single_number()
{
        int_obj actual = {}, expected = {};

        actual.data = bitwise_single_number(1, (int[]){1});
        expected.data = 1;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_single_number(5, (int[]){4, 1, 2, 1, 2});
        expected.data = 4;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_single_number(3, (int[]){2, 2, 1});
        expected.data = 1;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_single_number(3, (int[]){0, 0, 7});
        expected.data = 7;
        ASSERT_EQUAL(actual, expected);
}
