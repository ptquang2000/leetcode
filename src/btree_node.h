#ifndef BTREE_NODE_H
#define BTREE_NODE_H

#include <stddef.h>

struct btree_node {
        size_t value;
        struct btree_node *left;
        struct btree_node *right;
};

#define BTREE_NULL ((size_t)-1)

#endif
