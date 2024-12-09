#include "utils.h"

// Declaration:
int ArrayString_stringToInt(const char* s);

void test_ArrayString_stringToInt()
{
        UTILS_ASSERT_EQUAL(ArrayString_stringToInt("123"), 123);
        UTILS_ASSERT_EQUAL(ArrayString_stringToInt("-123"), -123);
        UTILS_ASSERT_EQUAL(ArrayString_stringToInt("314"), 314);
        UTILS_ASSERT_EQUAL(ArrayString_stringToInt("-314"), -314);
        UTILS_ASSERT_EQUAL(ArrayString_stringToInt("0"), 0);
        UTILS_ASSERT_EQUAL(ArrayString_stringToInt("3"), 3);
}
