import unittest
from test import (
    add_binary,
    hamming_weight,
    range_bitwise_and,
    reverse_bits,
    single_number,
    single_number_2,
)


class TestBitwise(unittest.TestCase):
    def test_add_binary(self):
        self.assertEqual(add_binary('11', '1'), '100')
        self.assertEqual(add_binary('1010', '1011'), '10101')
        self.assertEqual(add_binary('0', '0'), '0')
        self.assertEqual(add_binary('1111', '1111'), '11110')

    def test_hamming_weight(self):
        self.assertEqual(hamming_weight(11), 3)
        self.assertEqual(hamming_weight(128), 1)
        self.assertEqual(hamming_weight(2147483645), 30)
        self.assertEqual(hamming_weight(0), 0)
        self.assertEqual(hamming_weight(1), 1)
        self.assertEqual(hamming_weight(0xFFFFFFFF), 32)

    def test_range_bitwise_and(self):
        self.assertEqual(range_bitwise_and(5, 7), 4)
        self.assertEqual(range_bitwise_and(0, 0), 0)
        self.assertEqual(range_bitwise_and(1, 2147483647), 0)
        self.assertEqual(range_bitwise_and(12, 12), 12)
        self.assertEqual(range_bitwise_and(8, 15), 8)
        self.assertEqual(range_bitwise_and(600, 1023), 512)
        self.assertEqual(range_bitwise_and(1024, 2047), 1024)

    def test_reverse_bits(self):
        self.assertEqual(reverse_bits(0b00000010100101000001111010011100), 0b00111001011110000010100101000000)
        self.assertEqual(reverse_bits(0b11111111111111111111111111111101), 0b10111111111111111111111111111111)
        self.assertEqual(reverse_bits(0), 0)
        self.assertEqual(reverse_bits(4294967295), 4294967295)
        self.assertEqual(reverse_bits(1), 2147483648)
        self.assertEqual(reverse_bits(2147483648), 1)
        self.assertEqual(reverse_bits(1431655765), 2863311530)
        self.assertEqual(reverse_bits(2863311530), 1431655765)

    def test_single_number(self):
        self.assertEqual(single_number([1]), 1)
        self.assertEqual(single_number([4, 1, 2, 1, 2]), 4)
        self.assertEqual(single_number([2, 2, 1]), 1)
        self.assertEqual(single_number([0, 0, 7]), 7)

    def test_single_number_2(self):
        self.assertEqual(single_number_2([2, 2, 3, 2]), 3)
        self.assertEqual(single_number_2([0, 1, 0, 1, 0, 1, 99]), 99)
        self.assertEqual(single_number_2([-2, -2, 1, 1, -3, 1, -3, -3, -4, -2]), -4)
        self.assertEqual(single_number_2([300, 300, 300, -1000]), -1000)
