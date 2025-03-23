#ifndef UTILS_COMPARE_H
#define UTILS_COMPARE_H

#include "array.h"
#include "type.h"

#include <math.h>
#include <string.h>

extern int __cmp_ll_node_obj(ll_node_obj a, ll_node_obj b);
extern int __cmp_bt_node_obj(bt_node_obj a, bt_node_obj b);
extern int __cmp_heap_obj(heap_obj a, heap_obj b);

#define __cmp_integer_def(data_t)                                                                                      \
        static inline int __cmp_##data_t##_obj(data_t##_obj lhs, data_t##_obj rhs)                                     \
        {                                                                                                              \
                return lhs.data < rhs.data ? -1 : lhs.data > rhs.data ? 1 : 0;                                         \
        }
#define __cmp_string_def(data_t)                                                                                       \
        static inline int __cmp_##data_t##_obj(data_t##_obj lhs, data_t##_obj rhs)                                     \
        {                                                                                                              \
                int r = strncmp(lhs.data, rhs.data, strlen(rhs.data));                                                 \
                return r < 0 ? -1 : r > 0 ? 1 : 0;                                                                     \
        }
#define __cmp_floating_def(data_t)                                                                                     \
        static inline int __cmp_##data_t##_obj(data_t##_obj lhs, data_t##_obj rhs)                                     \
        {                                                                                                              \
                return signbit(lhs.data) < signbit(rhs.data)   ? -1                                                    \
                       : signbit(lhs.data) > signbit(rhs.data) ? 1                                                     \
                       : fabs(lhs.data) < fabs(rhs.data)       ? (signbit(lhs.data) ? 1 : -1)                          \
                       : fabs(lhs.data) > fabs(rhs.data)       ? (signbit(lhs.data) ? -1 : 1)                          \
                                                               : 0;                                                          \
        }

#define __cmp_array_def(data_t)                                                                                        \
        static inline int __cmp_##data_t##_array(data_t##_array a, data_t##_array b)                                   \
        {                                                                                                              \
                if (a.len != b.len)                                                                                    \
                        return a.len < b.len ? -1 : 1;                                                                 \
                array_zip(lhs, a, rhs, b)                                                                              \
                {                                                                                                      \
                        int r = __cmp_##data_t##_obj((data_t##_obj){*(lhs)}, (data_t##_obj){*(rhs)});                  \
                        if (r != 0)                                                                                    \
                                return r;                                                                              \
                }                                                                                                      \
                return 0;                                                                                              \
        }

#define __cmp_darray_def(data_t)                                                                                       \
        static inline int __cmp_##data_t##_darray(data_t##_darray a, data_t##_darray b)                                \
        {                                                                                                              \
                if (a.nr != b.nr)                                                                                      \
                        return a.nr < b.nr ? -1 : 1;                                                                   \
                darray_zip(lhs, lr, a, rhs, rr, b)                                                                     \
                {                                                                                                      \
                        if (lr[0] == lhs && rr[0] == rhs) {                                                            \
                                size_t llen = a.len[lr - a.data];                                                      \
                                size_t rlen = b.len[rr - b.data];                                                      \
                                if (llen != rlen)                                                                      \
                                        return llen < rlen ? -1 : 1;                                                   \
                        }                                                                                              \
                        int r = __cmp_##data_t##_obj((data_t##_obj){*(lhs)}, (data_t##_obj){*(rhs)});                  \
                        if (r != 0)                                                                                    \
                                return r;                                                                              \
                }                                                                                                      \
                return 0;                                                                                              \
        }

#define __cmp(a, ...) _Generic((a), __VA_OPT__(__expand__(__cmp_h(__VA_ARGS__))))
#define __cmp_h(type, ...)                                                                                             \
        type##_obj : __cmp_##type##_obj,                                                                               \
                     type##_array : __cmp_##type##_array,                                                              \
                                    type##_darray : __cmp_##type##_darray                                              \
                                                    __VA_OPT__(, __cmp_r PARENS(__VA_ARGS__))
#define __cmp_r() __cmp_h
#define cmp_helper(a, b) __cmp(a, __TYPES__)(a, b)

__function_decl(__cmp_integer_def, __INTEGER__);
__function_decl(__cmp_string_def, __LITERAL__);
__function_decl(__cmp_floating_def, __FLOATING__);
__function_decl(__cmp_array_def, __TYPES__);
__function_decl(__cmp_darray_def, __TYPES__);

#endif
