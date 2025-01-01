#include "utils.h"

// Declaration:
void ArrayString_reverseWords(int size, char s[size]);

void test_ArrayString_reverseWords()
{
        {
                char actual[] = {'A', 'l', 'i', 'c', 'e', ' ', 'l', 'i', 'k', 'e', 's', ' ', 'B', 'o', 'b'};
                ArrayString_reverseWords(15, actual);
                char expected[] = {'B', 'o', 'b', ' ', 'l', 'i', 'k', 'e', 's', ' ', 'A', 'l', 'i', 'c', 'e'};
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, 15);
        }
        {
                char actual[] = {'r', 'a', 'm', ' ', 'i', 's', ' ', 'c', 'o', 's', 't', 'l', 'y'};
                ArrayString_reverseWords(13, actual);
                char expected[] = {'c', 'o', 's', 't', 'l', 'y', ' ', 'i', 's', ' ', 'r', 'a', 'm'};
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, 13);
        }
}
