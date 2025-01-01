#include "ArrayString.h"
#include "utils.h"

// Declaration:
int ArrayString_deleteDuplicates(int ASize, int A[ASize]);

void test_ArrayString_deleteDuplicates()
{
        int A[] = {2, 3, 5, 5, 7, 11, 11, 11, 13};
        UTILS_ASSERT_EQUAL(ArrayString_deleteDuplicates(9, A), 6);
        int expected[] = {2, 3, 5, 7, 11, 13};
        UTILS_ASSERT_EQUAL_ARRAY(A, expected, 6);
}
