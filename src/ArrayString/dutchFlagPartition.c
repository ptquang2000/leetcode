#include "utils.h"

// Declaration:
void ArrayString_dutchFlagPartition(int pivotIndex, int ASize, int A[ASize]);

static int count(int size, int array[size], int value)
{
        int result = 0;
        for (int i = 0; i < size; i++)
        {
                if (array[i] == value)
                        result++;
        }
        return result;
}

void test_ArrayString_dutchFlagPartition()
{
        {
                int A[] = {0, 1, 2, 0, 2, 1, 1};
                ArrayString_dutchFlagPartition(2, 7, A);

                UTILS_ASSERT_EQUAL(count(7, A, 0), 2);
                UTILS_ASSERT_EQUAL(count(7, A, 1), 3);
                UTILS_ASSERT_EQUAL(count(7, A, 2), 2);

                const int expectLess[] = {2, 2, 2, 2, 2};
                UTILS_ASSERT_LESS(A, expectLess, 5);
                const int expectEqual[] = {2, 2};
                UTILS_ASSERT_EQUAL(A + 5, expectEqual, 2);
        }
        {
                int A[] = {0, 1, 2, 0, 2, 1, 1};
                ArrayString_dutchFlagPartition(3, 7, A);

                UTILS_ASSERT_EQUAL(count(7, A, 0), 2);
                UTILS_ASSERT_EQUAL(count(7, A, 1), 3);
                UTILS_ASSERT_EQUAL(count(7, A, 2), 2);

                const int expectEqual[] = {0, 0};
                UTILS_ASSERT_EQUAL(A, expectEqual, 2);
                const int expectGreater[] = {0, 0, 0, 0, 0};
                UTILS_ASSERT_GREATER(A + 2, expectGreater, 5);
        }
}
