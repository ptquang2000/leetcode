#include "common.h"
#include "utils/asserts.h"

extern struct LRU dsa_LRU_ctor(int capacity);

void test_dsa_LRU()
{
        struct LRU LRU = dsa_LRU_ctor(3);
        struct LRU *lru = &LRU;

        ASSERT_TRUE(lru->get != 0);
        ASSERT_TRUE(lru->update != 0);

        ASSERT_EQUAL((int_obj){lru->get(lru, "foo")}, (int_obj){-1});
        lru->update(lru, "foo", 69);
        ASSERT_EQUAL((int_obj){lru->get(lru, "foo")}, (int_obj){69});

        lru->update(lru, "bar", 420);
        ASSERT_EQUAL((int_obj){lru->get(lru, "bar")}, (int_obj){420});

        lru->update(lru, "baz", 1337);
        ASSERT_EQUAL((int_obj){lru->get(lru, "baz")}, (int_obj){1337});

        lru->update(lru, "ball", 69420);
        ASSERT_EQUAL((int_obj){lru->get(lru, "ball")}, (int_obj){69420});
        ASSERT_EQUAL((int_obj){lru->get(lru, "foo")}, (int_obj){-1});
        ASSERT_EQUAL((int_obj){lru->get(lru, "bar")}, (int_obj){420});
        lru->update(lru, "foo", 69);
        ASSERT_EQUAL((int_obj){lru->get(lru, "bar")}, (int_obj){420});
        ASSERT_EQUAL((int_obj){lru->get(lru, "foo")}, (int_obj){69});

        ASSERT_EQUAL((int_obj){lru->get(lru, "baz")}, (int_obj){-1});
}
