#ifndef UTILS_FORMAT_H
#define UTILS_FORMAT_H

#include "type.h"

#define DELIM "{}"
#define DELIM_LEN (sizeof(DELIM) - 1)
#define FMT_SPECIFIER(v)                                                                                               \
        _Generic((typeof(v)){},                                                                                        \
                char: "%c",                                                                                            \
                const char *: "%s",                                                                                    \
                short: "%hd",                                                                                          \
                int: "%d",                                                                                             \
                size_t: "%zx",                                                                                         \
                float: "%f",                                                                                           \
                default: "%p")

#define __print_decl(data_t)                                                                                           \
        static inline void __print_##data_t(data_t d)                                                                  \
        {                                                                                                              \
                printf(FMT_SPECIFIER(data_t), d);                                                                      \
        }
_function_decl(__print_decl, SUPPORTED_TYPE);
#define __print_helper(v) _Generic((typeof(v)){}, _generic_decl(print, SUPPORTED_TYPE))

#define print_obj(_v, ...)                                                                                             \
        typeof(_v) data;                                                                                               \
        __VA_OPT__(__expand__(print_array(__VA_ARGS__)))
#define print_array(_len, ...)                                                                                         \
        typeof(_len) len;                                                                                              \
        __VA_OPT__(__expand__(print_darray(__VA_ARGS__)))
#define print_darray(_nr) typeof(_nr) nr;

#define log(fmt, ...)                                                                                                  \
        do {                                                                                                           \
                char *__str = fmt;                                                                                     \
                char *__token = strstr(__str, DELIM);                                                                  \
                char *__end = __str + strlen(__str);                                                                   \
                printf("%.*s", (int)((__token ? __token : __end) - __str), __str);                                     \
                __VA_OPT__(__expand__(log_helper(__VA_ARGS__)))                                                        \
        } while (0);
#define log_helper(arg, ...)                                                                                           \
        do {                                                                                                           \
                __str = __token + DELIM_LEN;                                                                           \
                __token = strstr(__str + DELIM_LEN, DELIM);                                                            \
                printf("%.*s", (int)((__token ? __token : __end) - __str), __str);                                     \
                __VA_OPT__(log_recursion PARENS(__VA_ARGS__))                                                          \
        } while (0);
#define log_recursion() log_helper

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

//
// String formatter
// LOG("hello {} from {} with {} times", "me", "world", 3);
//              |
//              V
// log_func(
//      "hello {} from {}",
//      struct { .data="me", .format=str, },
//      struct { .data="world", .format=str, },
//      struct { .data=3,.format=int }
//      );

#endif
