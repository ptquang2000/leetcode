#include "stack.h"

#include "valid_parentheses.h"
#include "unity_internals.h"

void run_stack_tests(void)
{
	RUN_TEST(test0_valid_parentheses);
	RUN_TEST(test1_valid_parentheses);
	RUN_TEST(test2_valid_parentheses);
}
