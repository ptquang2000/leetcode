#ifndef UTILS_FORMAT_H
#define UTILS_FORMAT_H

#include "type.h"

#define DELIM "{}"
#define DELIM_LEN (sizeof(DELIM) - 1)
#define FMT_SPECIFIER(v)                                                                                               \
        _Generic((typeof(v)){},                                                                                        \
                char: "%c",                                                                                            \
                string: "%s",                                                                                          \
                short: "%hd",                                                                                          \
                int: "%d",                                                                                             \
                size_t: "%zx",                                                                                         \
                double: "%f",                                                                                          \
                default: "%p")

#define __print_obj_def(data_t)                                                                                        \
        static inline void __print_##data_t(data_t obj)                                                                \
        {                                                                                                              \
                printf(FMT_SPECIFIER(obj.data), obj.data);                                                             \
        }
__function_decl(__print_obj_def, obj_types);

#define __print_array_def(data_t)                                                                                      \
        static inline void __print_##data_t(data_t a)                                                                  \
        {                                                                                                              \
                array_foreach(i, a)                                                                                    \
                {                                                                                                      \
                        if (i == a.data)                                                                               \
                                printf("[");                                                                           \
                        printf(FMT_SPECIFIER(*i), *i);                                                                 \
                        if (i + 1 == a.data + a.len)                                                                   \
                                printf("]");                                                                           \
                        else                                                                                           \
                                printf(",");                                                                           \
                }                                                                                                      \
        }
__function_decl(__print_array_def, array_types);

#define __print_darray_def(data_t)                                                                                     \
        static inline void __print_##data_t(data_t da)                                                                 \
        {                                                                                                              \
                darray_foreach(i, a, da)                                                                               \
                {                                                                                                      \
                        if (i == a[0])                                                                                 \
                                printf("[");                                                                           \
                        printf(FMT_SPECIFIER(*i), *i);                                                                 \
                        if (a[0] + da.len[a - da.data] == i + 1)                                                       \
                                printf("]");                                                                           \
                        else                                                                                           \
                                printf(",");                                                                           \
                }                                                                                                      \
        }
__function_decl(__print_darray_def, darray_types);

#define log(fmt, ...)                                                                                                  \
        do {                                                                                                           \
                char *__str = fmt;                                                                                     \
                char *__token = strstr(__str, DELIM);                                                                  \
                char *__end = __str + strlen(__str);                                                                   \
                printf("%.*s", (int)((__token ? __token : __end) - __str), __str);                                     \
                __VA_OPT__(__expand__(__log_h(__VA_ARGS__)))                                                           \
        } while (0);
#define __log_h(arg, ...)                                                                                              \
        do {                                                                                                           \
                _Generic((arg), __print_r PARENS(ALL_TYPES))(arg);                                                     \
                __str = __token + DELIM_LEN;                                                                           \
                __token = strstr(__str, DELIM);                                                                        \
                printf("%.*s", (int)((__token ? __token : __end) - __str), __str);                                     \
                __VA_OPT__(__log_r PARENS(__VA_ARGS__))                                                                \
        } while (0);
#define __log_r() __log_h
#define __print_h(type, ...)                                                                                           \
        type:                                                                                                          \
        __print_##type __VA_OPT__(, __print_r PARENS(__VA_ARGS__))
#define __print_r() __print_h

void utils_format_bool(size_t i_value);
void utils_format_bool_ptr(size_t i_value);
void utils_format_int(size_t i_value);
void utils_format_uint64(size_t i_value);
void utils_format_float(size_t i_value);
void utils_format_int_ptr(size_t i_value);
void utils_format_char(size_t i_value);
void utils_format_char_ptr(size_t i_value);
void utils_format_string(size_t i_value);
void utils_format_ptr(size_t i_value);
void utils_format_btree(size_t i_root);

void utils_format_bool_array(size_t i_value, int i_size);
void utils_format_char_array(size_t i_value, int i_size);
void utils_format_int_array(size_t i_value, int i_size);
void utils_format_uint64_array(size_t i_value, int i_size);
void utils_format_float_array(size_t i_value, int i_size);
void utils_format_string_array(size_t i_value, int i_size);
void utils_format_pointer_array(size_t i_value, int i_size);

#endif
