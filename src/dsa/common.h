#ifndef COMMON_H
#define COMMON_H

struct dsa_point {
        int x;
        int y;
};

struct dsa_doubly_linked_list {
        int length;
        void (*prepend)(struct dsa_doubly_linked_list *l, int v);
        int (*insert_at)(struct dsa_doubly_linked_list *l, int v, int idx);
        int (*append)(struct dsa_doubly_linked_list *l, int v);
        int (*remove)(struct dsa_doubly_linked_list *l, int v);
        int (*get)(struct dsa_doubly_linked_list *l, int idx);
        int (*remove_at)(struct dsa_doubly_linked_list *l, int idx);
};

struct dsa_queue {
        int length;
        void (*enqueue)(struct dsa_queue *q, int v);
        int (*deque)(struct dsa_queue *q);
        int (*peek)(struct dsa_queue *q);
};

struct dsa_stack {
        int length;
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

#endif
