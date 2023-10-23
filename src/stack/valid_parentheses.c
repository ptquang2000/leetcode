#include "valid_parentheses.h"
#include "stdbool.h"
#include "unity.h"

static bool isValid(char * s) 
{
	char stack[10000] = {};
	int size = 0;
	for (; *s != '\0'; s++) {
		if (*s == ')' && size > 0 && stack[size - 1] == '(') {
			size--;
		} else if (*s == ']' && size > 0 && stack[size - 1] == '[') {
			size--;
		} else if (*s == '}' && size > 0 && stack[size - 1] == '{') {
			size--;
		} else if (*s == '(' || *s == '[' || *s == '{') {
			stack[size] = *s;
			size++;
		} else {
			return false;
		}
	}
	return size == 0 && *s == '\0';
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
