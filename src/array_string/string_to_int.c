#include "utils/asserts.h"

extern int array_string_stringToInt(const char *s);

void test_array_string_stringToInt()
{
        ASSERT_EQUAL((int_obj){array_string_stringToInt("123")}, (int_obj){123});
        ASSERT_EQUAL((int_obj){array_string_stringToInt("-123")}, (int_obj){-123});
        ASSERT_EQUAL((int_obj){array_string_stringToInt("314")}, (int_obj){314});
        ASSERT_EQUAL((int_obj){array_string_stringToInt("-314")}, (int_obj){-314});
        ASSERT_EQUAL((int_obj){array_string_stringToInt("0")}, (int_obj){0});
        ASSERT_EQUAL((int_obj){array_string_stringToInt("3")}, (int_obj){3});
}
