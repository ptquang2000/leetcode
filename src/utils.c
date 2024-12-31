#include "utils.h"

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#ifndef TEST_UTILS
#define UTILS_TRAP __builtin_trap()
#else
#define UTILS_TRAP break
#endif

////////////////////////////////////////////////////////////////////////////////

static void utils_format_bool(size_t i_value)
{
        bool value = i_value;
        if (value)
                printf("true");
        else
                printf("false");
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatBoolPointer(size_t i_value)
{
        bool* value = (bool*)i_value;
        if (*value)
                printf("true");
        else
                printf("false");
}

////////////////////////////////////////////////////////////////////////////////

static void utils_format_int(size_t i_value)
{
        int value = i_value;
        printf("%d", value);
}
////////////////////////////////////////////////////////////////////////////////

static void utils_format_uint64(size_t i_value)
{
        printf("%ld", i_value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatIntPointer(size_t i_value)
{
        int* value = (int*)i_value;
        printf("%d", *value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_format_char(size_t i_value)
{
        char value = i_value;
        printf("'%c'", value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatCharPointer(size_t i_value)
{
        char* value = (char*)i_value;
        printf("\"%c\"", *value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_format_string(size_t i_value)
{
        typedef const char* string;
        string value = (string)i_value;
        printf("\"%s\"", value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_format_pointer(size_t i_value)
{
        typedef void* pointer;
        pointer value = (pointer)i_value;
        printf("\"%p\"", value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_format_bool_array(size_t i_value, int i_size)
{
        bool* arr = (bool*)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++)
        {
                printf("%s", arr[i] ? "true" : "false");
                if (i != i_size - 1)
                {
                        printf(", ");
                }
        }
        printf("]");
}
////////////////////////////////////////////////////////////////////////////////

static void utils_format_char_array(size_t i_value, int i_size)
{
        char* arr = (char*)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++)
        {
                printf("'%c'", arr[i]);
                if (i != i_size - 1)
                {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

static void utils_format_int_array(size_t i_value, int i_size)
{
        int* arr = (int*)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++)
        {
                printf("%d", arr[i]);
                if (i != i_size - 1)
                {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

static void utils_format_uint64_array(size_t i_value, int i_size)
{
        size_t* arr = (size_t*)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++)
        {
                printf("%ld", arr[i]);
                if (i != i_size - 1)
                {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

static void utils_format_string_array(size_t i_value, int i_size)
{
        typedef const char* string;
        string* arr = (string*)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++)
        {
                printf("\"%s\"", arr[i]);
                if (i != i_size - 1)
                {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

static void utils_format_pointer_array(size_t i_value, int i_size)
{
        typedef void* ptr;
        ptr* arr = (ptr*)i_value;
        printf("[");
        for (int i = 0; i < i_size; i++)
        {
                printf("%p", arr[i]);
                if (i != i_size - 1)
                {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

typedef union FormatType_struct {
        UtilsType type;
        struct
        {
                int basicType : 7;
                bool isArray : 1;
        };
} FormatType;

////////////////////////////////////////////////////////////////////////////////

void utils_print(const char* i_format, ...)
{
        static void (*printFormatFunctions[UTYPE_COUNT])(size_t) = {
                utils_format_bool,   utils_format_char,    utils_format_int,
                utils_format_uint64, utils_format_pointer, utils_format_string,
        };
        static void (*printArrarFormatFunctions[UTYPE_COUNT])(size_t, int) = {
                utils_format_bool_array,   utils_format_char_array,    utils_format_int_array,
                utils_format_uint64_array, utils_format_pointer_array, utils_format_string_array,
        };

        size_t formatSize = strlen(i_format);
        const char target = '{';
        const char *next = i_format, *last = i_format;

        va_list args;
        va_start(args, i_format);
        while ((next = strchr(next, target)) != NULL && next - i_format < formatSize)
        {
                printf("%.*s", (int)(next - last), last);

                next++;
                if (*next != '}')
                {
                        printf("{");
                        last = next;
                        continue;
                }
                else
                {
                        next++;
                        last = next;
                }

                FormatType type = va_arg(args, FormatType);
                size_t value = va_arg(args, size_t);
                if (type.isArray)
                {
                        int size = va_arg(args, int);
                        printArrarFormatFunctions[type.basicType](value, size);
                }
                else
                {
                        printFormatFunctions[type.basicType](value);
                }
        }
        va_end(args);

        if (last == i_format)
        {
                printf("%s", i_format);
        }

        printf("\n");
}

////////////////////////////////////////////////////////////////////////////////

static bool is_equal_array(size_t i_actual, size_t i_expected, size_t i_size, size_t i_stride, UtilsType i_type)
{
        typedef const char* string;

        const size_t mask = ((size_t)-1) >> (sizeof(size_t) - i_stride) * 8;
        for (size_t i = 0; i < i_size; i += i_stride)
        {
                if (i_type == UTYPE_STRING)
                {
                        const string lhs = (string)(i_actual + i);
                        const string rhs = (string)(i_expected + i);
                        if (strcmp(lhs, rhs) != 0)
                                return false;
                }
                else
                {
                        const size_t lhs = *(size_t*)(i_actual + i) & mask;
                        const size_t rhs = *(size_t*)(i_expected + i) & mask;
                        if (lhs != rhs)
                                return false;
                }
        }
        return true;
}

////////////////////////////////////////////////////////////////////////////////

static bool is_less_array(size_t i_actual, size_t i_expected, size_t i_size, size_t i_stride, UtilsType i_type)
{
        typedef const char* string;

        const size_t mask = ((size_t)-1) >> (sizeof(size_t) - i_stride) * 8;
        for (size_t i = 0; i < i_size; i += i_stride)
        {
                if (i_type == UTYPE_STRING)
                {
                        const string lhs = (string)(i_actual + i);
                        const string rhs = (string)(i_expected + i);
                        if (strcmp(lhs, rhs) != -1)
                                return false;
                }
                else
                {
                        const size_t lhs = *(size_t*)(i_actual + i) & mask;
                        const size_t rhs = *(size_t*)(i_expected + i) & mask;
                        if (lhs < rhs)
                                return false;
                }
        }
        return true;
}

////////////////////////////////////////////////////////////////////////////////

static bool is_greater_array(size_t i_actual, size_t i_expected, size_t i_size, size_t i_stride, UtilsType i_type)
{
        typedef const char* string;

        const size_t mask = ((size_t)-1) >> (sizeof(size_t) - i_stride) * 8;
        for (size_t i = 0; i < i_size; i += i_stride)
        {
                if (i_type == UTYPE_STRING)
                {
                        const string lhs = (string)(i_actual + i);
                        const string rhs = (string)(i_expected + i);
                        if (strcmp(lhs, rhs) != 1)
                                return false;
                }
                else
                {
                        const size_t lhs = *(size_t*)(i_actual + i) & mask;
                        const size_t rhs = *(size_t*)(i_expected + i) & mask;
                        if (lhs != rhs)
                                return false;
                }
        }
        return true;
}

////////////////////////////////////////////////////////////////////////////////

static bool is_in_array(size_t i_actual, size_t i_expected, size_t i_size, size_t i_stride, UtilsType i_type)
{
        typedef const char* string;
        assert(i_size >= 0 && i_expected != 0);

        const size_t mask = ((size_t)-1) >> (sizeof(size_t) - i_stride) * 8;
        for (size_t i = 0; i < i_size; i += i_stride)
        {
                if (i_type == UTYPE_STRING)
                {
                        const string lhs = (string)(i_actual + 0);
                        const string rhs = (string)(i_expected + i);
                        if (strcmp(lhs, rhs) == 0)
                                return true;
                }
                else
                {
                        const size_t lhs = *(size_t*)(i_actual + 0) & mask;
                        const size_t rhs = *(size_t*)(i_expected + i) & mask;
                        if (lhs == rhs)
                                return true;
                }
        }
        return false;
}

////////////////////////////////////////////////////////////////////////////////

static size_t* construct_count_set(size_t i_data, size_t i_size, size_t i_stride, UtilsType i_type)
{
        size_t* set = calloc(i_size, sizeof(*set));
        for (size_t i = 0; i < i_size; i++)
        {
                if (set[i] == -1)
                        continue;

                set[i] = 1;
                for (size_t j = i + 1; j < i_size; j++)
                {
                        if (!is_equal_array(i_data + i * i_stride, i_data + j * i_stride, 1, i_stride, i_type))
                                continue;

                        set[i]++;
                        set[j] = -1;
                }
        }
        return set;
}

////////////////////////////////////////////////////////////////////////////////

static size_t* construct_count_array_set(size_t i_data, size_t i_size, size_t i_count, size_t i_stride,
                                         size_t i_size_stride, UtilsType i_type)
{
        const size_t mask = ((size_t)-1) >> (sizeof(size_t) - i_size_stride) * 8;
        size_t* data = (size_t*)i_data;
        size_t* set = calloc(i_count, sizeof(*set));
        for (size_t i = 0; i < i_count; i++)
        {
                if (set[i] == -1)
                        continue;

                set[i] = 1;
                for (size_t j = i + 1; j < i_count; j++)
                {
                        const size_t size = *(size_t*)(i_size + j * i_size_stride) & mask;
                        if (!is_equal_array(i_size + i * i_size_stride, i_size + j * i_size_stride, 1, i_size_stride,
                                            i_type) ||
                            !is_equal_array(data[i], data[j], size, i_stride, i_type))
                                continue;

                        set[i]++;
                        set[j] = -1;
                }
        }
        return set;
}

////////////////////////////////////////////////////////////////////////////////

static void print_assert_fail_bool(const char* format, size_t actual, size_t expected)
{
        bool a = actual;
        bool e = expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void print_assert_fail_char(const char* format, size_t actual, size_t expected)
{
        char a = actual;
        char e = expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void print_assert_fail_int(const char* format, size_t actual, size_t expected)
{
        int a = actual;
        int e = expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}
////////////////////////////////////////////////////////////////////////////////

static void print_assert_fail_uint64(const char* format, size_t actual, size_t expected)
{
        uint64_t a = actual;
        uint64_t e = expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void print_assert_fail_string(const char* format, size_t actual, size_t expected)
{
        typedef const char* string;
        string a = (string)actual;
        string e = (string)expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void print_assert_fail_pointer(const char* format, size_t actual, size_t expected)
{
        typedef void* pointer;
        pointer a = (pointer)actual;
        pointer e = (pointer)expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void print_assert_fail_bool_array(const char* format, size_t i_actual, size_t i_expected, size_t i_size)
{
        bool* actual = (bool*)i_actual;
        bool* expected = (bool*)i_expected;
        UTILS_LOG(format, UARRAY(actual, i_size), UARRAY(expected, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_assert_fail_char_array(const char* format, size_t i_actual, size_t i_expected, size_t i_size)
{
        char* actual = (char*)i_actual;
        char* expected = (char*)i_expected;
        UTILS_LOG(format, UARRAY(actual, i_size), UARRAY(expected, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_assert_fail_int_array(const char* format, size_t i_actual, size_t i_expected, size_t i_size)
{
        int* actual = (int*)i_actual;
        int* expected = (int*)i_expected;
        UTILS_LOG(format, UARRAY(actual, i_size), UARRAY(expected, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_assert_fail_uint64_array(const char* format, size_t i_actual, size_t i_expected, size_t i_size)
{
        uint64_t* actual = (uint64_t*)i_actual;
        uint64_t* expected = (uint64_t*)i_expected;
        UTILS_LOG(format, UARRAY(actual, i_size), UARRAY(expected, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_assert_fail_pointer_array(const char* format, size_t i_actual, size_t i_expected, size_t i_size)
{
        typedef void* pointer;
        pointer* actual = (pointer*)i_actual;
        pointer* expected = (pointer*)i_expected;
        UTILS_LOG(format, UARRAY(actual, i_size), UARRAY(expected, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_assert_fail_string_array(const char* format, size_t i_actual, size_t i_expected, size_t i_size)
{
        typedef const char* string;
        string* actual = (string*)i_actual;
        string* expected = (string*)i_expected;
        UTILS_LOG(format, UARRAY(actual, i_size), UARRAY(expected, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_in_array_fail_bool(const char* i_format, size_t i_actual, size_t i_expected, size_t i_size)
{
        bool actual = i_actual;
        bool* expected = (bool*)i_expected;
        UTILS_LOG(i_format, UARRAY(expected, i_size), UTYPE(actual));
}

////////////////////////////////////////////////////////////////////////////////

static void print_in_array_fail_char(const char* i_format, size_t i_actual, size_t i_expected, size_t i_size)
{
        char actual = i_actual;
        char* expected = (char*)i_expected;
        UTILS_LOG(i_format, UARRAY(expected, i_size), UTYPE(actual));
}

////////////////////////////////////////////////////////////////////////////////

static void print_in_array_fail_int(const char* i_format, size_t i_actual, size_t i_expected, size_t i_size)
{
        int actual = i_actual;
        int* expected = (int*)i_expected;
        UTILS_LOG(i_format, UARRAY(expected, i_size), UTYPE(actual));
}

////////////////////////////////////////////////////////////////////////////////

static void print_in_array_fail_uint64(const char* i_format, size_t i_actual, size_t i_expected, size_t i_size)
{
        int actual = i_actual;
        int* expected = (int*)i_expected;
        UTILS_LOG(i_format, UARRAY(expected, i_size), UTYPE(actual));
}

////////////////////////////////////////////////////////////////////////////////

static void print_in_array_fail_pointer(const char* i_format, size_t i_actual, size_t i_expected, size_t i_size)
{
        typedef void* pointer;
        pointer actual = (pointer)i_actual;
        pointer* expected = (pointer*)i_expected;
        UTILS_LOG(i_format, UARRAY(expected, i_size), UTYPE(actual));
}

////////////////////////////////////////////////////////////////////////////////

static void print_in_array_fail_string(const char* i_format, size_t i_actual, size_t i_expected, size_t i_size)
{
        typedef const char* string;
        string actual = (string)i_actual;
        string* expected = (string*)i_expected;
        UTILS_LOG(i_format, UARRAY(expected, i_size), UTYPE(actual));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_fail_bool(size_t i_actual_count, size_t i_expected_count, size_t i_value)
{
        bool value = *(bool*)i_value;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UTYPE(value));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_fail_char(size_t i_actual_count, size_t i_expected_count, size_t i_value)
{
        char value = *(char*)i_value;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UTYPE(value));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_fail_int(size_t i_actual_count, size_t i_expected_count, size_t i_value)
{
        int value = *(int*)i_value;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UTYPE(value));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_fail_uint64(size_t i_actual_count, size_t i_expected_count, size_t i_value)
{
        uint64_t value = *(uint64_t*)i_value;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UTYPE(value));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_fail_pointer(size_t i_actual_count, size_t i_expected_count, size_t i_value)
{
        typedef void* pointer;
        pointer value = *(pointer*)i_value;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UTYPE(value));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_fail_string(size_t i_actual_count, size_t i_expected_count, size_t i_value)
{
        typedef const char* string;
        string value = *(string*)i_value;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UTYPE(value));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_array_fail_bool(size_t i_actual_count, size_t i_expected_count, size_t i_data,
                                              size_t i_size)
{
        bool* data = (bool*)i_data;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UARRAY(data, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_array_fail_char(size_t i_actual_count, size_t i_expected_count, size_t i_data,
                                              size_t i_size)
{
        char* data = (char*)i_data;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UARRAY(data, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_array_fail_int(size_t i_actual_count, size_t i_expected_count, size_t i_data,
                                             size_t i_size)
{
        int* data = (int*)i_data;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UARRAY(data, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_array_fail_uint64(size_t i_actual_count, size_t i_expected_count, size_t i_data,
                                                size_t i_size)
{
        uint64_t* data = (uint64_t*)i_data;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UARRAY(data, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_array_fail_pointer(size_t i_actual_count, size_t i_expected_count, size_t i_data,
                                                 size_t i_size)
{
        typedef void* pointer;
        pointer* data = (pointer*)i_data;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UARRAY(data, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_array_fail_string(size_t i_actual_count, size_t i_expected_count, size_t i_data,
                                                size_t i_size)
{
        typedef const char* string;
        string* data = (string*)i_data;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UARRAY(data, i_size));
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_equal(const char* i_file, const char* i_func, int i_line, UtilsType i_type, size_t i_actual,
                        size_t i_expected, size_t i_stride)
{
        static void (*print_failed_reason[UTYPE_COUNT])(const char*, size_t, size_t) = {
                print_assert_fail_bool, print_assert_fail_char,    print_assert_fail_int,
                print_assert_fail_int,  print_assert_fail_pointer, print_assert_fail_string,
        };

        while (!is_equal_array((size_t)&i_actual, (size_t)&i_expected, i_stride, 1, i_type))
        {
                UTILS_LOG("\n-----------------------------------------------------");
                UTILS_LOG("FAILED: {}", UTYPE(i_func));
                UTILS_LOG("File {} at line {}:", UTYPE(i_file), UTYPE(i_line));
                print_failed_reason[i_type]("Expected {} got {}.", i_actual, i_expected);
                UTILS_LOG("-----------------------------------------------------\n");
                UTILS_TRAP;
        }
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_less(const char* i_file, const char* i_func, int i_line, UtilsType i_type, size_t i_actual,
                       size_t i_expected, size_t i_stride)
{
        static void (*print_failed_reason[UTYPE_COUNT])(const char*, size_t, size_t) = {
                print_assert_fail_bool, print_assert_fail_char,    print_assert_fail_int,
                print_assert_fail_int,  print_assert_fail_pointer, print_assert_fail_string,
        };

        while (!is_less_array((size_t)&i_actual, (size_t)&i_expected, 1, i_stride, i_type))
        {
                UTILS_LOG("\n-----------------------------------------------------");
                UTILS_LOG("FAILED: {}", UTYPE(i_func));
                UTILS_LOG("File {} at line {}:", UTYPE(i_file), UTYPE(i_line));
                print_failed_reason[i_type]("Expected less than {} got {}.", i_actual, i_expected);
                UTILS_LOG("-----------------------------------------------------\n");
                UTILS_TRAP;
        }
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_greater(const char* i_file, const char* i_func, int i_line, UtilsType i_type, size_t i_actual,
                          size_t i_expected, size_t i_stride)
{
        static void (*print_failed_reason[UTYPE_COUNT])(const char*, size_t, size_t) = {
                print_assert_fail_bool, print_assert_fail_char,    print_assert_fail_int,
                print_assert_fail_int,  print_assert_fail_pointer, print_assert_fail_string,
        };

        while (!is_greater_array((size_t)&i_actual, (size_t)&i_expected, 1, i_stride, i_type))
        {
                UTILS_LOG("\n-----------------------------------------------------");
                UTILS_LOG("FAILED: {}", UTYPE(i_func));
                UTILS_LOG("File {} at line {}:", UTYPE(i_file), UTYPE(i_line));
                print_failed_reason[i_type]("Expected greater {} got {}.", i_actual, i_expected);
                UTILS_LOG("-----------------------------------------------------\n");
                UTILS_TRAP;
        }
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_equal_array(const char* i_file, const char* i_func, int i_line, UtilsType i_type, size_t i_actual,
                              size_t i_expected, size_t i_size, size_t i_stride)
{
        static void (*print_failed_reason[UTYPE_COUNT])(const char*, size_t, size_t, size_t) = {
                print_assert_fail_bool_array,   print_assert_fail_char_array,    print_assert_fail_int_array,
                print_assert_fail_uint64_array, print_assert_fail_pointer_array, print_assert_fail_string_array,
        };

        while (!is_equal_array(i_actual, i_expected, i_stride, i_size, i_type))
        {
                UTILS_LOG("\n-----------------------------------------------------");
                UTILS_LOG("FAILED: {}", UTYPE(i_func));
                UTILS_LOG("File {} at line {}:", UTYPE(i_file), UTYPE(i_line));
                print_failed_reason[i_type]("Expected {} got {}.", i_actual, i_expected, i_size);
                UTILS_LOG("-----------------------------------------------------\n");
                UTILS_TRAP;
        }
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_less_array(const char* i_file, const char* i_func, int i_line, UtilsType i_type, size_t i_actual,
                             size_t i_expected, size_t i_size, size_t i_stride)
{
        static void (*print_failed_reason[UTYPE_COUNT])(const char*, size_t, size_t) = {
                print_assert_fail_bool, print_assert_fail_char,    print_assert_fail_int,
                print_assert_fail_int,  print_assert_fail_pointer, print_assert_fail_string,
        };

        while (!is_less_array(i_actual, i_expected, i_size, i_stride, i_type))
        {
                UTILS_LOG("\n-----------------------------------------------------");
                UTILS_LOG("FAILED: {}", UTYPE(i_func));
                UTILS_LOG("File {} at line {}:", UTYPE(i_file), UTYPE(i_line));
                print_failed_reason[i_type]("Expected less than {} got {}.", i_actual, i_expected);
                UTILS_LOG("-----------------------------------------------------\n");
                UTILS_TRAP;
        }
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_greater_array(const char* i_file, const char* i_func, int i_line, UtilsType i_type, size_t i_actual,
                                size_t i_expected, size_t i_size, size_t i_stride)
{
        static void (*print_failed_reason[UTYPE_COUNT])(const char*, size_t, size_t) = {
                print_assert_fail_bool, print_assert_fail_char,    print_assert_fail_int,
                print_assert_fail_int,  print_assert_fail_pointer, print_assert_fail_string,
        };

        while (!is_greater_array(i_actual, i_expected, i_size, i_stride, i_type))
        {
                UTILS_LOG("\n-----------------------------------------------------");
                UTILS_LOG("FAILED: {}", UTYPE(i_func));
                UTILS_LOG("File {} at line {}:", UTYPE(i_file), UTYPE(i_line));
                print_failed_reason[i_type]("Expected greater {} got {}.", i_actual, i_expected);
                UTILS_LOG("-----------------------------------------------------\n");
                UTILS_TRAP;
        }
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_in_array(const char* i_file, const char* i_func, int i_line, UtilsType i_type, size_t i_actual,
                           size_t i_expected, size_t i_size, size_t i_stride)
{
        static void (*print_failed_reason[UTYPE_COUNT])(const char*, size_t, size_t, size_t) = {
                print_in_array_fail_bool,   print_in_array_fail_char,    print_in_array_fail_int,
                print_in_array_fail_uint64, print_in_array_fail_pointer, print_in_array_fail_string,
        };

        while (!is_in_array((size_t)&i_actual, i_expected, i_size, i_stride, i_type))
        {
                UTILS_LOG("\n-----------------------------------------------------");
                UTILS_LOG("FAILED: {}", UTYPE(i_func));
                UTILS_LOG("File {} at line {}:", UTYPE(i_file), UTYPE(i_line));
                print_failed_reason[i_type]("Expected {} got {}.", i_actual, i_expected, i_size);
                UTILS_LOG("-----------------------------------------------------\n");
                UTILS_TRAP;
        }
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_count_equal(const char* i_file, const char* i_func, int i_line, UtilsType i_type, size_t i_actual,
                              size_t i_expected, size_t i_size, size_t i_stride)
{
        size_t* actual_set = construct_count_set(i_actual, i_size, i_stride, i_type);
        size_t* expected_set = construct_count_set(i_expected, i_size, i_stride, i_type);

        static void (*print_fail_funtions[UTYPE_COUNT])(size_t, size_t, size_t) = {
                print_count_equal_fail_bool,   print_count_equal_fail_char,    print_count_equal_fail_int,
                print_count_equal_fail_uint64, print_count_equal_fail_pointer, print_count_equal_fail_string,
        };

        bool is_asserted = false;
        for (size_t i = 0; i < i_size; i++)
        {
                if (actual_set[i] == -1)
                        continue;

                size_t j, min = 0, actual_remain = actual_set[i], expected_remain = 0;
                for (j = 0; j < i_size; j++)
                {
                        if (expected_set[j] == -1)
                                continue;

                        if (!is_equal_array(i_actual + i * i_stride, i_expected + j * i_stride, 1, i_stride, i_type))
                                continue;

                        min = actual_set[i] < expected_set[j] ? actual_set[i] : expected_set[j];
                        actual_remain -= min;
                        expected_remain = expected_set[j] - min;
                        break;
                }

                actual_set[i] = -1;
                if (j < i_size)
                        expected_set[j] = -1;

                if (actual_remain == expected_remain && actual_remain == 0)
                        continue;

                if (!is_asserted)
                {
                        UTILS_LOG("\n-----------------------------------------------------");
                        UTILS_LOG("FAILED: {}", UTYPE(i_func));
                        UTILS_LOG("File {} at line {}:", UTYPE(i_file), UTYPE(i_line));
                        is_asserted = true;
                }

                print_fail_funtions[i_type](actual_remain + min, expected_remain + min, i_actual + i * i_stride);
        }

        for (size_t i = 0; i < i_size; i++)
        {
                if (expected_set[i] == -1)
                        continue;

                print_fail_funtions[i_type](0, expected_set[i], i_expected + i * i_stride);
                expected_set[i] = -1;
        }

        free(actual_set);
        free(expected_set);

        while (is_asserted)
        {
                UTILS_LOG("-----------------------------------------------------\n");
                UTILS_TRAP;
        }
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_count_equal_array(const char* i_file, const char* i_func, int i_line, UtilsType i_type,
                                    size_t i_actual, size_t i_actual_size, size_t i_expected, size_t i_expected_size,
                                    size_t i_count, size_t i_stride, size_t i_size_stride)
{
        const size_t mask = ((size_t)-1) >> (sizeof(size_t) - i_size_stride) * 8;
        size_t* actual = (size_t*)i_actual;
        size_t* expected = (size_t*)i_expected;
        size_t* actual_set =
                construct_count_array_set(i_actual, i_actual_size, i_count, i_stride, i_size_stride, i_type);
        size_t* expected_set =
                construct_count_array_set(i_expected, i_expected_size, i_count, i_stride, i_size_stride, i_type);

        static void (*print_fail_funtions[UTYPE_COUNT])(size_t, size_t, size_t, size_t) = {
                print_count_equal_array_fail_bool,    print_count_equal_array_fail_char,
                print_count_equal_array_fail_int,     print_count_equal_array_fail_uint64,
                print_count_equal_array_fail_pointer, print_count_equal_array_fail_string,
        };

        bool is_asserted = false;
        for (size_t i = 0; i < i_count; i++)
        {
                if (actual_set[i] == -1)
                        continue;

                size_t j, min = 0, actual_remain = actual_set[i], expected_remain = 0;
                const size_t actual_size = *(size_t*)(i_actual_size + i * i_size_stride) & mask;
                for (j = 0; j < i_count; j++)
                {
                        if (expected_set[j] == -1)
                                continue;

                        if (!is_equal_array(i_actual_size + i * i_size_stride, i_expected_size + j * i_size_stride, 1,
                                            i_size_stride, i_type) ||
                            !is_equal_array(actual[i], expected[j], actual_size, i_stride, i_type))
                                continue;

                        min = actual_set[i] < expected_set[j] ? actual_set[i] : expected_set[j];
                        actual_remain -= min;
                        expected_remain = expected_set[j] - min;
                        break;
                }

                actual_set[i] = -1;
                if (j < i_count)
                        expected_set[j] = -1;

                if (actual_remain == expected_remain && actual_remain == 0)
                        continue;

                if (!is_asserted)
                {
                        UTILS_LOG("\n-----------------------------------------------------");
                        UTILS_LOG("FAILED: {}", UTYPE(i_func));
                        UTILS_LOG("File {} at line {}:", UTYPE(i_file), UTYPE(i_line));
                        is_asserted = true;
                }

                print_fail_funtions[i_type](actual_remain + min, expected_remain + min, actual[i], actual_size);
        }

        for (size_t i = 0; i < i_count; i++)
        {
                if (expected_set[i] == -1)
                        continue;

                const size_t expected_size = (i * i_size_stride)[(size_t*)i_expected_size] & mask;
                print_fail_funtions[i_type](0, expected_set[i], expected[i], expected_size);
                expected_set[i] = -1;
        }

        free(actual_set);
        free(expected_set);

        while (is_asserted)
        {
                UTILS_LOG("-----------------------------------------------------\n");
                UTILS_TRAP;
        }
}

////////////////////////////////////////////////////////////////////////////////
