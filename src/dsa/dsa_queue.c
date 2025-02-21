#include "common.h"
#include "utils/utils.h"

extern struct dsa_queue dsa_queue_ctor();

void test_dsa_queue()
{
        struct dsa_queue *q;
        *q = dsa_queue_ctor();

        q->enqueue(q, 5);
        q->enqueue(q, 7);
        q->enqueue(q, 9);

        UTILS_ASSERT_EQUAL(q->deque(q), 5);
        UTILS_ASSERT_EQUAL(q->length, 2);

        q->enqueue(q, 11);

        UTILS_ASSERT_EQUAL(q->deque(q), 7);
        UTILS_ASSERT_EQUAL(q->deque(q), 9);
        UTILS_ASSERT_EQUAL(q->peek(q), 11);
        UTILS_ASSERT_EQUAL(q->deque(q), 11);
        UTILS_ASSERT_EQUAL(q->deque(q), -1);
        UTILS_ASSERT_EQUAL(q->length, 0);

        q->enqueue(q, 69);
        UTILS_ASSERT_EQUAL(q->peek(q), 69);
        UTILS_ASSERT_EQUAL(q->length, 1);
}
