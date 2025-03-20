#include "btree_node.h"
#include "queue/queue.h"
#include "utils/asserts.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queue bt_queue;
#define btq_ctor() queue_ctor()
#define btq_dtor(q) queue_dtor(&q)
#define btq_push(q, n) queue_push(&q, (void *)n)
#define btq_pop(q) (struct btree_node *)queue_pop(&q)

#define MASK(stride) ((size_t)-1 >> ((sizeof(size_t) - stride) * 8))
#define array_at(arr, idx, stride) (*(size_t *)(arr + idx * stride) & MASK(stride))

static struct btree_node *new_node(struct btree_node i_node);
#define node(...) new_node((struct btree_node){__VA_ARGS__});

////////////////////////////////////////////////////////////////////////////////

static struct btree_node *new_node(struct btree_node i_node)
{
        struct btree_node *node = calloc(1, sizeof(*node));
        node->left = i_node.left ? i_node.left : 0;
        node->right = i_node.right ? i_node.right : 0;
        node->value = i_node.value;
        return node;
}

////////////////////////////////////////////////////////////////////////////////

struct btree_node *btree_ctor_bfs(size_t size, void *data, size_t stride, size_t height, size_t idx)
{
        if (!size)
                return NULL;

        UTILS_ASSERT_MSG(idx < size, "Error: Missing node {} at height={}, size={}", (int_obj){idx},
                         (size_t_obj){height}, (size_t_obj){size});
        const size_t val = array_at(data, idx, stride);
        if (val == NONE)
                return NULL;

        struct btree_node *node = node(val);
        const size_t breadth = min(size, 1 << height);
        const size_t remain = size - breadth;

        size_t skip = 0;
        for (size_t i = 0; i < idx; i++) {
                if (array_at(data, i, stride) == NONE)
                        skip++;
        }
        idx -= skip;
        height -= skip;

        const size_t left_idx = idx * 2;
        if (left_idx < remain)
                node->left = btree_ctor_bfs(remain, data + breadth * stride, stride, height + 1, left_idx);
        const size_t right_idx = idx * 2 + 1;
        if (right_idx < remain)
                node->right = btree_ctor_bfs(remain, data + breadth * stride, stride, height + 1, right_idx);
        return node;
}

////////////////////////////////////////////////////////////////////////////////

void btree_dtor(struct btree_node *root)
{
        if (!root)
                return;

        btree_dtor(root->left);
        btree_dtor(root->right);

        free(root->right);
        free(root->left);
}

////////////////////////////////////////////////////////////////////////////////

void print_btree(struct btree_node *node, size_t height)
{
        const char *tabs = "\t\t\t\t\t\t\t\t\t\t\t";
        if (!node)
                return;

        printf("%ld", node->value);
        if (node->right)
                printf("\t→");
        print_btree(node->right, height + 1);
        if (node->left)
                printf("\n%.*s↓", (int)height, tabs);
        print_btree(node->left, 0);
}

////////////////////////////////////////////////////////////////////////////////

void __print_bt_node_obj(bt_node_obj a)
{
        struct btree_node *root = a.data;
        printf("\n");
        print_btree(root, 0);
}

////////////////////////////////////////////////////////////////////////////////

int __cmp_bt_node_obj(bt_node_obj a, bt_node_obj b)
{
        struct btree_node *r1 = a.data;
        struct btree_node *r2 = b.data;
        struct btree_node *root;
        struct array {
                struct btree_node **data;
                int sz;
        };
        struct array stack = {};
        struct array pre1 = {};
        struct array pre2 = {};
        struct array in1 = {};
        struct array in2 = {};

        root = r1;
        while (root || stack.sz) {
                if (root) {
                        pre1.data = realloc(pre1.data, ++pre1.sz * sizeof(*pre1.data));
                        pre1.data[pre1.sz - 1] = root;

                        stack.data = realloc(stack.data, ++stack.sz * sizeof(*stack.data));
                        stack.data[stack.sz - 1] = root->right;

                        root = root->left;
                } else {
                        root = stack.sz ? stack.data[--stack.sz] : 0;
                }
        }
        assert(stack.sz == 0);

        root = r2;
        while (root || stack.sz) {
                if (root) {
                        pre2.data = realloc(pre2.data, ++pre2.sz * sizeof(*pre2.data));
                        pre2.data[pre2.sz - 1] = root;

                        stack.data = realloc(stack.data, ++stack.sz * sizeof(*stack.data));
                        stack.data[stack.sz - 1] = root->right;

                        root = root->left;
                } else {
                        root = stack.sz ? stack.data[--stack.sz] : 0;
                }
        }
        assert(stack.sz == 0);

        root = r1;
        while (root || stack.sz) {
                if (root) {
                        stack.data = realloc(stack.data, ++stack.sz * sizeof(*stack.data));
                        stack.data[stack.sz - 1] = root;

                        root = root->left;
                } else {
                        root = stack.sz ? stack.data[--stack.sz] : 0;

                        in1.data = realloc(in1.data, ++in1.sz * sizeof(*in1.data));
                        in1.data[in1.sz - 1] = root;

                        root = root->right;
                }
        }
        assert(stack.sz == 0);

        root = r2;
        while (root || stack.sz) {
                if (root) {
                        stack.data = realloc(stack.data, ++stack.sz * sizeof(*stack.data));
                        stack.data[stack.sz - 1] = root;

                        root = root->left;
                } else {
                        root = stack.sz ? stack.data[--stack.sz] : 0;

                        in2.data = realloc(in2.data, ++in2.sz * sizeof(*in2.data));
                        in2.data[in2.sz - 1] = root;

                        root = root->right;
                }
        }

        assert(pre1.sz == in1.sz);
        assert(pre2.sz == in2.sz);

        int res = pre1.sz < pre2.sz ? -1 : pre1.sz > pre2.sz ? 1 : 0;

        if (res == 0) {
                for (size_t i = 0, res = 0; i < pre1.sz; i++) {
                        res = pre1.data[i]->value < pre2.data[i]->value   ? -1
                              : pre1.data[i]->value > pre2.data[i]->value ? 1
                                                                          : 0;
                        if (res != 0)
                                break;

                        res = in1.data[i]->value < in2.data[i]->value   ? -1
                              : in1.data[i]->value > in2.data[i]->value ? 1
                                                                        : 0;
                        if (res != 0)
                                break;
                }
        }

        free(stack.data);
        free(pre1.data);
        free(pre2.data);
        free(in1.data);
        free(in2.data);
        return res;
}

////////////////////////////////////////////////////////////////////////////////
