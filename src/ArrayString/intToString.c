#include "utils.h"

#include <stdlib.h>
#include <string.h>

// Declaration:
char* ArrayString_intToString(int x);

void test_ArrayString_intToString()
{
        {
                const char* actual = ArrayString_intToString(123);
                const char expected[] = "123";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
        {
                const char* actual = ArrayString_intToString(-123);
                const char expected[] = "-123";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
        {
                const char* actual = ArrayString_intToString(314);
                const char expected[] = "314";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
        {
                const char* actual = ArrayString_intToString(-314);
                const char expected[] = "-314";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
        {
                const char* actual = ArrayString_intToString(0);
                const char expected[] = "0";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
        {
                const char* actual = ArrayString_intToString(3);
                const char expected[] = "3";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
}
