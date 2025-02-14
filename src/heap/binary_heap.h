#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <stddef.h>

struct heap {
        size_t size;
        size_t *data;

        size_t maxheap;
};

void heap_push(struct heap *, size_t);
size_t heap_pop(struct heap *);
size_t heap_top(struct heap *);

#endif
