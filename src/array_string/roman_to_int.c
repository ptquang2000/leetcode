#include "roman_to_int.h"
#include "unity.h"
#include <stdio.h>

static int getValue(char c) 
{
	if (c == 'I') return 1;
	if (c == 'V') return 5;
	if (c == 'X') return 10;
	if (c == 'L') return 50;
	if (c == 'C') return 100;
	if (c == 'D') return 500;
	if (c == 'M') return 1000;
	return 0;
}

static int romanToInt(char* s)
{
	int integer = 0;
	while (*s != '\0') {
		if (getValue(*s) < getValue(*(s + 1))) {
			integer -= getValue(*s);
		}
		else {
			integer += getValue(*s);
		}
		s++;
	}
	return integer;
}

void test0_roman_to_int(void)
{
	char* s = "III";
	int expected = 3;
	int output = romanToInt(s);
	
	TEST_ASSERT_EQUAL_INT(expected, output);
}

void test1_roman_to_int(void)
{
	char* s = "LVIII";
	int expected = 58;
	int output = romanToInt(s);
	
	TEST_ASSERT_EQUAL_INT(expected, output);
}

void test2_roman_to_int(void)
{
	char* s = "MCMXCIV";
	int expected = 1994;
	int output = romanToInt(s);
	
	TEST_ASSERT_EQUAL_INT(expected, output);
}
