#include "btree_node.h"
#include "queue.h"

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

static struct btree_node *new_node(struct btree_node i_node)
{
        struct btree_node *node = calloc(1, sizeof(*node));
        node->left = i_node.left ? i_node.left : 0;
        node->right = i_node.right ? i_node.right : 0;
        node->value = i_node.value;
        return node;
}

struct btree_node *btree_ctor_bfs(size_t size, void *data, size_t stride, size_t height, size_t idx)
{
        if (!size)
                return NULL;

        assert(idx < size);
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

void utils_format_btree(size_t i_root)
{
        struct btree_node *root = (struct btree_node *)i_root;
        printf("\n");
        print_btree(root, 0);
}
