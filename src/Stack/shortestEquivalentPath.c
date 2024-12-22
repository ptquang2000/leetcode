#include "utils.h"

#include <stdlib.h>
#include <string.h>

// Declaration:
char* Stack_shortestEquivalentPath(const char* path);

void test_Stack_shortestEquivalentPath()
{
        {
                const char expected[] = "/home";
                char* actual = Stack_shortestEquivalentPath("/home/");
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected) - 1);
                UTILS_ASSERT_EQUAL((const char*)actual, expected);
                free(actual);
        }
        {
                const char expected[] = "/";
                char* actual = Stack_shortestEquivalentPath("/../");
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected) - 1);
                UTILS_ASSERT_EQUAL((const char*)actual, expected);
                free(actual);
        }
        {
                const char expected[] = "/home/foo";
                char* actual = Stack_shortestEquivalentPath("/home//foo/");
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected) - 1);
                UTILS_ASSERT_EQUAL((const char*)actual, expected);
                free(actual);
        }
        {
                const char expected[] = "tc/awk";
                char* actual = Stack_shortestEquivalentPath("sc//./../tc/awk/././");
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected) - 1);
                UTILS_ASSERT_EQUAL((const char*)actual, expected);
                free(actual);
        }
        {
                const char expected[] = "/usr/bin/gcc";
                char* actual = Stack_shortestEquivalentPath("/usr/lib/../bin/gcc");
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected) - 1);
                UTILS_ASSERT_EQUAL((const char*)actual, expected);
                free(actual);
        }
        {
                const char expected[] = "scripts/awkscripts";
                char* actual = Stack_shortestEquivalentPath("scripts//./../scripts/awkscripts/././");
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected) - 1);
                UTILS_ASSERT_EQUAL((const char*)actual, expected);
                free(actual);
        }
}
