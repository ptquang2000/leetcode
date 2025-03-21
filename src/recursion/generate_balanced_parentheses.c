#include "utils/asserts.h"

extern char **recursion_generate_balanced_parentheses(int i_num_pairs, int *o_size);

void test_recursion_generate_balanced_parentheses()
{
        string_array actual = {}, expected = {};
        {
                const int num_pairs = 3;
                expected = (string_array){(char *[]){"((()))", "(()())", "(())()", "()(())", "()()()"}, 5};
                actual.data = recursion_generate_balanced_parentheses(num_pairs, &actual.len);
                ASSERT_COUNT_EQUAL(actual, expected);

                free_array(actual.data, actual.len);
        }
        {
                const int num_pairs = 2;
                expected = (string_array){(char *[]){"(())", "()()"}, 2};
                actual.data = recursion_generate_balanced_parentheses(num_pairs, &actual.len);
                ASSERT_COUNT_EQUAL(actual, expected);

                free_array(actual.data, actual.len);
        }
        {
                const int num_pairs = 1;
                expected = (string_array){(char *[]){"()"}, 1};
                actual.data = recursion_generate_balanced_parentheses(num_pairs, &actual.len);
                ASSERT_COUNT_EQUAL(actual, expected);

                free_array(actual.data, actual.len);
        }
}
