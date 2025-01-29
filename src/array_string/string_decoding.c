#include "utils/utils.h"

#include <stdlib.h>
#include <string.h>

// Declaration:
char* array_string_stringDecoding(const char* s);

void test_array_string_stringDecoding()
{
        {
                const char* actual = array_string_stringDecoding("4a1b3c2a");
                const char expected[] = "aaaabcccaa";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
        {
                const char* actual = array_string_stringDecoding("3e4f2e");
                const char expected[] = "eeeffffee";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
}
