#include "utils.h"

#include <stdlib.h>
#include <string.h>

// Declaration:
char* ArrayString_stringEncoding(const char* s);

void test_ArrayString_stringEncoding()
{
        {
                const char* actual = ArrayString_stringEncoding("aaaabcccaa");
                const char expected[] = "4a1b3c2a";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
        {
                const char* actual = ArrayString_stringEncoding("eeeffffee");
                const char expected[] = "3e4f2e";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
}
