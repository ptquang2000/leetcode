#include "utils/asserts.h"

extern char *array_string_convertBase(const char *numAsString, int b1, int b2);

void test_array_string_convertBase()
{
        {
                string_obj actual = {array_string_convertBase("615", 7, 13)};
                string_obj expected = {"1A7"};
                ASSERT_EQUAL(actual, expected);
                free((void *)actual.data);
        }
        {
                string_obj actual = {array_string_convertBase("1A7", 13, 7)};
                string_obj expected = {"615"};
                ASSERT_EQUAL(actual, expected);
                free((void *)actual.data);
        }
        {
                string_obj actual = {array_string_convertBase("102", 3, 4)};
                string_obj expected = {"23"};
                ASSERT_EQUAL(actual, expected);
                free((void *)actual.data);
        }
        {
                string_obj actual = {array_string_convertBase("23", 4, 3)};
                string_obj expected = {"102"};
                ASSERT_EQUAL(actual, expected);
                free((void *)actual.data);
        }
}
