#ifndef UTILS_FORMAT_H
#define UTILS_FORMAT_H

#include "helper.h"
#include "type.h"

#define DELIM "{}"
#define DELIM_LEN (sizeof(DELIM) - 1)
#define __printf(v)                                                                                                    \
        printf(_Generic((v),                                                                                           \
                       bool: "%s",                                                                                     \
                       char: "'%c'",                                                                                   \
                       string: "\"%s\"",                                                                               \
                       short: "%hd",                                                                                   \
                       int: "%d",                                                                                      \
                       size_t: "0x%zx",                                                                                \
                       double: "%f",                                                                                   \
                       default: "%p"),                                                                                 \
               _Generic((v), bool: ((v) ? "true" : "false"), default: (v)))

#define __print_obj_def(data_t)                                                                                        \
        static inline void __print_##data_t##_obj(data_t##_obj obj)                                                    \
        {                                                                                                              \
                __printf(obj.data);                                                                                    \
        }

#define __print_array_def(data_t)                                                                                      \
        static inline void __print_##data_t##_array(data_t##_array a)                                                  \
        {                                                                                                              \
                array_foreach(i, a)                                                                                    \
                {                                                                                                      \
                        if (i == a.data)                                                                               \
                                printf("[");                                                                           \
                        __printf(*i);                                                                                  \
                        if (i + 1 == a.data + a.len)                                                                   \
                                printf("]");                                                                           \
                        else                                                                                           \
                                printf(",");                                                                           \
                }                                                                                                      \
        }

#define __print_darray_def(data_t)                                                                                     \
        static inline void __print_##data_t##_darray(data_t##_darray da)                                               \
        {                                                                                                              \
                printf("[");                                                                                           \
                darray_foreach(i, a, da)                                                                               \
                {                                                                                                      \
                        if (i == a[0])                                                                                 \
                                printf("[");                                                                           \
                        __printf(*i);                                                                                  \
                        if (a[0] + da.len[a - da.data] == i + 1) {                                                     \
                                printf("]");                                                                           \
                                if (a - da.data < da.nr - 1)                                                           \
                                        printf(",");                                                                   \
                        } else                                                                                         \
                                printf(",");                                                                           \
                }                                                                                                      \
                printf("]");                                                                                           \
        }

#define utils_log(fmt, ...)                                                                                            \
        do {                                                                                                           \
                char *__str = fmt "\n";                                                                                \
                char *__token = strstr(__str, DELIM);                                                                  \
                char *__end = __str + strlen(__str);                                                                   \
                printf("%.*s", (int)((__token ? __token : __end) - __str), __str);                                     \
                __VA_OPT__(__expand__(__log_h(__VA_ARGS__)))                                                           \
        } while (0);
#define __log_h(arg, ...)                                                                                              \
        do {                                                                                                           \
                _Generic((arg), __print_r PARENS(__TYPES__))(arg);                                                     \
                __str = __token + DELIM_LEN;                                                                           \
                __token = strstr(__str, DELIM);                                                                        \
                printf("%.*s", (int)((__token ? __token : __end) - __str), __str);                                     \
                __VA_OPT__(__log_r PARENS(__VA_ARGS__))                                                                \
        } while (0);
#define __log_r() __log_h
#define __print_h(type, ...)                                                                                           \
        type##_obj : __print_##type##_obj,                                                                             \
                     type##_array : __print_##type##_array,                                                            \
                                    type##_darray : __print_##type##_darray                                            \
                                                    __VA_OPT__(, __print_r PARENS(__VA_ARGS__))
#define __print_r() __print_h

__function_decl(__print_obj_def, __TYPES__);
__function_decl(__print_array_def, __TYPES__);
__function_decl(__print_darray_def, __TYPES__);

#endif
