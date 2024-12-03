#include "utils.h"

// Declaration:
void ArrayString_applyPermutation(int* perm, int permSize, char* A, int ASize);

void test_ArrayString_applyPermutation()
{
    {
        char A[] = {'a', 'b', 'c', 'd'};
        int perm[] = {3, 2, 1, 0};
        ArrayString_applyPermutation(perm, 4, A, 4);

        const char expected[] = {'d', 'c', 'b', 'a'};
        UTILS_ASSERT_EQUAL(A, expected, 4);
    }
    {
        char A[] = {'a', 'b', 'c', 'd'};
        int perm[] = {2, 0, 1, 3};
        ArrayString_applyPermutation(perm, 4, A, 4);

        const char expected[] = {'b', 'c', 'a', 'd'};
        UTILS_ASSERT_EQUAL(A, expected, 4);
    }
}
