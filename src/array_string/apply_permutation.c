#include "utils/asserts.h"

extern void array_string_applyPermutation(int permSize, int perm[permSize], int ASize, char A[ASize]);

void test_array_string_applyPermutation()
{
        {
                char_array A = {(char[]){'a', 'b', 'c', 'd'}, 4};
                int_array perm = {(int[]){3, 2, 1, 0}, 4};
                array_string_applyPermutation(perm.len, perm.data, A.len, A.data);

                char_array expected = {(char[]){'d', 'c', 'b', 'a'}, 4};
                ASSERT_EQUAL(A, expected);
        }
        {
                char_array A = {(char[]){'a', 'b', 'c', 'd'}, 4};
                int_array perm = {(int[]){2, 0, 1, 3}, 4};
                array_string_applyPermutation(perm.len, perm.data, A.len, A.data);

                char_array expected = {(char[]){'b', 'c', 'a', 'd'}, 4};
                ASSERT_EQUAL(A, expected);
        }
}
