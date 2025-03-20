#ifndef UTILS_TYPE_H
#define UTILS_TYPE_H

#include "binary_tree/btree_node.h"
#include "heap/binary_heap.h"
#include "helper.h"
#include "linked_list/list_node.h"

typedef char *string;
typedef struct btree_node *bt_node;
typedef struct list_node *ll_node;
typedef struct heap *heap;
#define __FLOATING__ double
#define __INTEGER__ char, bool, short, int, size_t
#define __LITERAL__ string
#define __STRUCT__ bt_node, ll_node, heap
#define __TYPES__ __FLOATING__, __INTEGER__, __LITERAL__, __STRUCT__

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
typedef struct_tmpl(bt_node) bt_node_obj;
typedef struct_tmpl(ll_node) ll_node_obj;
typedef struct_tmpl(heap) heap_obj;

typedef struct_tmpl((char *){}, int) char_array;
typedef struct_tmpl((string *){}, int) string_array;
typedef struct_tmpl((bool *){}, int) _Bool_array;
typedef struct_tmpl((short *){}, int) short_array;
typedef struct_tmpl((int *){}, int) int_array;
typedef struct_tmpl((size_t *){}, int) size_t_array;
typedef struct_tmpl((double *){}, int) double_array;
typedef struct_tmpl((bt_node *){}, int) bt_node_array;
typedef struct_tmpl((ll_node *){}, int) ll_node_array;
typedef struct_tmpl((heap *){}, int) heap_array;

typedef struct_tmpl((char **){}, (int *){}, int) char_darray;
typedef struct_tmpl((string **){}, (int *){}, int) string_darray;
typedef struct_tmpl((bool **){}, (int *){}, int) _Bool_darray;
typedef struct_tmpl((short **){}, (int *){}, int) short_darray;
typedef struct_tmpl((int **){}, (int *){}, int) int_darray;
typedef struct_tmpl((size_t **){}, (int *){}, int) size_t_darray;
typedef struct_tmpl((double **){}, (int *){}, int) double_darray;
typedef struct_tmpl((bt_node **){}, (int *){}, int) bt_node_darray;
typedef struct_tmpl((ll_node **){}, (int *){}, int) ll_node_darray;
typedef struct_tmpl((heap **){}, (int *){}, int) heap_darray;

typedef struct_tmpl((void **){}, int) _Container;

typedef _Bool_obj bool_obj;
typedef _Bool_array bool_array;
typedef _Bool_darray bool_darray;

#endif
