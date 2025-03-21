#include "heap/binary_heap.h"
#include "utils/asserts.h"

int main()
{
        struct heap *min_heap = &(struct heap){.maxheap = 0};

        ASSERT_EQUAL((int_obj){min_heap->size}, (int_obj){0});

        heap_push(min_heap, 5);
        heap_push(min_heap, 3);
        heap_push(min_heap, 69);
        heap_push(min_heap, 420);
        heap_push(min_heap, 4);
        heap_push(min_heap, 1);
        heap_push(min_heap, 8);
        heap_push(min_heap, 7);

        UTILS_LOG("min_heap={}", (heap_obj){min_heap});

        ASSERT_EQUAL((int_obj){min_heap->size}, (int_obj){8});
        ASSERT_EQUAL((int_obj){heap_pop(min_heap)}, (int_obj){1});
        ASSERT_EQUAL((int_obj){heap_pop(min_heap)}, (int_obj){3});
        ASSERT_EQUAL((int_obj){heap_pop(min_heap)}, (int_obj){4});
        ASSERT_EQUAL((int_obj){heap_pop(min_heap)}, (int_obj){5});
        ASSERT_EQUAL((int_obj){min_heap->size}, (int_obj){4});
        ASSERT_EQUAL((int_obj){heap_pop(min_heap)}, (int_obj){7});
        ASSERT_EQUAL((int_obj){heap_pop(min_heap)}, (int_obj){8});
        ASSERT_EQUAL((int_obj){heap_pop(min_heap)}, (int_obj){69});
        ASSERT_EQUAL((int_obj){heap_pop(min_heap)}, (int_obj){420});
        ASSERT_EQUAL((int_obj){min_heap->size}, (int_obj){0});

        struct heap *max_heap = &(struct heap){.maxheap = 1};

        ASSERT_EQUAL((int_obj){max_heap->size}, (int_obj){0});

        heap_push(max_heap, 5);
        heap_push(max_heap, 3);
        heap_push(max_heap, 69);
        heap_push(max_heap, 420);
        heap_push(max_heap, 4);
        heap_push(max_heap, 1);
        heap_push(max_heap, 8);
        heap_push(max_heap, 7);

        UTILS_LOG("max_heap={}", (heap_obj){max_heap});

        ASSERT_EQUAL((int_obj){max_heap->size}, (int_obj){8});
        ASSERT_EQUAL((int_obj){heap_pop(max_heap)}, (int_obj){420});
        ASSERT_EQUAL((int_obj){heap_pop(max_heap)}, (int_obj){69});
        ASSERT_EQUAL((int_obj){heap_pop(max_heap)}, (int_obj){8});
        ASSERT_EQUAL((int_obj){heap_pop(max_heap)}, (int_obj){7});
        ASSERT_EQUAL((int_obj){max_heap->size}, (int_obj){4});
        ASSERT_EQUAL((int_obj){heap_pop(max_heap)}, (int_obj){5});
        ASSERT_EQUAL((int_obj){heap_pop(max_heap)}, (int_obj){4});
        ASSERT_EQUAL((int_obj){heap_pop(max_heap)}, (int_obj){3});
        ASSERT_EQUAL((int_obj){heap_pop(max_heap)}, (int_obj){1});
        ASSERT_EQUAL((int_obj){max_heap->size}, (int_obj){0});
}
