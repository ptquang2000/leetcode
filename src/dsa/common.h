#ifndef COMMON_H
#define COMMON_H

#include "map/htable.h"

struct dsa_point {
        int x;
        int y;
};

struct dsa_list_node {
        int value;
        struct dsa_list_node *prev;
        struct dsa_list_node *next;
};

struct dsa_doubly_linked_list {
        int length;
        struct dsa_list_node *head;
        struct dsa_list_node *tail;

        void (*prepend)(struct dsa_doubly_linked_list *l, int v);
        void (*insert_at)(struct dsa_doubly_linked_list *l, int v, int idx);
        void (*append)(struct dsa_doubly_linked_list *l, int v);
        int (*remove)(struct dsa_doubly_linked_list *l, int v);
        int (*get)(struct dsa_doubly_linked_list *l, int idx);
        int (*remove_at)(struct dsa_doubly_linked_list *l, int idx);
};

struct dsa_queue {
        int length;
        struct dsa_list_node *head;
        struct dsa_list_node *tail;

        void (*enqueue)(struct dsa_queue *q, int v);
        int (*deque)(struct dsa_queue *q);
        int (*peek)(struct dsa_queue *q);
};

struct dsa_stack {
        int length;
        struct dsa_list_node *head;

        void (*push)(struct dsa_stack *s, int v);
        int (*pop)(struct dsa_stack *s);
        int (*peek)(struct dsa_stack *s);
};

struct dsa_bt {
        int value;
        struct dsa_bt *left;
        struct dsa_bt *right;
};

static struct dsa_bt *tree = &(struct dsa_bt){
        .value = 20,
        .right =
                &(struct dsa_bt){
                        .value = 50,
                        .right =
                                &(struct dsa_bt){
                                        .value = 100,
                                        .right = 0,
                                        .left = 0,
                                },
                        .left =
                                &(struct dsa_bt){
                                        .value = 30,
                                        .right =
                                                &(struct dsa_bt){
                                                        .value = 45,
                                                        .right = 0,
                                                        .left = 0,
                                                },
                                        .left =
                                                &(struct dsa_bt){
                                                        .value = 29,
                                                        .right = 0,
                                                        .left = 0,
                                                },
                                },
                },
        .left =
                &(struct dsa_bt){
                        .value = 10,
                        .right =
                                &(struct dsa_bt){
                                        .value = 15,
                                        .right = 0,
                                        .left = 0,
                                },
                        .left =
                                &(struct dsa_bt){
                                        .value = 5,
                                        .right =
                                                &(struct dsa_bt){
                                                        .value = 7,
                                                        .right = 0,
                                                        .left = 0,
                                                },
                                        .left = 0,
                                },
                },
};

static struct dsa_bt *tree2 = &(struct dsa_bt){
        .value = 20,
        .right =
                &(struct dsa_bt){
                        .value = 50,
                        .right = 0,
                        .left =
                                &(struct dsa_bt){
                                        .value = 30,
                                        .right =
                                                &(struct dsa_bt){
                                                        .value = 45,
                                                        .right =
                                                                &(struct dsa_bt){
                                                                        .value = 49,
                                                                        .right = 0,
                                                                        .left = 0,
                                                                },
                                                        .left = 0,
                                                },
                                        .left =
                                                &(struct dsa_bt){
                                                        .value = 29,
                                                        .right = 0,
                                                        .left =
                                                                &(struct dsa_bt){
                                                                        .value = 21,
                                                                        .right = 0,
                                                                        .left = 0,
                                                                },
                                                },
                                },
                },
        .left =
                &(struct dsa_bt){
                        .value = 10,
                        .right =
                                &(struct dsa_bt){
                                        .value = 15,
                                        .right = 0,
                                        .left = 0,
                                },
                        .left =
                                &(struct dsa_bt){
                                        .value = 5,
                                        .right =
                                                &(struct dsa_bt){
                                                        .value = 7,
                                                        .right = 0,
                                                        .left = 0,
                                                },
                                        .left = 0,
                                },
                },
};

struct min_heap {
        int length;
        int *data;
        void (*insert)(struct min_heap *h, int v);
        int (*delete)(struct min_heap *h);
};

struct weighted_adj {
        int to;
        int weight;
};
typedef struct weighted_adj *weighted_adj_list;

//      (1) --- (4) ---- (5)
//    /  |       |       /|
// (0)   | ------|------- |
//    \  |/      |        |
//      (2) --- (3) ---- (6)
static weighted_adj_list list1[] = {
        (struct weighted_adj[]){
                {.to = 1, .weight = 3},
                {.to = 2, .weight = 1},
        },
        (struct weighted_adj[]){
                {.to = 0, .weight = 3},
                {.to = 2, .weight = 4},
                {.to = 4, .weight = 1},
        },
        (struct weighted_adj[]){
                {.to = 1, .weight = 4},
                {.to = 3, .weight = 7},
                {.to = 0, .weight = 1},
        },
        (struct weighted_adj[]){
                {.to = 2, .weight = 7},
                {.to = 4, .weight = 5},
                {.to = 6, .weight = 1},
        },
        (struct weighted_adj[]){
                {.to = 1, .weight = 1},
                {.to = 3, .weight = 5},
                {.to = 5, .weight = 2},
        },
        (struct weighted_adj[]){
                {.to = 6, .weight = 1},
                {.to = 4, .weight = 2},
                {.to = 2, .weight = 18},
        },
        (struct weighted_adj[]){
                {.to = 3, .weight = 1},
                {.to = 5, .weight = 1},
        },
};
static int list1_len[] = {2, 3, 3, 3, 3, 3, 2};

static weighted_adj_list list2[] = {
        (struct weighted_adj[]){
                {.to = 1, .weight = 3},
                {.to = 2, .weight = 1},
        },
        (struct weighted_adj[]){
                {.to = 4, .weight = 1},
        },
        (struct weighted_adj[]){
                {.to = 3, .weight = 7},
        },
        (struct weighted_adj[]){},
        (struct weighted_adj[]){
                {.to = 1, .weight = 1},
                {.to = 3, .weight = 5},
                {.to = 5, .weight = 2},
        },
        (struct weighted_adj[]){
                {.to = 2, .weight = 18},
                {.to = 6, .weight = 1},
        },
        (struct weighted_adj[]){
                {.to = 3, .weight = 1},
        },
};
static int list2_len[] = {2, 1, 1, 0, 3, 2, 1};

typedef int *weighted_adj_matrix;

//     >(1)<--->(4) ---->(5)
//    /          |       /|
// (0)     ------|------- |
//    \   v      v        v
//     >(2) --> (3) <----(6)
static weighted_adj_matrix matrix2[] = {
        (int[]){0, 3, 1, 0, 0, 0, 0},  // 0
        (int[]){0, 0, 0, 0, 1, 0, 0},  // 1
        (int[]){0, 0, 7, 0, 0, 0, 0},  // 2
        (int[]){0, 0, 0, 0, 0, 0, 0},  // 3
        (int[]){0, 1, 0, 5, 0, 2, 0},  // 4
        (int[]){0, 0, 18, 0, 0, 0, 1}, // 5
        (int[]){0, 0, 0, 1, 0, 0, 1},  // 6
};

struct htable;
struct LRU {
        int capacity;
        struct dsa_list_node *head;
        struct dsa_list_node *tail;
        struct htable map;

        int length;
        void (*update)(struct LRU *lru, const char *k, int v);
        int (*get)(struct LRU *lru, const char *k);
};

#endif
