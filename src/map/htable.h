#ifndef HTABLE_H
#define HTABLE_H

struct htable_node {
        const char *key;
        size_t value;
};
struct htable {
        size_t size;
        struct htable_node **data;
        size_t *len;
        size_t nr;
};

struct htable_node *htable_set(struct htable *ht, const char *k, int v);
void htable_delete(struct htable *ht, const char *k);
struct htable_node *htable_get(struct htable *ht, const char *k);
size_t htable_size(struct htable *ht);

#endif
