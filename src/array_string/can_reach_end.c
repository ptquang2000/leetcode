#include "array_string.h"
#include "utils/utils.h"

#include <stdbool.h>

// Declaration:
bool array_string_canReachEnd(int ASize, int A[ASize]);

void test_array_string_canReachEnd()
{
        {
                int A[] = {2, 4, 1, 1, 0, 2, 3};
                UTILS_ASSERT_TRUE(array_string_canReachEnd(7, A));
        }
        {
                int A[] = {3, 3, 7, 0, 2, 0, 1};
                UTILS_ASSERT_TRUE(array_string_canReachEnd(7, A));
        }
        {
                int A[] = {3, 2, 0, 0, 2, 0, 7};
                UTILS_ASSERT_TRUE(array_string_canReachEnd(7, A));
        }
}
