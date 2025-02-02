#include "utils/utils.h"

#include <stdlib.h>
#include <string.h>

extern char* array_string_snakeString(const char* s);

void test_array_string_snakeString()
{
        const char* actual = array_string_snakeString("Hello World!");
        const char expected[] = "e lHloWrdlo!";
        int actualSize = strlen(actual);
        UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
        UTILS_ASSERT_EQUAL(actual, expected);
        free((void*)actual);
}
