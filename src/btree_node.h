#ifndef BTREE_NODE_H
#define BTREE_NODE_H

#include <stddef.h>
#include <stdint.h>

#define BTREE_NULL (0xC0FFE)

struct btree_node {
        size_t value;
        struct btree_node *left;
        struct btree_node *right;
};

struct btree_node *btree_ctor_bfs(size_t size, void *data, size_t stride, size_t height, size_t idx);
#define btree(data, size) btree_ctor_bfs(size, data, sizeof(*data), 0, 0);

void btree_dtor(struct btree_node *root);
#define free_btree(r) btree_dtor(r)

#endif
