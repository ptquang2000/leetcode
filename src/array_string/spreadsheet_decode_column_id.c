#include "utils/asserts.h"

extern int array_string_spreadsheetDecodeColumnID(const char *column);

void test_array_string_spreadsheetDecodeColumnID()
{
        ASSERT_EQUAL((int_obj){array_string_spreadsheetDecodeColumnID("D")}, (int_obj){4});
        ASSERT_EQUAL((int_obj){array_string_spreadsheetDecodeColumnID("AA")}, (int_obj){27});
        ASSERT_EQUAL((int_obj){array_string_spreadsheetDecodeColumnID("ZZ")}, (int_obj){702});
}
