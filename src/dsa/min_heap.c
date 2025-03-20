#include "common.h"
#include "utils/asserts.h"

extern struct min_heap dsa_min_heap_ctor();

void test_dsa_min_heap()
{
        struct min_heap heap = dsa_min_heap_ctor();
        struct min_heap *h = &heap;

        ASSERT_TRUE(h->insert != 0);
        ASSERT_TRUE(h->delete != 0);
        ASSERT_EQUAL((int_obj){h->length}, (int_obj){0});

        h->insert(h, 5);
        h->insert(h, 3);
        h->insert(h, 69);
        h->insert(h, 420);
        h->insert(h, 4);
        h->insert(h, 1);
        h->insert(h, 8);
        h->insert(h, 7);

        ASSERT_EQUAL((int_obj){h->length}, (int_obj){8});
        ASSERT_EQUAL((int_obj){h->delete(h)}, (int_obj){1});
        ASSERT_EQUAL((int_obj){h->delete(h)}, (int_obj){3});
        ASSERT_EQUAL((int_obj){h->delete(h)}, (int_obj){4});
        ASSERT_EQUAL((int_obj){h->delete(h)}, (int_obj){5});
        ASSERT_EQUAL((int_obj){h->length}, (int_obj){4});
        ASSERT_EQUAL((int_obj){h->delete(h)}, (int_obj){7});
        ASSERT_EQUAL((int_obj){h->delete(h)}, (int_obj){8});
        ASSERT_EQUAL((int_obj){h->delete(h)}, (int_obj){69});
        ASSERT_EQUAL((int_obj){h->delete(h)}, (int_obj){420});
        ASSERT_EQUAL((int_obj){h->length}, (int_obj){0});
}
