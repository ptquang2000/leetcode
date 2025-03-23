#include "utils/asserts.h"

extern int array_string_replaceAndRemove(int size, char s[size]);

void test_array_string_replaceAndRemove()
{
        {
                char_array actual = {(char[]){'a', 'c', 'a', 'a', '\0', '\0', '\0'}, 7};
                actual.len = array_string_replaceAndRemove(4, actual.data);
                char_array expected = {(char[]){'d', 'd', 'c', 'd', 'd', 'd', 'd'}, 7};
                ASSERT_EQUAL(actual, expected);
        }
        {
                char_array actual = {(char[]){'a', 'c', 'd', 'b', 'b', 'c', 'a'}, 7};
                actual.len = array_string_replaceAndRemove(7, actual.data);
                char_array expected = {(char[]){'d', 'd', 'c', 'd', 'c', 'd', 'd'}, 7};
                ASSERT_EQUAL(actual, expected);
        }
        {
                char_array actual = {(char[]){'a', 'b', 'a', 'c', '\0'}, 5};
                actual.len = array_string_replaceAndRemove(4, actual.data);
                char_array expected = {(char[]){'d', 'd', 'd', 'd', 'c'}, 5};
                ASSERT_EQUAL(actual, expected);
        }
}
