#include "utils.h"

#include <stdlib.h>
#include <string.h>

// Declaration:
char* array_string_lookAndSay(int n);

void test_array_string_lookAndSay()
{
        const char* actual = array_string_lookAndSay(8);
        const char expected[] = "1113213211";
        int actualSize = strlen(actual);
        UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
        UTILS_ASSERT_EQUAL(actual, expected);
        free((void*)actual);
}
