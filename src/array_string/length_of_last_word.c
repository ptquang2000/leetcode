#include "length_of_last_word.h"
#include "unity.h"
#include <stdio.h>

static int lengthOfLastWord(char* s)
{
	int length = 0, lastWordLength;
	while (*s != '\0') {
		if (*s == ' ') {
			length = 0;
		}
		else {
			length++;
			lastWordLength = length;
		}
		s++;
	}
	return lastWordLength;
}

void test0_length_of_last_word(void)
{
	char* s = "Hello World";
	int expected = 5;

	int output = lengthOfLastWord(s);
	TEST_ASSERT_EQUAL_INT(expected, output);
}

void test1_length_of_last_word(void)
{
	char* s = "   fly me   to   the moon  ";
	int expected = 4;

	int output = lengthOfLastWord(s);
	TEST_ASSERT_EQUAL_INT(expected, output);
}

void test2_length_of_last_word(void)
{
	char* s = "luffy is still joyboy";
	int expected = 6;

	int output = lengthOfLastWord(s);
	TEST_ASSERT_EQUAL_INT(expected, output);
}
