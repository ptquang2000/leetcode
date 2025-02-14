#include "binary_heap.h"
#include "utils/utils.h"

////////////////////////////////////////////////////////////////////////////////

#define parent_idx(i) (((i) - 1) / 2)
#define lc_idx(i) (2 * (i) + 1)
#define rc_idx(i) (2 * (i) + 2)

////////////////////////////////////////////////////////////////////////////////

static void heapify_up(struct heap *h, size_t i)
{
        if (i <= 0)
                return;

        size_t p = parent_idx(i);
        size_t m = h->maxheap ? (h->data[p] < h->data[i] ? p : i) : (h->data[p] > h->data[i] ? p : i);
        if (m != i) {
                h->data[p] ^= h->data[i];
                h->data[i] ^= h->data[p];
                h->data[p] ^= h->data[i];
                heapify_up(h, p);
        }
}

////////////////////////////////////////////////////////////////////////////////

static void heapify_down(struct heap *h, size_t i)
{
        size_t l = lc_idx(i);
        size_t r = rc_idx(i);
        if (i >= h->size || l >= h->size)
                return;

        size_t m = h->maxheap ? (h->data[l] < h->data[r] ? (h->data[i] < h->data[r] ? r : i)
                                                         : (h->data[i] < h->data[l] ? l : i))
                              : (h->data[l] > h->data[r] ? (h->data[i] > h->data[r] ? r : i)
                                                         : (h->data[i] > h->data[l] ? l : i));
        if (m != i) {
                h->data[m] ^= h->data[i];
                h->data[i] ^= h->data[m];
                h->data[m] ^= h->data[i];
                heapify_down(h, m);
        }
}

////////////////////////////////////////////////////////////////////////////////

void heap_push(struct heap *h, size_t v)
{
        h->data = realloc(h->data, ++h->size * sizeof(*h->data));
        h->data[h->size - 1] = v;
        heapify_up(h, h->size - 1);
}

////////////////////////////////////////////////////////////////////////////////

size_t heap_pop(struct heap *h)
{
        UTILS_ASSERT_MSG(h->size > 0, "Heap size is 0");
        size_t v = h->data[0];
        if (--h->size == 0) {
                free(h->data);
                return v;
        }

        h->data[0] = h->data[h->size];
        heapify_down(h, 0);
        return v;
}

////////////////////////////////////////////////////////////////////////////////

size_t heap_top(struct heap *h)
{
        UTILS_ASSERT_MSG(h->size > 0, "Heap size is 0");
        return h->data[0];
}

////////////////////////////////////////////////////////////////////////////////
