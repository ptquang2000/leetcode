#include "valid_parentheses.h"
#include "stdbool.h"
#include "unity.h"

static bool isValid(char * s) 
{
	char *i, *j;
	for (i = s + 1, j = s; *j != '\0'; i++) {
		if (*i == ')') {
			if (*j == '(') {
				j--;
			} else {
				return false;
			}
		} else if (*i == ']') {
			if (*j == '[') {
				j--;
			} else {
				return false;
			}
		} else if (*i == '}') {
			if (*j == '{') {
				j--;
			} else {
				return false;
			}
		} else {
			j += 1;
		}
	}
	return j == s && *i == '\0';
}

void test0_valid_parentheses(void)
{
	char *s = "()";
	TEST_ASSERT_TRUE(isValid(s));
}

void test1_valid_parentheses(void)
{
	char *s = "()[]{}";
	TEST_ASSERT_TRUE(isValid(s));
}

void test2_valid_parentheses(void)
{
	char *s = "(]";
	TEST_ASSERT_FALSE(isValid(s));
}
