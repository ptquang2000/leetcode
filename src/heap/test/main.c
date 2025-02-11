#include "heap/heap.h"
#define TEST_UTILS
#include "utils/utils.c"

int main()
{
        struct heap *h = &(struct heap){};

        UTILS_ASSERT_EQUAL(h->size, 0);

        heap_push(h, 5);
        heap_push(h, 3);
        heap_push(h, 69);
        heap_push(h, 420);
        heap_push(h, 4);
        heap_push(h, 1);
        heap_push(h, 8);
        heap_push(h, 7);

	UTILS_ASSERT_EQUAL(h->size, 8);
	UTILS_ASSERT_EQUAL(heap_pop(h), 1);
	UTILS_ASSERT_EQUAL(heap_pop(h), 3);
	UTILS_ASSERT_EQUAL(heap_pop(h), 4);
	UTILS_ASSERT_EQUAL(heap_pop(h), 5);
	UTILS_ASSERT_EQUAL(h->size, 4);
	UTILS_ASSERT_EQUAL(heap_pop(h), 7);
	UTILS_ASSERT_EQUAL(heap_pop(h), 8);
	UTILS_ASSERT_EQUAL(heap_pop(h), 69);
	UTILS_ASSERT_EQUAL(heap_pop(h), 420);
	UTILS_ASSERT_EQUAL(h->size, 0);
}
