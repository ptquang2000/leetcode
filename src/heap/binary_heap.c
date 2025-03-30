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

static void heapify_up(struct heap *h, size_t i)
{
        size_t p = parent_idx(i);
        if (i <= 0)
                return;

        bool (*lt)(size_t, size_t) = h->__lt__ ? h->__lt__ : __lt__;
        size_t m = lt(h->data[p], h->data[i]) ^ !h->maxheap ? p : i;
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
        size_t m = lt(h->data[l], h->data[r]) ^ !h->maxheap ? (lt(h->data[i], h->data[r]) ^ !h->maxheap ? r : i)
                                                            : (lt(h->data[i], h->data[l]) ^ !h->maxheap ? l : i);
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
        ASSERT_MSG(h->size > 0, "Heap size is 0");
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
        ASSERT_MSG(h->size > 0, "Heap size is 0");
        return h->data[0];
}

////////////////////////////////////////////////////////////////////////////////

static void __print_heap(struct heap *h, int i, int height)
{
        const char *tabs = "\t\t\t\t\t\t\t\t\t\t\t";
        if (i < 0 || h->size <= i)
                return;

        printf("%ld", h->data[i]);
        if (rc_idx(i) < h->size)
                printf("\t→");
        __print_heap(h, rc_idx(i), height + 1);
        if (lc_idx(i) < h->size)
                printf("\n%.*s↓", (int)height, tabs);
        __print_heap(h, lc_idx(i), 0);
}

////////////////////////////////////////////////////////////////////////////////

void __print_heap_obj(heap_obj a)
{
        struct heap *h = a.data;
        printf("\n");
        __print_heap(h, 0, 0);
}

////////////////////////////////////////////////////////////////////////////////

static int __cmp_heap(struct heap *a, struct heap *b, int i)
{
        if (i < 0 || a->size <= i)
                return 0;

        int l = __cmp_heap(a, b, lc_idx(i));
        int r = __cmp_heap(a, b, rc_idx(i));
        return !l ? l : !r ? r : 0;
}

////////////////////////////////////////////////////////////////////////////////

int __cmp_heap_obj(heap_obj a, heap_obj b)
{
        if (a.data == 0 && b.data == a.data)
                return 0;

        struct heap *lhs, *rhs;
        return lhs->size < rhs->size ? -1 : lhs->size > rhs->size ? 1 : __cmp_heap(lhs, rhs, 0);
}

////////////////////////////////////////////////////////////////////////////////
