#include "utils.h"

#include <stdlib.h>
#include <string.h>

// Declaration:
char* ArrayString_snakeString(const char* s);

void test_ArrayString_snakeString()
{
        const char* actual = ArrayString_snakeString("Hello World!");
        const char expected[] = "e lHloWrdlo!";
        int actualSize = strlen(actual);
        UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
        UTILS_ASSERT_EQUAL(actual, expected);
        free((void*)actual);
}
