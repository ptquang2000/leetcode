#include "array_string.h"
#include "utils/asserts.h"

extern int array_string_deleteDuplicates(int ASize, int A[ASize]);

void test_array_string_deleteDuplicates()
{
        int_array A = {(int[]){2, 3, 5, 5, 7, 11, 11, 11, 13}, 9};
        A.len = array_string_deleteDuplicates(A.len, A.data);
        int_array expected = {(int[]){2, 3, 5, 7, 11, 13}, 6};
        ASSERT_EQUAL(A, expected);
}
