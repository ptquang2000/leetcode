#include "utils/asserts.h"

extern char *array_string_snakeString(const char *s);

void test_array_string_snakeString()
{
        string_obj actual = {array_string_snakeString("Hello World!")};
        string_obj expected = {"e lHloWrdlo!"};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);
}
