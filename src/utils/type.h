#ifndef UTILS_TYPE_H
#define UTILS_TYPE_H

#include "helper.h"

typedef char *string;
#define __FLOATING__ double
#define __INTEGER__ char, bool, short, int, size_t
#define __LITERAL__ string
#define __TYPES__ __FLOATING__, __INTEGER__, __LITERAL__

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
typedef struct_tmpl(bool) _Bool_obj;
typedef struct_tmpl(short) short_obj;
typedef struct_tmpl(int) int_obj;
typedef struct_tmpl(size_t) size_t_obj;
typedef struct_tmpl(double) double_obj;

typedef struct_tmpl((char *){}, size_t) char_array;
typedef struct_tmpl((string *){}, size_t) string_array;
typedef struct_tmpl((bool *){}, size_t) _Bool_array;
typedef struct_tmpl((short *){}, size_t) short_array;
typedef struct_tmpl((int *){}, size_t) int_array;
typedef struct_tmpl((size_t *){}, size_t) size_t_array;
typedef struct_tmpl((double *){}, size_t) double_array;

typedef struct_tmpl((char **){}, (int *){}, size_t) char_darray;
typedef struct_tmpl((string **){}, (int *){}, size_t) string_darray;
typedef struct_tmpl((bool **){}, (int *){}, size_t) _Bool_darray;
typedef struct_tmpl((short **){}, (int *){}, size_t) short_darray;
typedef struct_tmpl((int **){}, (int *){}, size_t) int_darray;
typedef struct_tmpl((size_t **){}, (int *){}, size_t) size_t_darray;
typedef struct_tmpl((double **){}, (int *){}, size_t) double_darray;

typedef struct_tmpl((void **){}, size_t) _Container;

typedef _Bool_obj bool_obj;
typedef _Bool_array bool_array;
typedef _Bool_darray bool_darray;

#endif
