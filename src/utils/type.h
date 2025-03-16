#ifndef UTILS_TYPE_H
#define UTILS_TYPE_H

#include "utils.h"

typedef char *string;
#define __FLOATING__ double
#define __INTEGER__ char, short, int, size_t
#define __CHARACTER__ string
#define SUPPORTED_TYPE __CHARACTER__, __INTEGER__, __FLOATING__

#define struct_tmpl(...)                                                                                               \
        struct {                                                                                                       \
                __VA_OPT__(__expand__(__struct_obj(__VA_ARGS__)))                                                      \
        }

#define __struct_obj_skip(...) __expand__(__struct_array(__VA_ARGS__))
#define __struct_obj_(_data) typeof(_data) data;
#define __struct_obj(data, ...) __struct_obj_##__VA_OPT__(skip)(data __VA_OPT__(, __VA_ARGS__))

#define __struct_array_skip(...) __expand__(__struct_darray(__VA_ARGS__))
#define __struct_array_(_data, _len)                                                                                   \
        typeof(*_data) *data;                                                                                          \
        typeof(_len) len;
#define __struct_array(data, len, ...) __struct_array_##__VA_OPT__(skip)(data, len __VA_OPT__(, __VA_ARGS__))

#define __struct_darray(_data, _len, _nr)                                                                              \
        typeof(**_data) **data;                                                                                        \
        typeof(*_len) *len;                                                                                            \
        typeof(_nr) nr;

typedef struct_tmpl(char) char_obj;
typedef struct_tmpl(string) string_obj;
typedef struct_tmpl(short) short_obj;
typedef struct_tmpl(int) int_obj;
typedef struct_tmpl(size_t) size_t_obj;
typedef struct_tmpl(double) double_obj;

typedef struct_tmpl((char *){}, size_t) char_array;
typedef struct_tmpl((string *){}, size_t) string_array;
typedef struct_tmpl((short *){}, size_t) short_array;
typedef struct_tmpl((int *){}, size_t) int_array;
typedef struct_tmpl((size_t *){}, size_t) size_t_array;
typedef struct_tmpl((double *){}, size_t) double_array;

typedef struct_tmpl((char **){}, (int *){}, size_t) char_darray;
typedef struct_tmpl((string **){}, (int *){}, size_t) string_darray;
typedef struct_tmpl((short **){}, (int *){}, size_t) short_darray;
typedef struct_tmpl((int **){}, (int *){}, size_t) int_darray;
typedef struct_tmpl((size_t **){}, (int *){}, size_t) size_t_darray;
typedef struct_tmpl((double **){}, (int *){}, size_t) double_darray;

#define ALL_TYPES                                                                                                      \
        char_obj, string_obj, short_obj, int_obj, size_t_obj, double_obj, char_array, string_array, short_array,       \
                int_array, size_t_array, double_array, char_darray, string_darray, short_darray, int_darray,           \
                size_t_darray, double_darray,

#define __ext_type(ext, ...) __VA_OPT__(__expand__(__ext_type_h(ext, __VA_ARGS__)))
#define __ext_type_h(ext, type, ...) type##_##ext __VA_OPT__(, __ext_type_r PARENS(ext, __VA_ARGS__))
#define __ext_type_r() __ext_type_h

#define obj_types __ext_type(obj, SUPPORTED_TYPE)
#define array_types __ext_type(array, SUPPORTED_TYPE)
#define darray_types __ext_type(darray, SUPPORTED_TYPE)

#define array_index(s, e) (((e) - (s)) / sizeof(typeof(s)))

#define array_foreach(it, arr) for (typeof(arr.data) it = &((arr).data[0]); (it) < &((arr).data[(arr).len]); (it)++)

#define darray_foreach(it, arr, darr)                                                                                  \
        for (typeof(darr.data) arr = &((darr).data[0]); (arr) < &((darr).data[(darr).nr]); (arr)++)                    \
                for (typeof(*arr) it = &((arr)[0][0]);                                                                 \
                     (it) < &((arr)[0][(darr).len[array_index((darr).data[0], arr[0])]]); (it)++)

#define array_zip(it1, arr1, it2, arr2)                                                                                \
        for (typeof(arr1.data) it1 = &((arr1).data[0]), it2 = &((arr2).data[0]); (it1) < &((arr1).data[(arr1).len]);   \
             (it1)++, (it2)++)

#define darray_zip(it1, darr1, it2, darr2)                                                                             \
        for (typeof(darr1.data) arr1 = &((darr1).data[0]), arr2 = &((darr2).data[0]);                                  \
             (arr1) < &((darr1).data[(darr1).nr]); (arr1)++, (arr2)++)                                                 \
                for (typeof(*arr1) it1 = &((arr1)[0][0]), it2 = &((arr2)[0][0]);                                       \
                     (it1) < &((arr1)[0][(darr1).len[array_index((darr1).data[0], arr1[0])]]); (it1)++, (it2)++)

#define __cmp_integer_def(data_t)                                                                                      \
        static inline int __cmp_##data_t(data_t lhs, data_t rhs)                                                       \
        {                                                                                                              \
                return lhs.data < rhs.data ? -1 : lhs.data > rhs.data ? 1 : 0;                                         \
        }
__function_decl(__cmp_integer_def, __ext_type(obj, __INTEGER__));
#define __cmp_string_def(data_t)                                                                                       \
        static inline int __cmp_##data_t(data_t lhs, data_t rhs)                                                       \
        {                                                                                                              \
                return strcmp(lhs.data, rhs.data);                                                                     \
        }
__function_decl(__cmp_string_def, __ext_type(obj, __CHARACTER__));
#define __cmp_floating_def(data_t)                                                                                     \
        static inline int __cmp_##data_t(data_t lhs, data_t rhs)                                                       \
        {                                                                                                              \
                return signbit(lhs.data) < signbit(rhs.data)   ? -1                                                    \
                       : signbit(lhs.data) > signbit(rhs.data) ? 1                                                     \
                       : fabs(lhs.data) < fabs(rhs.data)       ? (signbit(lhs.data) ? 1 : -1)                          \
                       : fabs(lhs.data) > fabs(rhs.data)       ? (signbit(lhs.data) ? -1 : 1)                          \
                                                               : 0;                                                          \
        }
__function_decl(__cmp_floating_def, __ext_type(obj, __FLOATING__));

#define __cmp_array_def(data_t)                                                                                        \
        static inline int __cmp_##data_t##_array(data_t##_array a, data_t##_array b)                                   \
        {                                                                                                              \
                array_zip(lhs, a, rhs, b)                                                                              \
                {                                                                                                      \
                        int r = __cmp_##data_t##_obj((data_t##_obj){*(lhs)}, (data_t##_obj){*(rhs)});                  \
                        if (r != 0)                                                                                    \
                                return r;                                                                              \
                }                                                                                                      \
                return 0;                                                                                              \
        }
__function_decl(__cmp_array_def, SUPPORTED_TYPE);

#define __cmp_darray_def(data_t)                                                                                       \
        static inline int __cmp_##data_t##_darray(data_t##_darray a, data_t##_darray b)                                \
        {                                                                                                              \
                darray_zip(lhs, a, rhs, b)                                                                             \
                {                                                                                                      \
                        int r = __cmp_##data_t##_obj((data_t##_obj){*(lhs)}, (data_t##_obj){*(rhs)});                  \
                        if (r != 0)                                                                                    \
                                return r;                                                                              \
                }                                                                                                      \
                return 0;                                                                                              \
        }
__function_decl(__cmp_darray_def, SUPPORTED_TYPE);

#define cmp_helper(a, b) __cmp(a, obj_types, array_types, darray_types)(a, b)

#define __cmp(a, ...) _Generic((a), __VA_OPT__(__expand__(__cmp_h(__VA_ARGS__))))
#define __cmp_h(type, ...)                                                                                             \
        type:                                                                                                          \
        __cmp_##type __VA_OPT__(, __cmp_r PARENS(__VA_ARGS__))
#define __cmp_r() __cmp_h

#define assert_msg(cond, msg)                                                                                          \
        do {                                                                                                           \
                if (!(cond))                                                                                           \
                        printf("%s\n", msg);                                                                           \
        } while (0)

#define assert_equal(a, b)                                                                                             \
        do {                                                                                                           \
                assert_msg(cmp_helper(a, b) == 0, "not equal");                                                        \
        } while (0)

#define assert_count_equal

#define assert_in

#endif
