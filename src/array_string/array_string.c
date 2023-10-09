#include "array_string.h"

#include "unity.h"
#include "stdio.h"

static void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	if (n == 0) {
		return;
	}
	else if (m == 0) {
		for (int k = 0; k < nums1Size; k++) {
			nums1[k] = nums2[k];
		}
		return;
	}

	for (int i = 0, j = 0; i < m + n; i++) {
		if (i >= m) {
			nums1[i] = nums2[j];
			j++;
		}
		else if (nums1[i] > nums2[j]) {
			int temp = nums1[i];
			nums1[i] = nums2[j];
			nums2[j] = temp;
			
			for (int k = j; k < n - 1; k++) {
				if (nums2[k] <= nums2[k + 1]) break;
			
				temp = nums2[k];
				nums2[k] = nums2[k + 1];
				nums2[k + 1] = temp;
			}
		}
	}
}

void test1_merge_sorted_array()
{
	int expected[] = {1,2,2,3,5,6};
	int nums1[] = {1,2,3,0,0,0};
	int nums2[] = {2,5,6};

	merge(nums1, 6, 3, nums2, 3, 3);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, nums1, 6);
}

void test2_merge_sorted_array()
{
	int expected[] = { 1 };
	int nums1[] = { 1 };

	merge(nums1, 1, 1, NULL, 0, 0);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, nums1, 1);
}

void test3_merge_sorted_array()
{
	int expected[] = { 1 };
	int nums1[] = { 0 };
	int nums2[] = { 1 };

	merge(nums1, 1, 0, nums2, 1, 1);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, nums1, 1);
}

void test4_merge_sorted_array()
{
	int expected[] = { 1,2,3,4,5,6 };
	int nums1[] = { 4,5,6,0,0,0 };
	int nums2[] = { 1,2,3 };

	merge(nums1, 6, 3, nums2, 3, 3);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, nums1, 6);
}

void test5_merge_sorted_array()
{
	int expected[] = { 1,2,3,4,5,6 };
	int nums1[] = { 4,0,0,0,0,0 };
	int nums2[] = { 1,2,3,5,6 };

	merge(nums1, 6, 1, nums2, 5, 5);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, nums1, 6);
}

void setUp(void)
{
}

void tearDown(void)
{
}