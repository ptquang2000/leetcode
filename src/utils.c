#include <stdio.h>

void utils_format_int(int i_value, char *o_buffer)
{
    sprintf(o_buffer, "%d", i_value);
}

#define UTILS_FORMAT(value, ...) _Generic((value), int: utils_format_int)(value, __VA_ARGS__)

void utils_prolouge_failed_message(char *i_file, const char *i_func, int i_line)
{
    printf("FAILED: %s\n", i_func);
    printf("File \"%s\" at line %d: \n", i_file, i_line);
}

void utils_assert_equal_int(int i_actual, int i_expect, char *i_file, const char *i_func, int i_line)
{
    while (i_actual != i_expect)
    {
        utils_prolouge_failed_message(i_file, i_func, i_line);
        char buffer[128];
        printf("Expected ");
        UTILS_FORMAT(i_expect, buffer);
        printf("%s", buffer);
        printf(" got ");
        UTILS_FORMAT(i_actual, buffer);
        printf("%s", buffer);
        printf(".\n");

        __builtin_trap();
    }
}
