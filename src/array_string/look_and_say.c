#include "utils/asserts.h"

extern char *array_string_lookAndSay(int n);

void test_array_string_lookAndSay()
{
        string_obj actual = {array_string_lookAndSay(8)};
        string_obj expected = {"1113213211"};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);
}
