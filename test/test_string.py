import unittest
from test import (
    convert_base,
    int_to_string,
    is_palindrome,
    look_and_say,
    rabin_karp,
    replace_and_remove,
    reverse_words,
    roman_to_integer,
    snake_string,
    ss_decode_col_id,
    string_decoding,
    string_encoding,
    string_to_int,
)


class TestString(unittest.TestCase):
    def test_convert_base(self):
        self.assertEqual(convert_base("615", 7, 13), "1A7")
        self.assertEqual(convert_base("1A7", 13, 7), "615")
        self.assertEqual(convert_base("102", 3, 4), "23")
        self.assertEqual(convert_base("23", 4, 3), "102")

    def test_int_to_string(self):
        self.assertEqual(int_to_string(123), "123")
        self.assertEqual(int_to_string(-123), "-123")
        self.assertEqual(int_to_string(314), "314")
        self.assertEqual(int_to_string(-314), "-314")
        self.assertEqual(int_to_string(0), "0")
        self.assertEqual(int_to_string(3), "3")

    def test_is_palindrome(self):
        self.assertTrue(is_palindrome("A man, a plan, a canal Panama."))
        self.assertTrue(is_palindrome("Able was I, ere I saw Elba!"))
        self.assertFalse(is_palindrome("Ray a Ray"))

    def test_look_and_say(self):
        self.assertEqual(look_and_say(8), "1113213211")

    def test_rabin_karp(self):
        text = "GACGCCA"
        string = "CGC"
        self.assertEqual(rabin_karp(text, string), text.find(string))
        text = "GACGCCA"
        string = "CCA"
        self.assertEqual(rabin_karp(text, string), text.find(string))
        text = "GACGCCA"
        string = "BBA"
        self.assertEqual(rabin_karp(text, string), text.find(string))
        text = "hello how are you?"
        string = "how are"
        self.assertEqual(rabin_karp(text, string), text.find(string))
        text = " hello world is the first code of every programmer"
        string = "first"
        self.assertEqual(rabin_karp(text, string), text.find(string))

    def test_replace_and_remove(self):
        s = ['a','c','a','a',None,None,None]
        self.assertEqual(replace_and_remove(4, s), 7)
        self.assertEqual(s, ['d','d','c','d','d','d','d'])

        s = ['a','c','d','b','b','c','a']
        self.assertEqual(replace_and_remove(7, s), 7)
        self.assertEqual(s, ['d','d','c','d','c','d','d'])

        s = ['a','b','a','c',None]
        self.assertEqual(replace_and_remove(4, s), 5)
        self.assertEqual(s, ['d','d','d','d','c'])

    def test_reverse_words(self):
        s = ['A','l','i','c','e',' ','l','i','k','e','s',' ','B','o','b']
        reverse_words(s)
        self.assertEqual(s, ['B','o','b',' ','l','i','k','e','s',' ','A','l','i','c','e'])
        s = ['r','a','m',' ','i','s',' ','c','o','s','t','l','y']
        reverse_words(s)
        self.assertEqual(s, ['c','o','s','t','l','y',' ','i','s',' ','r','a','m'])

    def test_roman_to_integer(self):
        self.assertEqual(roman_to_integer("XXXXXIIIIIIIII"), 59)
        self.assertEqual(roman_to_integer("LVIIII"), 59)
        self.assertEqual(roman_to_integer("LIX"), 59)
        self.assertEqual(roman_to_integer("IC"), 99)

    def test_snake_string(self):
        self.assertEqual(snake_string("Hello World!"), "e lHloWrdlo!")

    def test_ss_decode_col_id(self):
        self.assertEqual(ss_decode_col_id("D"), 4)
        self.assertEqual(ss_decode_col_id("AA"), 27)
        self.assertEqual(ss_decode_col_id("ZZ"), 702)

    def test_string_decoding(self):
        self.assertEqual(string_decoding("4a1b3c2a"), "aaaabcccaa")
        self.assertEqual(string_decoding("3e4f2e"), "eeeffffee")

    def test_string_encoding(self):
        self.assertEqual(string_encoding("aaaabcccaa"), "4a1b3c2a")
        self.assertEqual(string_encoding("eeeffffee"), "3e4f2e")

    def test_string_to_int(self):
        self.assertEqual(string_to_int("123"), 123)
        self.assertEqual(string_to_int("-123"), -123)
        self.assertEqual(string_to_int("-123"), -123)
        self.assertEqual(string_to_int("314"), 314)
        self.assertEqual(string_to_int("-314"), -314)
        self.assertEqual(string_to_int("0"), 0)
        self.assertEqual(string_to_int("3"), 3)
