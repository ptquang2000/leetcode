#include "utils/asserts.h"

extern char *bitwise_add_binary(const char *a, const char *b);

void test_bitwise_add_binary()
{
        string_obj actual = {}, expected = {};

        actual.data = bitwise_add_binary("11", "1");
        expected.data = "100";
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        actual.data = bitwise_add_binary("1010", "1011");
        expected.data = "10101";
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        actual.data = bitwise_add_binary("0", "0");
        expected.data = "0";
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        actual.data = bitwise_add_binary("1111", "1111");
        expected.data = "11110";
        ASSERT_EQUAL(actual, expected);
        free(actual.data);
}
