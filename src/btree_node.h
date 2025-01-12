#ifndef BTREE_NODE_H
#define BTREE_NODE_H

#include <stddef.h>

#define BTREE_NULL ((size_t)-1)

struct btree_node {
        size_t value;
        struct btree_node *left;
        struct btree_node *right;
};

struct btree_node *btree_ctor_bfs(size_t size, void *data, size_t stride, size_t height, size_t idx);
#define btree(data, size) btree_ctor_bfs(size, data, sizeof(*data), 0, 0);

#endif
