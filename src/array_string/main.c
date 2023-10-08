#include "stdio.h"
#include "unity.h"
#include "array_string.h"

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test1_merge_sorted_array);

	return UNITY_END();
}
