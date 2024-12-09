#include "utils.h"

#include <stdlib.h>
#include <string.h>

// Declaration:
char* ArrayString_stringDecoding(const char*);

void test_ArrayString_stringDecoding()
{
        {
                const char* actual = ArrayString_stringDecoding("4a1b3c2a");
                const char expected[] = "aaaabcccaa";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
        {
                const char* actual = ArrayString_stringDecoding("3e4f2e");
                const char expected[] = "eeeffffee";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
}
