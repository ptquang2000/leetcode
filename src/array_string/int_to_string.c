#include "utils/asserts.h"

extern char *array_string_intToString(int x);

void test_array_string_intToString()
{
        {
                string_obj actual = {array_string_intToString(123)};
                string_obj expected = {"123"};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                string_obj actual = {array_string_intToString(-123)};
                string_obj expected = {"-123"};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                string_obj actual = {array_string_intToString(314)};
                string_obj expected = {"314"};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                string_obj actual = {array_string_intToString(-314)};
                string_obj expected = {"-314"};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                string_obj actual = {array_string_intToString(0)};
                string_obj expected = {"0"};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
        {
                string_obj actual = {array_string_intToString(3)};
                string_obj expected = {"3"};
                ASSERT_EQUAL(actual, expected);
                free(actual.data);
        }
}
