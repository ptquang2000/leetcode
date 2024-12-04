#include "utils.h"

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void utils_print(const char* i_format, ...);

#define ASSERT_EQUAL(file, func, line, actual, expect)                                                                 \
    while (actual != expect)                                                                                           \
    {                                                                                                                  \
        utils_print("\n-----------------------------------------------------");                                        \
        utils_print("FAILED: {}", UTYPE(func));                                                                        \
        utils_print("File {} at line {}:", UTYPE(file), UTYPE(line));                                                  \
        utils_print("Expected {} got {}.", UTYPE(expect), UTYPE(actual));                                              \
        utils_print("-----------------------------------------------------\n");                                        \
        __builtin_trap();                                                                                              \
    }

#define ASSERT_ARRAY_EQUAL(file, func, line, size, actual, expect)                                                     \
    int i = 0;                                                                                                         \
    do                                                                                                                 \
    {                                                                                                                  \
        if (!(actual == expect && expect == NULL) && *actual != *expect)                                               \
        {                                                                                                              \
            utils_print("\n-----------------------------------------------------");                                    \
            utils_print("FAILED: {}", UTYPE(func));                                                                    \
            utils_print("File {} at line {}:", UTYPE(file), UTYPE(line));                                              \
            utils_print("Expected {} got {} at index {}.", UTYPE(expect), UTYPE(actual), UTYPE(i));                    \
            utils_print("-----------------------------------------------------\n");                                    \
            __builtin_trap();                                                                                          \
        }                                                                                                              \
        i++;                                                                                                           \
        expect++;                                                                                                      \
        actual++;                                                                                                      \
    } while (i < size);

////////////////////////////////////////////////////////////////////////////////

void utils_format_bool(void* i_value)
{
    bool value = *((bool*)(i_value));
    if (value)
        printf("true");
    else
        printf("false");
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_bool_ptr(void* i_value)
{
    bool* value = *((bool**)(i_value));
    if (*value)
        printf("true");
    else
        printf("false");
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_int(void* i_value)
{
    int value = *((int*)(i_value));
    printf("%d", value);
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_int_ptr(void* i_value)
{
    int* value = *((int**)(i_value));
    printf("%d", *value);
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_char(void* i_value)
{
    char value = *((char*)(i_value));
    printf("\"%c\"", value);
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_char_ptr(void* i_value)
{
    char* value = *((char**)(i_value));
    printf("\"%c\"", *value);
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_string(void* i_value)
{
    char* value = *((char**)(i_value));
    printf("\"%s\"", value);
}

////////////////////////////////////////////////////////////////////////////////

static void (*s_utils_print_format[UTYPE_COUNT])(void*) = {
    utils_format_bool, utils_format_bool_ptr, utils_format_int,    utils_format_int_ptr,
    utils_format_char, utils_format_char_ptr, utils_format_string,
};

////////////////////////////////////////////////////////////////////////////////

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
        s_utils_print_format[type](value);

        next++;
        last = next;
    }
    va_end(args);

    if (last == i_format)
    {
        printf("%s", i_format);
    }

    printf("\n");
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_equal(const char* i_file, const char* i_func, int i_line, UtilsType i_type, ...)
{
    va_list args;
    va_start(args, i_type);

    switch (i_type)
    {
    case UTYPE_BOOL: {
        bool actual = va_arg(args, int);
        bool expect = va_arg(args, int);
        ASSERT_EQUAL(i_file, i_func, i_line, actual, expect);
    }
    break;
    case UTYPE_CHAR: {
        char actual = va_arg(args, int);
        char expect = va_arg(args, int);
        ASSERT_EQUAL(i_file, i_func, i_line, actual, expect);
    }
    break;
    case UTYPE_INT: {
        int actual = va_arg(args, int);
        int expect = va_arg(args, int);
        ASSERT_EQUAL(i_file, i_func, i_line, actual, expect);
    }
    break;
    default:
        assert(false);
    }
    va_end(args);
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_equal_array(const char* i_file, const char* i_func, int i_line, UtilsType i_type, ...)
{
    va_list args;
    va_start(args, i_type);
    switch (i_type)
    {
    case UTYPE_BOOL: {
        bool* actual = va_arg(args, bool*);
        bool* expect = va_arg(args, bool*);
        int size = va_arg(args, int);
        ASSERT_ARRAY_EQUAL(i_file, i_func, i_line, size, actual, expect);
    }
    break;
    case UTYPE_CHAR: {
        char* actual = va_arg(args, char*);
        char* expect = va_arg(args, char*);
        int size = va_arg(args, int);
        ASSERT_ARRAY_EQUAL(i_file, i_func, i_line, size, actual, expect);
    }
    break;
    case UTYPE_INT: {
        int* actual = va_arg(args, int*);
        int* expect = va_arg(args, int*);
        int size = va_arg(args, int);
        ASSERT_ARRAY_EQUAL(i_file, i_func, i_line, size, actual, expect);
    }
    break;
    default:
        printf("Unsupported Type %d\n", i_type);
        assert(false);
    }
    va_end(args);
}

////////////////////////////////////////////////////////////////////////////////
