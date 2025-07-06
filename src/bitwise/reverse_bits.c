#include "utils/asserts.h"

extern uint32_t bitwise_reverse_bits(uint32_t b);

void test_bitwise_reverse_bits()
{
        size_t_obj actual = {}, expected = {};

        actual.data = bitwise_reverse_bits(0b00000010100101000001111010011100);
        expected.data = 0b00111001011110000010100101000000;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_reverse_bits(0b11111111111111111111111111111101);
        expected.data = 0b10111111111111111111111111111111;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_reverse_bits(0);
        expected.data = 0;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_reverse_bits(4294967295);
        expected.data = 4294967295;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_reverse_bits(1);
        expected.data = 2147483648;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_reverse_bits(2147483648);
        expected.data = 1;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_reverse_bits(1431655765);
        expected.data = 1431655765;
        ASSERT_EQUAL(actual, expected);

        actual.data = bitwise_reverse_bits(2863311530);
        expected.data = 1431655765;
        ASSERT_EQUAL(actual, expected);
}
