#include "ArrayString.h"
#include "utils.h"

// Declaration:
int ArrayString_deleteDuplicates(int* A, int ASize);

void test_ArrayString_deleteDuplicates()
{
    int A[] = {2, 3, 5, 5, 7, 11, 11, 11, 13};
    UTILS_ASSERT_EQUAL(ArrayString_deleteDuplicates(A, 9), 6);
    int expected[] = {2, 3, 5, 7, 11, 13};
    UTILS_ASSERT_EQUAL(A, expected, 6);
}
