#include "remove_element.h"
#include "unity.h"

static int removeElement(int* nums, int numsSize, int val)
{
	int i = 0;
	while (i < numsSize) {
		if (nums[i] != val) {
			i++;
			continue;
		}

		if (nums[numsSize - 1] != val) {
			nums[i] = nums[numsSize - 1];
			i++;
		}
		numsSize--;
	}

	return numsSize;
}

void test1_remove_element(void)
{
	int expected[] = { 2,2 };
	int nums[] = { 3,2,2,3 };

	removeElement(nums, 4, 3);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, nums, 2);
}

void test0_remove_element(void)
{
	int expected[] = { 0,1,4,0,3 };
	int nums[] = { 0,1,2,2,3,0,4,2 };

	removeElement(nums, 8, 2);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, nums, 5);
}

