#include "array_string.h"

#include "is_palindrome.h"
#include "length_of_last_word.h"
#include "longest_common_prefix.h"
#include "max_profit.h"
#include "merge_sorted_array.h"
#include "remove_element.h"
#include "remove_duplicates.h"
#include "roman_to_int.h"
#include "str_str.h"
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

	RUN_TEST(test0_roman_to_int);
	RUN_TEST(test1_roman_to_int);
	RUN_TEST(test2_roman_to_int);

	RUN_TEST(test0_length_of_last_word);
	RUN_TEST(test1_length_of_last_word);
	RUN_TEST(test2_length_of_last_word);

	RUN_TEST(test0_longest_common_prefix);
	RUN_TEST(test1_longest_common_prefix);
	RUN_TEST(test2_longest_common_prefix);

	RUN_TEST(test0_str_str);
	RUN_TEST(test1_str_str);

	RUN_TEST(test0_is_palindrome);
	RUN_TEST(test1_is_palindrome);
	RUN_TEST(test2_is_palindrome);
	RUN_TEST(test3_is_palindrome);
	RUN_TEST(test4_is_palindrome);
	RUN_TEST(test5_is_palindrome);
	RUN_TEST(test6_is_palindrome);
	RUN_TEST(test7_is_palindrome);
	RUN_TEST(test8_is_palindrome);
}
