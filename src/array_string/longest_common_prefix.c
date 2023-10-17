#include "longest_common_prefix.h"
#include "unity.h"
#include <stdlib.h>
#include <string.h>

static char * longestCommonPrefix(char **strs, int strsSize)
{
	char *c = *strs, *str;
	int i, offset;
	while (*c != '\0') {
		offset = c - *strs;

		for (i = 1; i < strsSize; i++) {
			str = *(strs + i) + offset;
			if (*c != *str) {
				*c = '\0';
				return *strs;
			}
		}

		c++;
	}

	return *strs;
}

void test0_longest_common_prefix(void)
{
	char *expected = "fl";
	
	char **strs = calloc(3, sizeof(char*));
	*strs = calloc(7, sizeof(char)); 
	memcpy(*strs, "flower", 7);
	*(strs + 1) = calloc(5, sizeof(char)); 
	memcpy(*(strs + 1), "flow", 5);
	*(strs + 2) = calloc(7, sizeof(char)); 
	memcpy(*(strs + 2), "flight", 7);

	char *output = longestCommonPrefix(strs, 3);
	TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, output, 3);

	free(*strs);
	free(*(strs + 1));
	free(*(strs + 2));
	free(strs);
}

void test1_longest_common_prefix(void)
{
	char *expected = "";

	char **strs = calloc(3, sizeof(char*));
	*strs = calloc(4, sizeof(char)); 
	memcpy(*strs, "dog", 4);
	*(strs + 1) = calloc(7, sizeof(char)); 
	memcpy(*(strs + 1), "racecar", 7);
	*(strs + 2) = calloc(4, sizeof(char)); 
	memcpy(*(strs + 2), "car", 4);

	char *output = longestCommonPrefix(strs, 3);
	TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, output, 1);

	free(*strs);
	free(*(strs + 1));
	free(*(strs + 2));
	free(strs);
}

void test2_longest_common_prefix(void)
{
	char *expected = "a";

	char **strs = calloc(3, sizeof(char*));
	*strs = calloc(2, sizeof(char)); 
	memcpy(*strs, "a", 2);

	char *output = longestCommonPrefix(strs, 1);
	TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, output, 2);

	free(*strs);
	free(strs);
}
