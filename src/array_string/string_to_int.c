#include "utils.h"

// Declaration:
int array_string_stringToInt(const char* s);

void test_array_string_stringToInt()
{
        UTILS_ASSERT_EQUAL(array_string_stringToInt("123"), 123);
        UTILS_ASSERT_EQUAL(array_string_stringToInt("-123"), -123);
        UTILS_ASSERT_EQUAL(array_string_stringToInt("314"), 314);
        UTILS_ASSERT_EQUAL(array_string_stringToInt("-314"), -314);
        UTILS_ASSERT_EQUAL(array_string_stringToInt("0"), 0);
        UTILS_ASSERT_EQUAL(array_string_stringToInt("3"), 3);
}
