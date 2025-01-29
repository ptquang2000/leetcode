#include "utils/utils.h"

#include <stdlib.h>
#include <string.h>

// Declaration:
char* array_string_convertBase(const char* numAsString, int b1, int b2);

void test_array_string_convertBase()
{
        {
                const char* actual = array_string_convertBase("615", 7, 13);
                const char expected[] = "1A7";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
        {
                const char* actual = array_string_convertBase("1A7", 13, 7);
                const char expected[] = "615";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
        {
                const char* actual = array_string_convertBase("102", 3, 4);
                const char expected[] = "23";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
        {
                const char* actual = array_string_convertBase("23", 4, 3);
                const char expected[] = "102";
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
                UTILS_ASSERT_EQUAL(actual, expected);
                free((void*)actual);
        }
}
