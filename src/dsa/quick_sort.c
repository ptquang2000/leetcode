#include "utils/asserts.h"

extern void dsa_quick_sort(int size, int arr[size]);

void test_dsa_quick_sort()
{
        int arr[] = {9, 3, 7, 4, 69, 420, 42};
        dsa_quick_sort(ARRAY_SIZE(arr), arr);

        int expected[] = {3, 4, 7, 9, 42, 69, 420};
        ASSERT_EQUAL(arr, expected, ARRAY_SIZE(expected));
}
