#include "utils/asserts.h"

extern void dsa_quick_sort(int size, int arr[size]);

void test_dsa_quick_sort()
{
        int_array arr = {(int[]){9, 3, 7, 4, 69, 420, 42}, 7};
        dsa_quick_sort(arr.len, arr.data);

        int_array expected = {(int[]){3, 4, 7, 9, 42, 69, 420}, 7};
        ASSERT_EQUAL(arr, expected);
}
