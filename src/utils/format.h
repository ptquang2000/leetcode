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

#define __print_obj_decl(data_t)                                                                                       \
        static inline void __print_obj_##data_t(void *data)                                                            \
        {                                                                                                              \
                data_t##_obj obj = *(data_t##_obj *)data;                                                              \
                printf(FMT_SPECIFIER(obj.data), obj.data);                                                             \
        }
__function_decl(__print_obj_decl, SUPPORTED_TYPE);

#define __print_array_decl(data_t)                                                                                     \
        static inline void __print_array_##data_t(void *_p)                                                            \
        {                                                                                                              \
                data_t##_array _a = *(data_t##_array *)_p;                                                             \
                array_foreach(i, _a)                                                                                   \
                {                                                                                                      \
                        if (i == _a.data)                                                                              \
                                printf("[");                                                                           \
                        printf(FMT_SPECIFIER(*i), *i);                                                                 \
                        if (i + 1 == _a.data + _a.len)                                                                 \
                                printf("]");                                                                           \
                        else                                                                                           \
                                printf(",");                                                                           \
                }                                                                                                      \
        }
__function_decl(__print_array_decl, SUPPORTED_TYPE);

#define __print_darray_decl(data_t)                                                                                    \
        static inline void __print_darray_##data_t(void *_p)                                                           \
        {                                                                                                              \
                data_t##_darray _da = *(data_t##_darray *)_p;                                                          \
                darray_foreach(i, _a, _da)                                                                             \
                {                                                                                                      \
                        if (i == _a[0])                                                                                \
                                printf("[");                                                                           \
                        printf(FMT_SPECIFIER(*i), *i);                                                                 \
                        if (_a[0] + _da.len[_a - _da.data] == i + 1)                                                   \
                                printf("]");                                                                           \
                        else                                                                                           \
                                printf(",");                                                                           \
                }                                                                                                      \
        }
__function_decl(__print_darray_decl, SUPPORTED_TYPE);

#define __print_obj_skip(...) __expand__(__print_array(__VA_ARGS__))
#define __print_obj_(data) _Generic((typeof(data)){}, __generic_decl(__print_obj, SUPPORTED_TYPE))
#define __print_obj(data, ...) __print_obj_##__VA_OPT__(skip)((data)__VA_OPT__(, __VA_ARGS__))

#define __print_array_skip(...) __expand__(__print_darray(__VA_ARGS__))
#define __print_array_(data, len) _Generic((typeof(*(data))){}, __generic_decl(__print_array, SUPPORTED_TYPE))
#define __print_array(data, len, ...) __print_array_##__VA_OPT__(skip)((data), (len)__VA_OPT__(, __VA_ARGS__))

#define __print_darray(data, len, nr) _Generic((typeof(**(data))){}, __generic_decl(__print_darray, SUPPORTED_TYPE))

#define print_helper(...) __VA_OPT__(__print_obj(__VA_ARGS__))

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
                arg.print(&arg);                                                                                       \
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

#endif
