#include "heap/binary_heap.h"
#include "utils/asserts.h"

int main()
{
        struct heap *min_heap = &(struct heap){.maxheap = 0};

        ASSERT_EQUAL(min_heap->size, 0);

        heap_push(min_heap, 5);
        heap_push(min_heap, 3);
        heap_push(min_heap, 69);
        heap_push(min_heap, 420);
        heap_push(min_heap, 4);
        heap_push(min_heap, 1);
        heap_push(min_heap, 8);
        heap_push(min_heap, 7);

        ASSERT_EQUAL(min_heap->size, 8);
        ASSERT_EQUAL(heap_pop(min_heap), 1);
        ASSERT_EQUAL(heap_pop(min_heap), 3);
        ASSERT_EQUAL(heap_pop(min_heap), 4);
        ASSERT_EQUAL(heap_pop(min_heap), 5);
        ASSERT_EQUAL(min_heap->size, 4);
        ASSERT_EQUAL(heap_pop(min_heap), 7);
        ASSERT_EQUAL(heap_pop(min_heap), 8);
        ASSERT_EQUAL(heap_pop(min_heap), 69);
        ASSERT_EQUAL(heap_pop(min_heap), 420);
        ASSERT_EQUAL(min_heap->size, 0);

        struct heap *max_heap = &(struct heap){.maxheap = 1};

        ASSERT_EQUAL(max_heap->size, 0);

        heap_push(max_heap, 5);
        heap_push(max_heap, 3);
        heap_push(max_heap, 69);
        heap_push(max_heap, 420);
        heap_push(max_heap, 4);
        heap_push(max_heap, 1);
        heap_push(max_heap, 8);
        heap_push(max_heap, 7);

        ASSERT_EQUAL(max_heap->size, 8);
        ASSERT_EQUAL(heap_pop(max_heap), 420);
        ASSERT_EQUAL(heap_pop(max_heap), 69);
        ASSERT_EQUAL(heap_pop(max_heap), 8);
        ASSERT_EQUAL(heap_pop(max_heap), 7);
        ASSERT_EQUAL(max_heap->size, 4);
        ASSERT_EQUAL(heap_pop(max_heap), 5);
        ASSERT_EQUAL(heap_pop(max_heap), 4);
        ASSERT_EQUAL(heap_pop(max_heap), 3);
        ASSERT_EQUAL(heap_pop(max_heap), 1);
        ASSERT_EQUAL(max_heap->size, 0);
}
