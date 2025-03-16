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

#define ext_type(ext, ...) __VA_OPT__(__expand__(ext_type_h(ext, __VA_ARGS__)))
#define ext_type_h(ext, type, ...) type##_##ext __VA_OPT__(, ext_type_r PARENS(ext, __VA_ARGS__))
#define ext_type_r() ext_type_h

#define obj_types __expand__(ext_type(obj, SUPPORTED_TYPE))
#define array_types __expand__(ext_type(array, SUPPORTED_TYPE))
#define darray_types __expand__(ext_type(darray, SUPPORTED_TYPE))

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

#define __generic_decl(name, ...) __VA_OPT__(__expand__(__generic_decl_helper(name, __VA_ARGS__)))
#define __generic_decl_helper(name, type, ...)                                                                         \
        type:                                                                                                          \
        name##_##type __VA_OPT__(, __generic_decl_recursion PARENS(name, __VA_ARGS__))
#define __generic_decl_recursion() __generic_decl_helper
#define __printf(v) _Generic((v), __generic_decl(__print, obj_types, array_types, darray_types))(v)

#define utils_log(fmt, ...)                                                                                            \
        do {                                                                                                           \
                char *__str = fmt;                                                                                     \
                char *__token = strstr(__str, DELIM);                                                                  \
                char *__end = __str + strlen(__str);                                                                   \
                printf("%.*s", (int)((__token ? __token : __end) - __str), __str);                                     \
                __VA_OPT__(__expand__(log_helper(__VA_ARGS__)))                                                        \
        } while (0);
#define log_helper(arg, ...)                                                                                           \
        do {                                                                                                           \
                __printf(arg);                                                                                         \
                __str = __token + DELIM_LEN;                                                                           \
                __token = strstr(__str, DELIM);                                                                        \
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
