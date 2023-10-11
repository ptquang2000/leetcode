#include "array_string.h"

#include "unity.h"
#include "stdio.h"

static void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	while (m > 0 || n > 0) {
		if (n == 0) {
			break;
		}
		else if (m == 0 || nums1[m - 1] <= nums2[n - 1]) {
			n--;
			nums1[m + n] = nums2[n];
		}
		else if (nums1[m - 1] > nums2[n - 1]) {
			m--;
			nums1[m + n] = nums1[m];
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
