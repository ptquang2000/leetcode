#include "linked_list_cycle.h"
#include "merge_two_sorted_lists.h"

#include "unity_internals.h"

void run_linked_list_tests(void)
{
	RUN_TEST(test0_linked_list_cycle);
	RUN_TEST(test1_linked_list_cycle);
	RUN_TEST(test2_linked_list_cycle);

	RUN_TEST(test0_merge_two_sorted_lists);
	RUN_TEST(test1_merge_two_sorted_lists);
	RUN_TEST(test2_merge_two_sorted_lists);
}
