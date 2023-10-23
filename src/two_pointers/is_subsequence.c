#include "is_subsequence.h"
#include "stdbool.h"
#include "unity.h"

static bool is_subsequence(char *s, char *t)
{
	for (; *t != '\0'; t++) {
		if (*s == '\0') {
			break;
		}
		s = *t == *s ? s + 1 : s;
	}
	return *s == '\0';
}

void test0_is_subsequence(void)
{
	char *s = "abc";
	char *t = "ahbgdc";
	TEST_ASSERT_TRUE(is_subsequence(s, t));
}

void test1_is_subsequence(void)
{
	char *s = "axc";
	char *t = "ahbgdc";
	TEST_ASSERT_FALSE(is_subsequence(s, t));
}

