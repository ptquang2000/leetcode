#include "common.h"
#include "utils/asserts.h"

extern struct min_heap dsa_min_heap_ctor();

void test_dsa_min_heap()
{
        struct min_heap heap = dsa_min_heap_ctor();
        struct min_heap *h = &heap;

        ASSERT_TRUE(h->insert != 0);
        ASSERT_TRUE(h->delete != 0);
        ASSERT_EQUAL(h->length, 0);

        h->insert(h, 5);
        h->insert(h, 3);
        h->insert(h, 69);
        h->insert(h, 420);
        h->insert(h, 4);
        h->insert(h, 1);
        h->insert(h, 8);
        h->insert(h, 7);

        ASSERT_EQUAL(h->length, 8);
        ASSERT_EQUAL(h->delete(h), 1);
        ASSERT_EQUAL(h->delete(h), 3);
        ASSERT_EQUAL(h->delete(h), 4);
        ASSERT_EQUAL(h->delete(h), 5);
        ASSERT_EQUAL(h->length, 4);
        ASSERT_EQUAL(h->delete(h), 7);
        ASSERT_EQUAL(h->delete(h), 8);
        ASSERT_EQUAL(h->delete(h), 69);
        ASSERT_EQUAL(h->delete(h), 420);
        ASSERT_EQUAL(h->length, 0);
}
