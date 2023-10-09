#include "stdio.h"
#include "unity.h"
#include "array_string.h"

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test1_merge_sorted_array);
	RUN_TEST(test2_merge_sorted_array);
	RUN_TEST(test3_merge_sorted_array);
	RUN_TEST(test4_merge_sorted_array);
	RUN_TEST(test5_merge_sorted_array);

	return UNITY_END();
}
