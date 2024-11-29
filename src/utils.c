#include "utils.h"

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef enum UtilsType_enum
{
    UTYPE_BOOL,
    UTYPE_INT,
    UTYPE_INT_PTR,
    UTYPE_CHAR,
    UTYPE_STRING,
    UTYPE_COUNT,
} UtilsType;

#define UTYPE(value)                                                                                                   \
    _Generic((value),                                                                                                  \
        int: UTYPE_INT,                                                                                                \
        int*: UTYPE_INT_PTR,                                                                                           \
        char: UTYPE_CHAR,                                                                                              \
        char*: UTYPE_STRING,                                                                                           \
        const char*: UTYPE_STRING),                                                                                    \
        &value

void utils_print_format(UtilsType i_type, void* i_value)
{
    char buffer[128];
    switch (i_type)
    {
    case UTYPE_BOOL: {
        bool value = *((bool*)(i_value));
        if (value)
        {
            printf("true");
        }
        else
        {
            printf("false");
        }
    }
    break;
    case UTYPE_INT: {
        int value = *((int*)(i_value));
        printf("%d", value);
    }
    break;
    case UTYPE_INT_PTR: {
        int* value = *((int**)(i_value));
        printf("%d", *value);
    }
    break;
    case UTYPE_CHAR: {
        char value = *((char*)(i_value));
        printf("%c", value);
    }
    break;
    case UTYPE_STRING: {
        char* value = *((char**)(i_value));
        printf("%s", value);
    }
    break;
    default:
        printf("Unsupported printing format");
        assert(false);
    }
}

void utils_print(const char* i_format, ...)
{
    size_t formatSize = strlen(i_format);
    const char target = '{';
    const char *next = i_format, *last = i_format;

    va_list args;
    va_start(args, i_format);
    while ((next = strchr(next, target)) != NULL && next - i_format < formatSize)
    {
        printf("%.*s", (int)(next - last), last);

        next++;
        assert(*next == '}');

        UtilsType type = va_arg(args, UtilsType);
        void* value = va_arg(args, void*);
        utils_print_format(type, value);

        next++;
        last = next;
    }
    va_end(args);

    printf("\n");
}

void utils_assert_equal_int(char* i_file, const char* i_func, int i_line, int i_actual, int i_expect)
{
    while (i_actual != i_expect)
    {
        utils_print("FAILED: {}", UTYPE(i_func));
        utils_print("File \"{}\" at line {}:", UTYPE(i_file), UTYPE(i_line));
        utils_print("Expected {} got {}.", UTYPE(i_expect), UTYPE(i_actual));

        __builtin_trap();
    }
}

void utils_assert_equal_int_array(char* i_file, const char* i_func, int i_line, int* i_actual, int* i_expect,
                                  int i_size)
{
    int i = 0;
    char buffer[128];
    while (i < i_size)
    {
        if (*i_actual != *i_expect)
        {
            utils_print("FAILED: {}", UTYPE(i_func));
            utils_print("File \"{}\" at line {}:", UTYPE(i_file), UTYPE(i_line));
            utils_print("Expected {} got {} at index {}.", UTYPE(i_expect), UTYPE(i_actual), UTYPE(i));

            __builtin_trap();
        }

        i++;
        i_expect++;
        i_actual++;
    }
}
