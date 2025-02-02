#include "pch.h"

extern int array_string_removeElement(int* nums, int numsSize, int val);

static void tc1()
{
        array_string_removeElement(0, 0, 0);
}

static void tc2()
{
        array_string_removeElement(0, 0, 0);
}

void test_array_string_removeElement()
{
        printf("hello from test_removeElement\n");
        tc1();
        tc2();
}
