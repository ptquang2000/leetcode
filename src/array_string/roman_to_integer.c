#include "utils/utils.h"

// Declaration:
int array_string_romanToInteger(const char* s);

void test_array_string_romanToInteger()
{
        UTILS_ASSERT_EQUAL(array_string_romanToInteger("XXXXXIIIIIIIII"), 59);
        UTILS_ASSERT_EQUAL(array_string_romanToInteger("LVIIII"), 59);
        UTILS_ASSERT_EQUAL(array_string_romanToInteger("LIX"), 59);
        UTILS_ASSERT_EQUAL(array_string_romanToInteger("IC"), 99);
}
