#include "is_palindrome.h"
#include "stdbool.h"
#include "unity.h"
#include "stdlib.h"
#include "string.h"
#include <stdio.h>

static bool isPalindrome(char *s)
{
	int len = 0;
	for (char *i = s; *i != '\0'; i++) {
		bool is_az = 'a' <= *i && *i <= 'z';
		bool is_AZ = 'A' <= *i && *i <= 'Z';
		bool is_09 = '0' <= *i && *i <= '9';

		if (!is_az && !is_AZ && !is_09) {
			*(s + len) = *(i + 1);
			continue;
		}

		len += 1;
		if (is_AZ) {
			*(s + len - 1) = *i + ('a' - 'A');
		} else {
			*(s + len - 1) = *i;
		}
	}

	if (len < 2) return true;

	char *s1, *s2;
	for (s1 = s, s2 = s + len - 1; *s1 == *s2 && s1 < s2; s1++, s2--);
	return s1 == s2 || s1 == s2 + 1;
}

void test0_is_palindrome(void)
{
	char *s = "A man, a plan, a canal: Panama";
	bool expected = true;
	
	char *str = malloc(sizeof( *s) * (strlen(s) + 1));
	memcpy(str, s, strlen(s) + 1);
	bool output = isPalindrome(str);
	TEST_ASSERT_EQUAL_size_t(expected, output);
	free(str);
}

void test1_is_palindrome(void)
{
	char *s = "race a car";
	bool expected = false;
	
	char *str = malloc(sizeof( *s) * (strlen(s) + 1));
	memcpy(str, s, strlen(s) + 1);
	bool output = isPalindrome(str);
	TEST_ASSERT_EQUAL_size_t(expected, output);
	free(str);
}

void test2_is_palindrome(void)
{
	char *s = " ";
	bool expected = true;
	
	char *str = malloc(sizeof( *s) * (strlen(s) + 1));
	memcpy(str, s, strlen(s) + 1);
	bool output = isPalindrome(str);
	TEST_ASSERT_EQUAL_size_t(expected, output);
	free(str);
}

void test3_is_palindrome(void)
{
	char *s = "abb";
	bool expected = false;
	
	char *str = malloc(sizeof( *s) * (strlen(s) + 1));
	memcpy(str, s, strlen(s) + 1);
	bool output = isPalindrome(str);
	TEST_ASSERT_EQUAL_size_t(expected, output);
	free(str);
}

void test4_is_palindrome(void)
{
	char *s = "1a2";
	bool expected = false;
	
	char *str = malloc(sizeof( *s) * (strlen(s) + 1));
	memcpy(str, s, strlen(s) + 1);
	bool output = isPalindrome(str);
	TEST_ASSERT_EQUAL_size_t(expected, output);
	free(str);
}

void test5_is_palindrome(void) 
{
	char *s = "aa";
	bool expected = true;
	
	char *str = malloc(sizeof( *s) * (strlen(s) + 1));
	memcpy(str, s, strlen(s) + 1);
	bool output = isPalindrome(str);
	TEST_ASSERT_EQUAL_size_t(expected, output);
	free(str);
}

void test6_is_palindrome(void)
{
	char *s = "a";
	bool expected = true;
	
	char *str = malloc(sizeof( *s) * (strlen(s) + 1));
	memcpy(str, s, strlen(s) + 1);
	bool output = isPalindrome(str);
	TEST_ASSERT_EQUAL_size_t(expected, output);
	free(str);
}

void test7_is_palindrome(void)
{
	char *s = "a ba";
	bool expected = true;
	
	char *str = malloc(sizeof( *s) * (strlen(s) + 1));
	memcpy(str, s, strlen(s) + 1);
	bool output = isPalindrome(str);
	TEST_ASSERT_EQUAL_size_t(expected, output);
	free(str);
}

void test8_is_palindrome(void)
{
	char *s = "Eve, mad Adam, Eve!";
	bool expected = true;
	
	char *str = malloc(sizeof( *s) * (strlen(s) + 1));
	memcpy(str, s, strlen(s) + 1);
	bool output = isPalindrome(str);
	TEST_ASSERT_EQUAL_size_t(expected, output);
	free(str);
}

