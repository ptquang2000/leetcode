#include "btree_node.h"
#include "queue.h"
#include "utils.h"

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

        UTILS_ASSERT_MSG(idx < size, "Error: Missing node {} at height={}, size={}", UTYPE(idx), UTYPE(height),
                         UTYPE(size));
        const size_t val = array_at(data, idx, stride);
        if (val == BTREE_NULL)
                return NULL;

        struct btree_node *node = node(val);
        const size_t breadth = min(size, 1 << height);
        const size_t remain = size - breadth;

        size_t skip = 0;
        for (size_t i = 0; i < idx; i++) {
                if (array_at(data, i, stride) == BTREE_NULL)
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

void utils_format_btree(size_t i_root)
{
        struct btree_node *root = (struct btree_node *)i_root;
        printf("\n");
        print_btree(root, 0);
}

////////////////////////////////////////////////////////////////////////////////

int btreecmp(struct btree_node *r1, struct btree_node *r2)
{
        if (!r1 && !r2)
                return 0;
        if (!r1)
                return -1;
        if (!r2)
                return 1;

        int left = btreecmp(r1->left, r2->left);
        int right = btreecmp(r1->right, r2->right);
        int cmp = r1->value < r2->value ? -1 : r1->value > r2->value ? 1 : 0;
        return left < right ? -1 : left > right ? 1 : cmp;
}

////////////////////////////////////////////////////////////////////////////////
