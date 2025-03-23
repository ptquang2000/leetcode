#include "utils/asserts.h"

extern char *stack_shortest_equivalent_path(const char *path);

void test_stack_shortest_equivalent_path()
{
        {
                string_obj expected = {"/home"};
                string_obj actual = {stack_shortest_equivalent_path("/home/")};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                string_obj expected = {"/"};
                string_obj actual = {stack_shortest_equivalent_path("/../")};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                string_obj expected = {"/home/foo"};
                string_obj actual = {stack_shortest_equivalent_path("/home//foo/")};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                string_obj expected = {"tc/awk"};
                string_obj actual = {stack_shortest_equivalent_path("sc//./../tc/awk/././")};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                string_obj expected = {"/usr/bin/gcc"};
                string_obj actual = {stack_shortest_equivalent_path("/usr/lib/../bin/gcc")};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                string_obj expected = {"scripts/awkscripts"};
                string_obj actual = {stack_shortest_equivalent_path("scripts//./../scripts/awkscripts/././")};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
}
