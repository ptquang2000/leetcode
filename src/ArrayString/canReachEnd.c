#include "ArrayString.h"
#include "utils.h"

#include <stdbool.h>

// Declaration:
bool ArrayString_canReachEnd(int* A, int ASize);

void test_ArrayString_canReachEnd()
{
        {
                int A[] = {2, 4, 1, 1, 0, 2, 3};
                UTILS_ASSERT_TRUE(ArrayString_canReachEnd(A, 7));
        }
        {
                int A[] = {3, 3, 7, 0, 2, 0, 1};
                UTILS_ASSERT_TRUE(ArrayString_canReachEnd(A, 7));
        }
        {
                int A[] = {3, 2, 0, 0, 2, 0, 7};
                UTILS_ASSERT_FALSE(ArrayString_canReachEnd(A, 7));
        }
}
