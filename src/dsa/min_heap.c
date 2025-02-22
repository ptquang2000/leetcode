#include "common.h"
#include "utils/utils.h"

extern struct min_heap dsa_min_heap_ctor();

void test_dsa_min_heap()
{
        struct min_heap heap = dsa_min_heap_ctor();
        struct min_heap *h = &heap;

        UTILS_ASSERT_TRUE(h->insert != 0);
        UTILS_ASSERT_TRUE(h->delete != 0);
        UTILS_ASSERT_EQUAL(h->length, 0);

        h->insert(h, 5);
        h->insert(h, 3);
        h->insert(h, 69);
        h->insert(h, 420);
        h->insert(h, 4);
        h->insert(h, 1);
        h->insert(h, 8);
        h->insert(h, 7);

        UTILS_ASSERT_EQUAL(h->length, 8);
        UTILS_ASSERT_EQUAL(h->delete(h), 1);
        UTILS_ASSERT_EQUAL(h->delete(h), 3);
        UTILS_ASSERT_EQUAL(h->delete(h), 4);
        UTILS_ASSERT_EQUAL(h->delete(h), 5);
        UTILS_ASSERT_EQUAL(h->length, 4);
        UTILS_ASSERT_EQUAL(h->delete(h), 7);
        UTILS_ASSERT_EQUAL(h->delete(h), 8);
        UTILS_ASSERT_EQUAL(h->delete(h), 69);
        UTILS_ASSERT_EQUAL(h->delete(h), 420);
        UTILS_ASSERT_EQUAL(h->length, 0);
}
