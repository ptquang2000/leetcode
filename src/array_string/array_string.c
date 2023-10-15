#include "array_string.h"

#include "max_profit.h"
#include "merge_sorted_array.h"
#include "remove_element.h"
#include "remove_duplicates.h"
#include "unity_internals.h"

void run_array_string_tests(void)
{
	RUN_TEST(test0_merge_sorted_array);
	RUN_TEST(test1_merge_sorted_array);
	RUN_TEST(test2_merge_sorted_array);
	RUN_TEST(test3_merge_sorted_array);
	RUN_TEST(test4_merge_sorted_array);

	RUN_TEST(test0_remove_element);
	RUN_TEST(test1_remove_element);

	RUN_TEST(test0_remove_duplicates);
	RUN_TEST(test1_remove_duplicates);

	RUN_TEST(test0_max_profit);
	RUN_TEST(test1_max_profit);
}
