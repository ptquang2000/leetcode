#include "common.h"
#include "utils/utils.h"

extern struct dsa_stack dsa_stack_ctor();

void test_dsa_stack()
{
        struct dsa_stack *s;
        *s = dsa_stack_ctor();

        s->push(s, 5);
        s->push(s, 7);
        s->push(s, 9);

        UTILS_ASSERT_EQUAL(s->pop(s), 9);
        UTILS_ASSERT_EQUAL(s->length, 2);

        s->push(s, 11);

        UTILS_ASSERT_EQUAL(s->pop(s), 11);
        UTILS_ASSERT_EQUAL(s->pop(s), 7);
        UTILS_ASSERT_EQUAL(s->peek(s), 5);
        UTILS_ASSERT_EQUAL(s->pop(s), 5);
        UTILS_ASSERT_EQUAL(s->pop(s), -1);

        s->push(s, 69);
        UTILS_ASSERT_EQUAL(s->peek(s), 69);
        UTILS_ASSERT_EQUAL(s->length, 1);
}
