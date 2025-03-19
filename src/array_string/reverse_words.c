#include "utils/asserts.h"

extern void array_string_reverseWords(int size, char s[size]);

void test_array_string_reverseWords()
{
        {
                char_array actual = {
                        (char[]){'A', 'l', 'i', 'c', 'e', ' ', 'l', 'i', 'k', 'e', 's', ' ', 'B', 'o', 'b'}, 15};
                array_string_reverseWords(actual.len, actual.data);
                char_array expected = {
                        (char[]){'B', 'o', 'b', ' ', 'l', 'i', 'k', 'e', 's', ' ', 'A', 'l', 'i', 'c', 'e'}, 15};
                ASSERT_EQUAL(actual, expected);
        }
        {
                char_array actual = {(char[]){'r', 'a', 'm', ' ', 'i', 's', ' ', 'c', 'o', 's', 't', 'l', 'y'}, 13};
                array_string_reverseWords(actual.len, actual.data);
                char_array expected = {(char[]){'c', 'o', 's', 't', 'l', 'y', ' ', 'i', 's', ' ', 'r', 'a', 'm'}, 13};
                ASSERT_EQUAL(actual, expected);
        }
}
