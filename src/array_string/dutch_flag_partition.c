#include "utils/asserts.h"

extern void array_string_dutchFlagPartition(int pivotIndex, int ASize, int A[ASize]);

static int count(int size, int array[size], int value)
{
        int result = 0;
        for (int i = 0; i < size; i++) {
                if (array[i] == value)
                        result++;
        }
        return result;
}

void test_array_string_dutchFlagPartition()
{
        {
                int_array A = {(int[]){0, 1, 2, 0, 2, 1, 1}, 7};
                array_string_dutchFlagPartition(2, A.len, A.data);

                ASSERT_EQUAL((int_obj){count(A.len, A.data, 0)}, (int_obj){2});
                ASSERT_EQUAL((int_obj){count(A.len, A.data, 1)}, (int_obj){3});
                ASSERT_EQUAL((int_obj){count(A.len, A.data, 2)}, (int_obj){2});

                int_array expectLess = {(int[]){2, 2, 2, 2, 2}, 5};
                A.len = expectLess.len;
                ASSERT_LESS(A, expectLess);
                int_array expectEqual = {(int[]){2, 2}, 2};
                A.data = A.data + 5;
                A.len = expectEqual.len;
                ASSERT_EQUAL(A, expectEqual);
        }
        {
                int_array A = {(int[]){0, 1, 2, 0, 2, 1, 1}, 7};
                array_string_dutchFlagPartition(3, A.len, A.data);

                ASSERT_EQUAL((int_obj){count(A.len, A.data, 0)}, (int_obj){2});
                ASSERT_EQUAL((int_obj){count(A.len, A.data, 1)}, (int_obj){3});
                ASSERT_EQUAL((int_obj){count(A.len, A.data, 2)}, (int_obj){2});

                int_array expectEqual = {(int[]){0, 0}, 2};
                A.len = expectEqual.len;
                ASSERT_EQUAL(A, expectEqual);
                int_array expectGreater = {(int[]){0, 0, 0, 0, 0}, 5};
                A.data = A.data + 2;
                A.len = expectGreater.len;
                ASSERT_GREATER(A, expectGreater);
        }
}
