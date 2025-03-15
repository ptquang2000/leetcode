#ifndef UTILS_TYPE_H
#define UTILS_TYPE_H

typedef char *string;
#define SUPPORTED_TYPE char, string, short, int, size_t, double

#define struct_tmpl(...)                                                                                               \
        struct {                                                                                                       \
                __VA_OPT__(__expand__(__struct_obj(__VA_ARGS__)))                                                      \
                void (*print)(void *);                                                                                 \
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

#define cmp_scalar(a, b) ((a) < (b) ? -1 : (a) > (b) ? 1 : 0)
#define cmp_float(a, b) ((a) < (b) ? -1 : (a) > (b) ? 1 : 0)
#define cmp_double(a, b) ((a) < (b) ? -1 : (a) > (b) ? 1 : 0)

#define cmp(a, b) _Generic((a), float: cmp_float(a, b), double: cmp_double(a, b), default: cmp_scalar(a, b))

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

#define assert_msg(cond, msg)                                                                                          \
        do {                                                                                                           \
                if (!(cond))                                                                                           \
                        printf("%s\n", msg);                                                                           \
        } while (0)

#define assert_equal(a, b)                                                                                             \
        do {                                                                                                           \
                assert_msg(cmp(a, b) == 0, "not equal");                                                               \
        } while (0)

#define assert_equal_array(a, b)                                                                                       \
        do {                                                                                                           \
                array_zip(lhs, a, rhs, b)                                                                              \
                {                                                                                                      \
                        assert_equal(*(lhs), *(rhs));                                                                  \
                }                                                                                                      \
        } while (0)

#define assert_equal_darray(a, b)                                                                                      \
        do {                                                                                                           \
                darray_zip(lhs, a, rhs, b)                                                                             \
                {                                                                                                      \
                        assert_equal(*(lhs), *(rhs));                                                                  \
                }                                                                                                      \
        } while (0)

#define assert_count_equal

#define assert_in

#endif
