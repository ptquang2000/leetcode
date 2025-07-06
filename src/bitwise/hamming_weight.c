#include "utils/asserts.h"

extern int bitwise_hamming_weight(int n);

void test_bitwise_hamming_weight()
{
        int_obj actual = {}, expected = {};

        actual.data = bitwise_hamming_weight(11);
        expected.data = 3;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_hamming_weight(128);
        expected.data = 1;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_hamming_weight(2147483645);
        expected.data = 30;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_hamming_weight(0);
        expected.data = 0;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_hamming_weight(1);
        expected.data = 1;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_hamming_weight(0xFFFFFFFF);
        expected.data = 32;
        ASSERT_EQUAL(actual, expected);
}
