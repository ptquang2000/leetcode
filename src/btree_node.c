#include "btree_node.h"
#include "queue.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MASK(stride) ((size_t)-1 >> ((sizeof(size_t) - stride) * 8))
#define array_at(arr, idx, stride) (*(size_t *)(arr + idx * stride) & MASK(stride))

static struct btree_node *new_node(struct btree_node i_node);
#define node(...) new_node((struct btree_node){__VA_ARGS__});

static struct btree_node *new_node(struct btree_node i_node)
{
        struct btree_node *node = calloc(1, sizeof(*node));
        node->left = i_node.left ? i_node.left : 0;
        node->right = i_node.right ? i_node.right : 0;
        node->value = i_node.value;
        return node;
}

struct btree_node *__btree_ctor_bfs(size_t i_sz, void *i_data, size_t i_stride)
{
        if (!i_sz)
                return NULL;

        size_t i = 0;
        size_t value = array_at(i_data, i++, i_stride);
        struct btree_node *root = node(value);

        struct btree_node *node = root;
        for (; i < i_sz; i += 2) {
                assert(i_sz - i < 3 && "Missing child node");

                value = array_at(i_data, i, i_stride);
                node->left = node(value);
                value = array_at(i_data, i + 1, i_stride);
                node->right = node(value);
        }

        return root;
}

struct btree_node *btree_ctor_bfs(size_t size, void *data, size_t stride, size_t height, size_t idx)
{
        if (!size)
                return NULL;

        assert(idx < size && "Missing node at height");
        const size_t val = array_at(data, idx, stride);
        if (val == BTREE_NULL)
                return NULL;

        struct btree_node *node = node(val);
        const size_t breadth = size < 1 << height ? size : 1 << height;

        const size_t left_idx = idx * 2;
        node->left = btree_ctor_bfs(size - breadth, data + breadth * stride, stride, height + 1, left_idx);
        const size_t right_idx = node->left ? idx * 2 + 1 : (idx - 1) * 2;
        node->right = btree_ctor_bfs(size - breadth, data + breadth * stride, stride, height + 1, right_idx);
        return node;
}

typedef struct queue bt_queue;
#define bt_queue_ctor() queue_ctor();
#define bt_queue_push(q, next) queue_push(&q, next)
#define bt_queue_pop(q) (struct btree_node *)queue_pop(&q)
#define bt_queue_dtor(q) queue_dtor(&q)

static size_t get_leaves_breadth(struct btree_node *root)
{
        if (!root)
                return 0;

        bt_queue q = bt_queue_ctor();
        bt_queue_push(q, root);

        size_t breadth = 0;
        while (q.size) {
                struct btree_node *n = bt_queue_pop(q);
                if (n->left)
                        bt_queue_push(q, n->left);
                if (n->right)
                        bt_queue_push(q, n->right);

                breadth += !n->left && !n->right ? 1 : 0;
        }

        bt_queue_dtor(q);
        return breadth;
}

size_t get_tree_height(struct btree_node *root, size_t height)
{
        if (!root)
                return height;

        size_t lh = get_tree_height(root->left, height + 1);
        size_t rh = get_tree_height(root->right, height + 1);
        return lh < rh ? rh : lh;
}

static bt_queue print_btree(bt_queue nodes)
{
        const char *SPACES = "                                                 ";
        bool is_empty = true;

        bt_queue childs = bt_queue_ctor();
        printf("\n");
        while (nodes.size) {
                struct btree_node *root = bt_queue_pop(nodes);
                if (root) {
                        is_empty = false;
                        if (root->left)
                                bt_queue_push(childs, root->left);
                        if (root->right)
                                bt_queue_push(childs, root->right);
                        if (!root->left && !root->right)
                                bt_queue_push(childs, 0);
                }

                size_t lh = root ? get_tree_height(root->left, 0) : 1;
                size_t rb = get_leaves_breadth(root);

                int ls = (1 << lh) / 2;
                int rs = (1 << rb) / 2;
                if (root) {
                        printf("%.*s", ls, SPACES);
                        printf("%ld", root->value);
                        printf("%.*s", rs, SPACES);
                } else {
                        printf("%.*s", ls, SPACES);
                        printf("%.*s", 0, SPACES);
                        printf("%.*s", rs, SPACES);
                }
        }
        if (is_empty)
                bt_queue_dtor(childs);

        return childs;
}

void utils_format_btree(size_t i_root)
{
        struct btree_node *root = (struct btree_node *)i_root;
        char buf[64];

        bt_queue nodes = bt_queue_ctor();
        bt_queue_push(nodes, root);

        while (nodes.size) {
                nodes = print_btree(nodes);
        }
        bt_queue_dtor(nodes);
}
