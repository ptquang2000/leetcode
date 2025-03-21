#include "array_string.h"
#include "utils/asserts.h"

#include <stdbool.h>

extern bool array_string_canReachEnd(int ASize, int A[ASize]);

void test_array_string_canReachEnd()
{
        {
                int_array A = {(int[]){2, 4, 1, 1, 0, 2, 3}, 7};
                ASSERT_TRUE(array_string_canReachEnd(A.len, A.data));
        }
        {
                int_array A = {(int[]){3, 3, 7, 0, 2, 0, 1}, 7};
                ASSERT_TRUE(array_string_canReachEnd(A.len, A.data));
        }
        {
                int_array A = {(int[]){3, 2, 0, 0, 2, 0, 7}, 7};
                ASSERT_FALSE(array_string_canReachEnd(A.len, A.data));
        }
}
