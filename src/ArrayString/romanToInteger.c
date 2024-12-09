#include "utils.h"

// Declaration:
int ArrayString_romanToInteger(const char* s);

void test_ArrayString_romanToInteger()
{
        UTILS_ASSERT_EQUAL(ArrayString_romanToInteger("XXXXXIIIIIIIII"), 59);
        UTILS_ASSERT_EQUAL(ArrayString_romanToInteger("LVIIII"), 59);
        UTILS_ASSERT_EQUAL(ArrayString_romanToInteger("LIX"), 59);
        UTILS_ASSERT_EQUAL(ArrayString_romanToInteger("IC"), 99);
}
