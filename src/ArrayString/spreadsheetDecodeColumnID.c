#include "utils.h"

// Declaration:
int ArrayString_spreadsheetDecodeColumnID(const char* column);

void test_ArrayString_spreadsheetDecodeColumnID()
{
        UTILS_ASSERT_EQUAL(ArrayString_spreadsheetDecodeColumnID("D"), 4);
        UTILS_ASSERT_EQUAL(ArrayString_spreadsheetDecodeColumnID("AA"), 27);
        UTILS_ASSERT_EQUAL(ArrayString_spreadsheetDecodeColumnID("ZZ"), 702);
}
