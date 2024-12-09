#include "utils.h"

#include <stdlib.h>
#include <string.h>

// Declaration:
char* ArrayString_lookAndSay(int n);

void test_ArrayString_lookAndSay()
{
        const char* actual = ArrayString_lookAndSay(8);
        const char expected[] = "1113213211";
        int actualSize = strlen(actual);
        UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) - 1);
        UTILS_ASSERT_EQUAL(actual, expected);
        free((void*)actual);
}
