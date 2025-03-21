#include "common.h"
#include "utils/asserts.h"

extern struct dsa_queue dsa_queue_ctor();

void test_dsa_queue()
{
        struct dsa_queue queue = dsa_queue_ctor();
        struct dsa_queue *q = &queue;

        ASSERT_TRUE(q->enqueue != 0);
        ASSERT_TRUE(q->deque != 0);
        ASSERT_TRUE(q->peek != 0);

        q->enqueue(q, 5);
        q->enqueue(q, 7);
        q->enqueue(q, 9);

        ASSERT_EQUAL((int_obj){q->deque(q)}, (int_obj){5});
        ASSERT_EQUAL((int_obj){q->length}, (int_obj){2});

        q->enqueue(q, 11);

        ASSERT_EQUAL((int_obj){q->deque(q)}, (int_obj){7});
        ASSERT_EQUAL((int_obj){q->deque(q)}, (int_obj){9});
        ASSERT_EQUAL((int_obj){q->peek(q)}, (int_obj){11});
        ASSERT_EQUAL((int_obj){q->deque(q)}, (int_obj){11});
        ASSERT_EQUAL((int_obj){q->deque(q)}, (int_obj){-1});
        ASSERT_EQUAL((int_obj){q->length}, (int_obj){0});

        q->enqueue(q, 69);
        ASSERT_EQUAL((int_obj){q->peek(q)}, (int_obj){69});
        ASSERT_EQUAL((int_obj){q->length}, (int_obj){1});
}
