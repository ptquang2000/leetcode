#include "str_str.h"
#include "unity.h"

static int strStr(char *haystack, char *needle)
{
	char *i, *j, *k;
	for (i = haystack; *i != '\0'; i++) {
		for (j = needle, k = i; *j != '\0' || *k != '\0'; j++, k++) {
			if (*j != *k)  break;
		}
		if (*j == '\0') {
			return i - haystack;
		}
		else if (*k == '\0') {
			break;
		}
	}
	return -1;
}

void test0_str_str(void)
{
	char *haystack = "sadbutsad";	
	char *needle = "sad";
	int expected = 0;

	int output = strStr(haystack, needle);
	TEST_ASSERT_EQUAL_INT(expected, output);
}

void test1_str_str(void)
{
	char *haystack = "leetcode";	
	char *needle = "leeto";
	int expected = -1;

	int output = strStr(haystack, needle);
	TEST_ASSERT_EQUAL_INT(expected, output);
}
