#include "common.h"
#include "utils/utils.h"

extern struct dsa_doubly_linked_list dsa_doubly_linked_list_ctor();

void test_dsa_doubly_linked_list()
{
        struct dsa_doubly_linked_list list = dsa_doubly_linked_list_ctor();
        struct dsa_doubly_linked_list *l = &list;

        UTILS_ASSERT_TRUE(l->append != 0);
        UTILS_ASSERT_TRUE(l->get != 0);
        UTILS_ASSERT_TRUE(l->remove_at != 0);
        UTILS_ASSERT_TRUE(l->remove != 0);
        UTILS_ASSERT_TRUE(l->prepend != 0);
        UTILS_ASSERT_TRUE(l->insert_at != 0);

        l->append(l, 5);
        l->append(l, 7);
        l->append(l, 9);

        UTILS_ASSERT_EQUAL(l->get(l, 2), 9);
        UTILS_ASSERT_EQUAL(l->remove_at(l, 1), 7);
        UTILS_ASSERT_EQUAL(l->length, 2);

        l->append(l, 11);
        UTILS_ASSERT_EQUAL(l->remove_at(l, 1), 9);
        UTILS_ASSERT_EQUAL(l->remove(l, 9), -1);
        UTILS_ASSERT_EQUAL(l->remove_at(l, 0), 5);
        UTILS_ASSERT_EQUAL(l->remove_at(l, 0), 11);
        UTILS_ASSERT_EQUAL(l->length, 0);

        l->prepend(l, 5);
        l->prepend(l, 7);
        l->prepend(l, 9);

        UTILS_ASSERT_EQUAL(l->get(l, 2), 5);
        UTILS_ASSERT_EQUAL(l->get(l, 0), 9);
        UTILS_ASSERT_EQUAL(l->remove(l, 9), 9);
        UTILS_ASSERT_EQUAL(l->length, 2);
        UTILS_ASSERT_EQUAL(l->get(l, 0), 7);
}
