#include "stdio.h"
#include "unity.h"
#include "array_string/array_string.h"
#include "linked_list/linked_list.h"
#include "stack/stack.h"
#include "two_pointers/two_pointers.h"

void setUp(void) 
{
}

void tearDown(void)
{
}

int main(int argc, char** agrv)
{
	UNITY_BEGIN();

	run_array_string_tests();
	run_two_pointers_tests();
	run_stack_tests();
	run_linked_list_tests();

	return UNITY_END();
}
