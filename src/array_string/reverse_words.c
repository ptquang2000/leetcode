#include "utils/utils.h"

extern void array_string_reverseWords(int size, char s[size]);

void test_array_string_reverseWords()
{
        {
                char actual[] = {'A', 'l', 'i', 'c', 'e', ' ', 'l', 'i', 'k', 'e', 's', ' ', 'B', 'o', 'b'};
                array_string_reverseWords(15, actual);
                char expected[] = {'B', 'o', 'b', ' ', 'l', 'i', 'k', 'e', 's', ' ', 'A', 'l', 'i', 'c', 'e'};
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, 15);
        }
        {
                char actual[] = {'r', 'a', 'm', ' ', 'i', 's', ' ', 'c', 'o', 's', 't', 'l', 'y'};
                array_string_reverseWords(13, actual);
                char expected[] = {'c', 'o', 's', 't', 'l', 'y', ' ', 'i', 's', ' ', 'r', 'a', 'm'};
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, 13);
        }
}
