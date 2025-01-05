#include "array_string.h"
#include "utils.h"

// Declaration:
int array_string_deleteDuplicates(int ASize, int A[ASize]);

void test_array_string_deleteDuplicates()
{
        int A[] = {2, 3, 5, 5, 7, 11, 11, 11, 13};
        UTILS_ASSERT_EQUAL(array_string_deleteDuplicates(9, A), 6);
        int expected[] = {2, 3, 5, 7, 11, 13};
        UTILS_ASSERT_EQUAL_ARRAY(A, expected, 6);
}
