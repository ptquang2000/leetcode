#include "utils/asserts.h"

extern int array_string_romanToInteger(const char *s);

void test_array_string_romanToInteger()
{
        ASSERT_EQUAL((int_obj){array_string_romanToInteger("XXXXXIIIIIIIII")}, (int_obj){59});
        ASSERT_EQUAL((int_obj){array_string_romanToInteger("LVIIII")}, (int_obj){59});
        ASSERT_EQUAL((int_obj){array_string_romanToInteger("LIX")}, (int_obj){59});
        ASSERT_EQUAL((int_obj){array_string_romanToInteger("IC")}, (int_obj){99});
}
