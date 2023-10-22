#include "stdio.h"
#include "two_pointers/two_pointers.h"
#include "unity.h"
#include "array_string/array_string.h"

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

	return UNITY_END();
}
