#ifndef UTILS_TYPE_H
#define UTILS_TYPE_H

typedef const char *string;
#define SUPPORTED_TYPE char, string, short, int, size_t, float

#define struct_template(...)                                                                                           \
        struct {                                                                                                       \
                __VA_OPT__(__expand__(struct_obj(__VA_ARGS__)))                                                        \
                void (*print)(parse_args(__VA_ARGS__));                                                                \
        }

#define struct_obj_skip(...) __expand__(struct_array(__VA_ARGS__))
#define struct_obj_(_v) typeof(_v) data;
#define struct_obj(_v, ...) struct_obj_##__VA_OPT__(skip)(_v __VA_OPT__(, __VA_ARGS__))

#define struct_array_skip(...) __expand__(struct_darray(__VA_ARGS__))
#define struct_array_(_v, _len)                                                                                        \
        typeof(*_v) *data;                                                                                             \
        typeof(_len) len;
#define struct_array(_v, _len, ...) struct_array_##__VA_OPT__(skip)(_v, _len __VA_OPT__(, __VA_ARGS__))

#define struct_darray(_v, _len, _nr)                                                                                   \
        typeof(**_v) **data;                                                                                           \
        typeof(*_len) *len;                                                                                            \
        typeof(_nr) nr;

#define uobject(data_t)                                                                                                \
        struct {                                                                                                       \
                data_t data;                                                                                           \
                const char *fmt;                                                                                       \
        }

#define uarray(data_t)                                                                                                 \
        struct {                                                                                                       \
                size_t len;                                                                                            \
                data_t data;                                                                                           \
        }

#define udarray(data_t, len_t)                                                                                         \
        struct {                                                                                                       \
                size_t nr;                                                                                             \
                len_t len;                                                                                             \
                data_t data;                                                                                           \
        }

#define cmp_scalar(a, b) ((a) < (b) ? -1 : (a) > (b) ? 1 : 0)
#define cmp_float(a, b) ((a) < (b) ? -1 : (a) > (b) ? 1 : 0)
#define cmp_double(a, b) ((a) < (b) ? -1 : (a) > (b) ? 1 : 0)

#define cmp(a, b) _Generic((a), float: cmp_float(a, b), double: cmp_double(a, b), default: cmp_scalar(a, b))

#define array_index(s, e) (((e) - (s)) / sizeof(typeof(s)))

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

#define assert_equal(_a, _b)                                                                                           \
        do {                                                                                                           \
                typedef uobject((_a)) object;                                                                          \
                object __a = {.data = (_a)};                                                                           \
                object __b = {.data = (_b)};                                                                           \
                assert_msg(cmp(__a.data, __b.data) == 0, "not equal");                                                 \
        } while (0)

#define assert_equal_array(_a, _b, _len)                                                                               \
        do {                                                                                                           \
                typedef uarray(typeof(_a)) array;                                                                      \
                array __a = {.data = (_a), .len = (_len)};                                                             \
                array __b = {.data = (_b), .len = (_len)};                                                             \
                array_zip(_lhs, __a, _rhs, __b)                                                                        \
                {                                                                                                      \
                        assert_equal(*(_lhs), *(_rhs));                                                                \
                }                                                                                                      \
        } while (0)

#define assert_equal_darray(_a, _b, _len, _nr)                                                                         \
        do {                                                                                                           \
                typedef udarray(typeof(_a), typeof(_len)) darray;                                                      \
                darray __a = {.nr = (_nr), .len = (_len), .data = (_a)};                                               \
                darray __b = {.nr = (_nr), .len = (_len), .data = (_b)};                                               \
                darray_zip(_lhs, __a, _rhs, __b)                                                                       \
                {                                                                                                      \
                        assert_equal(*(_lhs), *(_rhs));                                                                \
                }                                                                                                      \
        } while (0)

#endif
