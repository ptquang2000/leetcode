#include "format.h"
#include "config/autoconf.h"
#include <stdarg.h>

////////////////////////////////////////////////////////////////////////////////

#ifndef CONFIG_BINARY_TREE
void utils_format_btree(size_t i_root)
{
}
#endif

////////////////////////////////////////////////////////////////////////////////

static void (*s_utype_format[UTYPE_COUNT])(size_t) = {
        utils_format_bool,  utils_format_char, utils_format_int,    utils_format_uint64,
        utils_format_float, utils_format_ptr,  utils_format_string, utils_format_btree,
};
static void (*s_uarray_format[UTYPE_COUNT])(size_t, int) = {
        utils_format_bool_array,  utils_format_char_array,    utils_format_int_array,    utils_format_uint64_array,
        utils_format_float_array, utils_format_pointer_array, utils_format_string_array, 0,
};

////////////////////////////////////////////////////////////////////////////////

void utils_format_bool(size_t i_value)
{
        bool value = i_value;
        if (value)
                printf("true");
        else
                printf("false");
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_bool_ptr(size_t i_value)
{
        bool *value = (bool *)i_value;
        if (*value)
                printf("true");
        else
                printf("false");
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_int(size_t i_value)
{
        int value = i_value;
        printf("%d", value);
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_uint64(size_t i_value)
{
        printf("%ld", i_value);
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_float(size_t i_value)
{
        printf("%f", fabsf((float)i_value));
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_int_ptr(size_t i_value)
{
        int *value = (int *)i_value;
        printf("%d", *value);
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_char(size_t i_value)
{
        char value = i_value;
        printf("'%c'", value);
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_char_ptr(size_t i_value)
{
        char *value = (char *)i_value;
        printf("\"%c\"", *value);
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_string(size_t i_value)
{
        typedef const char *string;
        string value = (string)i_value;
        printf("\"%s\"", value);
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_ptr(size_t i_value)
{
        typedef void *pointer;
        pointer value = (pointer)i_value;
        printf("%p", value);
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_bool_array(size_t i_value, int i_size)
{
        bool *arr = (bool *)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++) {
                printf("%s", arr[i] ? "true" : "false");
                if (i != i_size - 1) {
                        printf(", ");
                }
        }
        printf("]");
}
////////////////////////////////////////////////////////////////////////////////

void utils_format_char_array(size_t i_value, int i_size)
{
        char *arr = (char *)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++) {
                printf("'%c'", arr[i]);
                if (i != i_size - 1) {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_int_array(size_t i_value, int i_size)
{
        int *arr = (int *)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++) {
                printf("%d", arr[i]);
                if (i != i_size - 1) {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_uint64_array(size_t i_value, int i_size)
{
        size_t *arr = (size_t *)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++) {
                printf("%ld", arr[i]);
                if (i != i_size - 1) {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_float_array(size_t i_value, int i_size)
{
        float *arr = (float *)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++) {
                printf("%f", fabsf(arr[i]));
                if (i != i_size - 1) {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_string_array(size_t i_value, int i_size)
{
        typedef const char *string;
        string *arr = (string *)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++) {
                printf("\"%s\"", arr[i]);
                if (i != i_size - 1) {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_pointer_array(size_t i_value, int i_size)
{
        typedef void *ptr;
        ptr *arr = (ptr *)i_value;
        printf("[");
        for (int i = 0; i < i_size; i++) {
                printf("%p", arr[i]);
                if (i != i_size - 1) {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

void utils_format_darray(size_t i_value, int i_size)
{
}

////////////////////////////////////////////////////////////////////////////////

typedef union FormatType_struct {
        UtilsType type;
        struct {
                int scalar_type : 6;
                bool is_array : 1;
                bool is_darray : 1;
        };
} FormatType;

////////////////////////////////////////////////////////////////////////////////

void utils_print(const char *i_format, ...)
{
        size_t formatSize = strlen(i_format);
        const char target = '{';
        const char *next = i_format, *last = i_format;

        va_list args;
        va_start(args, i_format);
        while ((next = strchr(next, target)) != NULL && next - i_format < formatSize) {
                printf("%.*s", (int)(next - last), last);

                next++;
                if (*next != '}') {
                        printf("{");
                        last = next;
                        continue;
                } else {
                        next++;
                        last = next;
                }

                FormatType type = va_arg(args, FormatType);
                size_t value = va_arg(args, size_t);
                if (type.is_array) {
                        int size = va_arg(args, int);
                        s_uarray_format[type.scalar_type](value, size);
                } else {
                        s_utype_format[type.scalar_type](value);
                }
        }
        va_end(args);

        if (last == i_format) {
                printf("%s", i_format);
        }

        printf("\n");
}
