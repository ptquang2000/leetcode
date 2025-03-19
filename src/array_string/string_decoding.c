#include "utils/asserts.h"

extern char *array_string_stringDecoding(const char *s);

void test_array_string_stringDecoding()
{
        {
                string_obj actual = {array_string_stringDecoding("4a1b3c2a")};
                string_obj expected = {"aaaabcccaa"};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                string_obj actual = {array_string_stringDecoding("3e4f2e")};
                string_obj expected = {"eeeffffee"};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
}
