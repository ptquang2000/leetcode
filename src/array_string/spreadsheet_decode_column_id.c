#include "utils/utils.h"

extern int array_string_spreadsheetDecodeColumnID(const char* column);

void test_array_string_spreadsheetDecodeColumnID()
{
        UTILS_ASSERT_EQUAL(array_string_spreadsheetDecodeColumnID("D"), 4);
        UTILS_ASSERT_EQUAL(array_string_spreadsheetDecodeColumnID("AA"), 27);
        UTILS_ASSERT_EQUAL(array_string_spreadsheetDecodeColumnID("ZZ"), 702);
}
