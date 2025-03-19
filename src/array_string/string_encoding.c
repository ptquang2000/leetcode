#include "utils/asserts.h"

extern char *array_string_stringEncoding(const char *s);

void test_array_string_stringEncoding()
{
        {
                string_obj actual = {array_string_stringEncoding("aaaabcccaa")};
                string_obj expected = {"4a1b3c2a"};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                string_obj actual = {array_string_stringEncoding("eeeffffee")};
                string_obj expected = {"3e4f2e"};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
}
