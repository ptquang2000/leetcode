#ifndef UTILS_COMPARE_H
#define UTILS_COMPARE_H

int utils_scalar_cmp(size_t lhs, size_t rhs);
int utils_float_cmp(size_t lhs, size_t rhs);
int utils_str_cmp(size_t lhs, size_t rhs);
int utils_btree_cmp(size_t lhs, size_t rhs);
int btreecmp(struct btree_node *r1, struct btree_node *r2);

#endif
