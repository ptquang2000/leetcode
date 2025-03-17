#ifndef UTILS_ASSERTS_H
#define UTILS_ASSERTS_H

#include <stdio.h>

#include "compare.h"
#include "config/autoconf.h"
#include "logger.h"

#if CONFIG_UTILS_TEST == 1
#undef __builtin_trap
#define __builtin_trap() return;
#endif

#define assert_msg(cond, msg)                                                                                          \
        do {                                                                                                           \
                if (!(cond))                                                                                           \
                        utils_log("{}", (string_obj){msg});                                                            \
        } while (0)

#define assert_equal(a, b) assert_equal_helper(a, b)

#define assert_count_equal

#define assert_in

struct btree_node;
#define UTILS_ASSERT_MSG(cond, ...)                                                                                    \
        do {                                                                                                           \
                if (!(cond)) {                                                                                         \
                        UTILS_LOG(__VA_ARGS__);                                                                        \
                        __builtin_trap();                                                                              \
                }                                                                                                      \
        } while (0)

#define __assert_equal_obj_def(data_t)                                                                                 \
        static inline void __assert_equal_##data_t##_obj(const char *f, const char *fn, int l, data_t##_obj a,         \
                                                         data_t##_obj e)                                               \
        {                                                                                                              \
                if (__cmp_##data_t##_obj(a, e) != 0) {                                                                 \
                        printf("\n-----------------------------------------------------\n");                           \
                        printf("FAILED: %s\nFile %s at line %d:\n", fn, f, l);                                         \
                        printf("Expected ");                                                                           \
                        __print_##data_t##_obj(e);                                                                     \
                        printf(" got ");                                                                               \
                        __print_##data_t##_obj(a);                                                                     \
                        printf("\n-----------------------------------------------------\n\n");                         \
                        __builtin_trap();                                                                              \
                }                                                                                                      \
        }
#define __assert_equal_array_def(data_t)                                                                               \
        static inline void __assert_equal_##data_t##_array(const char *f, const char *fn, int l, data_t##_array a,     \
                                                           data_t##_array e)                                           \
        {                                                                                                              \
                array_zip(i, a, j, e)                                                                                  \
                {                                                                                                      \
                        if (__cmp_##data_t##_obj((data_t##_obj){*i}, (data_t##_obj){*j}) != 0) {                       \
                                printf("\n-----------------------------------------------------\n");                   \
                                printf("FAILED: %s\nFile %s at line %d:\n", fn, f, l);                                 \
                                printf("Expected ");                                                                   \
                                __print_##data_t##_array(e);                                                           \
                                printf(" got ");                                                                       \
                                __print_##data_t##_array(a);                                                           \
                                printf("\n-----------------------------------------------------\n\n");                 \
                                __builtin_trap();                                                                      \
                        }                                                                                              \
                }                                                                                                      \
        }
#define __assert_equal_darray_def(data_t)                                                                              \
        static inline void __assert_equal_##data_t##_darray(const char *f, const char *fn, int l, data_t##_darray a,   \
                                                            data_t##_darray e)                                         \
        {                                                                                                              \
        }

#define __assert_equal(a, ...) _Generic((a), __VA_OPT__(__expand__(__assert_equal_h(__VA_ARGS__))))
#define __assert_equal_h(type, ...)                                                                                    \
        type##_obj : __assert_equal_##type##_obj,                                                                      \
                     type##_array : __assert_equal_##type##_array,                                                     \
                                    type##_darray : __assert_equal_##type##_darray                                     \
                                                    __VA_OPT__(, __assert_equal_r PARENS(__VA_ARGS__))
#define __assert_equal_r() __assert_equal_h
#define assert_equal_helper(a, b) __assert_equal(a, __TYPES__)(__FILE__, __FUNCTION__, __LINE__, a, b)

__function_decl(__assert_equal_obj_def, __TYPES__);
__function_decl(__assert_equal_array_def, __TYPES__);
__function_decl(__assert_equal_darray_def, __TYPES__);

#endif
