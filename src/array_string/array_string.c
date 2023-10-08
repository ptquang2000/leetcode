#include "array_string.h"

#include "unity.h"
#include "stdio.h"

static void print_array(int* arr, int size);

static void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	for (int i = 0, j = 0; i < m + n; i++) {
		if (nums1[i] > nums2[j]) {
			int temp = nums1[i];
			nums1[i] = nums2[j];
			nums2[j] = temp;
		}
		else if (i >= m && nums1[i] == 0) {
			nums1[i] = nums2[j];
			j++;
		}
	}
}

void test1_merge_sorted_array()
{
	int expected[] = {1,2,2,3,5,6};
	int nums1[] = {1,2,3,0,0,0};
	int nums2[] = {2,5,6};

	merge(nums1, 3, 3, nums2, 3, 3);

	TEST_ASSERT_EQUAL_INT_ARRAY(expected, nums1, 6);
}

void setUp(void)
{
}

void tearDown(void)
{
}

static void print_array(int* arr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}