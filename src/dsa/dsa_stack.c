#include "common.h"
#include "utils/asserts.h"

extern struct dsa_stack dsa_stack_ctor();

void test_dsa_stack()
{
        struct dsa_stack stack = dsa_stack_ctor();
        struct dsa_stack *s = &stack;

        ASSERT_TRUE(s->push != 0);
        ASSERT_TRUE(s->pop != 0);
        ASSERT_TRUE(s->peek != 0);

        s->push(s, 5);
        s->push(s, 7);
        s->push(s, 9);

        ASSERT_EQUAL(s->pop(s), 9);
        ASSERT_EQUAL(s->length, 2);

        s->push(s, 11);

        ASSERT_EQUAL(s->pop(s), 11);
        ASSERT_EQUAL(s->pop(s), 7);
        ASSERT_EQUAL(s->peek(s), 5);
        ASSERT_EQUAL(s->pop(s), 5);
        ASSERT_EQUAL(s->pop(s), -1);

        s->push(s, 69);
        ASSERT_EQUAL(s->peek(s), 69);
        ASSERT_EQUAL(s->length, 1);
}
