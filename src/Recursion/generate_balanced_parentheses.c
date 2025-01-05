#include "utils.h"

// Declaration:
char** Recursion_generate_balanced_parentheses(int i_num_pairs, int* o_size);

void test_Recursion_generate_balanced_parentheses()
{
        {
                const int num_pairs = 3;
                const char* expected[] = {"((()))", "(()())", "(())()", "()(())", "()()()"};
                int expected_size = ARRAY_SIZE(expected), actual_size;
                char** actual = Recursion_generate_balanced_parentheses(num_pairs, &actual_size);
                UTILS_ASSERT_EQUAL(actual_size, expected_size);
                UTILS_ASSERT_COUNT_EQUAL((const char**)actual, expected, expected_size);

                free_array(actual, actual_size);
        }
        {
                const int num_pairs = 2;
                const char* expected[] = {"(())", "()()"};
                int expected_size = ARRAY_SIZE(expected), actual_size;
                char** actual = Recursion_generate_balanced_parentheses(num_pairs, &actual_size);
                UTILS_ASSERT_EQUAL(actual_size, expected_size);
                UTILS_ASSERT_COUNT_EQUAL((const char**)actual, expected, expected_size);

                free_array(actual, actual_size);
        }
        {
                const int num_pairs = 1;
                const char* expected[] = {"()"};
                int expected_size = ARRAY_SIZE(expected), actual_size;
                char** actual = Recursion_generate_balanced_parentheses(num_pairs, &actual_size);
                UTILS_ASSERT_EQUAL(actual_size, expected_size);
                UTILS_ASSERT_COUNT_EQUAL((const char**)actual, expected, expected_size);

                free_array(actual, actual_size);
        }
}
