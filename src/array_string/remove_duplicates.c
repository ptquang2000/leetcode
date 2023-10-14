#include "remove_duplicates.h"
#include "unity.h"

static int remove_duplicates(int* nums, int numsSize)
{
	int i, j;
	for (i = 0, j = 0; i < numsSize; i++) {
		if (nums[j] < nums[i]) {
			nums[++j] = nums[i];
		}
	}
	return ++j;
}

void test0_remove_duplicates(void)
{
	int expected[] = {0,1,2,3,4};
	int nums[] = {0,0,1,1,1,2,2,3,3,4};

	int output = remove_duplicates(nums, 10);
	TEST_ASSERT_EQUAL(5, output);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, nums, 5);
}

void test1_remove_duplicates(void)
{
	int expected[] = {1,2};
	int nums[] = {1,1,2};

	int output = remove_duplicates(nums, 3);
	TEST_ASSERT_EQUAL(2, output);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, nums, 2);
}
