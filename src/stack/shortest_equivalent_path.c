#include "utils.h"

#include <stdlib.h>
#include <string.h>

// Declaration:
char* stack_shortest_equivalent_path(const char* path);

void test_stack_shortest_equivalent_path()
{
        {
                const char expected[] = "/home";
                char* actual = stack_shortest_equivalent_path("/home/");
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected) - 1);
                UTILS_ASSERT_EQUAL((const char*)actual, expected);
                free(actual);
        }
        {
                const char expected[] = "/";
                char* actual = stack_shortest_equivalent_path("/../");
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected) - 1);
                UTILS_ASSERT_EQUAL((const char*)actual, expected);
                free(actual);
        }
        {
                const char expected[] = "/home/foo";
                char* actual = stack_shortest_equivalent_path("/home//foo/");
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected) - 1);
                UTILS_ASSERT_EQUAL((const char*)actual, expected);
                free(actual);
        }
        {
                const char expected[] = "tc/awk";
                char* actual = stack_shortest_equivalent_path("sc//./../tc/awk/././");
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected) - 1);
                UTILS_ASSERT_EQUAL((const char*)actual, expected);
                free(actual);
        }
        {
                const char expected[] = "/usr/bin/gcc";
                char* actual = stack_shortest_equivalent_path("/usr/lib/../bin/gcc");
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected) - 1);
                UTILS_ASSERT_EQUAL((const char*)actual, expected);
                free(actual);
        }
        {
                const char expected[] = "scripts/awkscripts";
                char* actual = stack_shortest_equivalent_path("scripts//./../scripts/awkscripts/././");
                int actualSize = strlen(actual);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected) - 1);
                UTILS_ASSERT_EQUAL((const char*)actual, expected);
                free(actual);
        }
}
