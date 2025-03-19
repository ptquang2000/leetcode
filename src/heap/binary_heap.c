#include "binary_heap.h"
#include "utils/asserts.h"

////////////////////////////////////////////////////////////////////////////////

#define parent_idx(i) (((i) - 1) / 2)
#define lc_idx(i) (2 * (i) + 1)
#define rc_idx(i) (2 * (i) + 2)

////////////////////////////////////////////////////////////////////////////////

static bool __lt__(size_t lhs, size_t rhs)
{
        return lhs < rhs;
}

////////////////////////////////////////////////////////////////////////////////

static bool __gt__(size_t lhs, size_t rhs)
{
        return lhs > rhs;
}

////////////////////////////////////////////////////////////////////////////////

static void heapify_up(struct heap *h, size_t i)
{
        size_t p = parent_idx(i);
        if (i <= 0)
                return;

        bool (*lt)(size_t, size_t) = h->__lt__ ? h->__lt__ : __lt__;
        bool (*gt)(size_t, size_t) = h->__gt__ ? h->__gt__ : __gt__;
        bool (*op)(size_t, size_t) = h->maxheap ? lt : gt;

        size_t m = op(h->data[p], h->data[i]) ? p : i;
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

        bool (*lt)(size_t, size_t) = h->__lt__ ? h->__lt__ : __lt__;
        bool (*gt)(size_t, size_t) = h->__gt__ ? h->__gt__ : __gt__;
        bool (*op)(size_t, size_t) = h->maxheap ? lt : gt;

        size_t m = op(h->data[l], h->data[r]) ? (op(h->data[i], h->data[r]) ? r : i)
                                              : (op(h->data[i], h->data[l]) ? l : i);
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
        UTILS_ASSERT_MSG((!h->__gt__ && !h->__lt__) || (h->maxheap && h->__lt__) || (!h->maxheap && h->__gt__),
                         "Are you sure to override the correct function?");

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
                h->data = 0;
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
