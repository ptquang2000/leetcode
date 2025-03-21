#include "common.h"
#include "utils/asserts.h"

extern struct dsa_doubly_linked_list dsa_doubly_linked_list_ctor();

void test_dsa_doubly_linked_list()
{
        struct dsa_doubly_linked_list list = dsa_doubly_linked_list_ctor();
        struct dsa_doubly_linked_list *l = &list;

        ASSERT_TRUE(l->append != 0);
        ASSERT_TRUE(l->get != 0);
        ASSERT_TRUE(l->remove_at != 0);
        ASSERT_TRUE(l->remove != 0);
        ASSERT_TRUE(l->prepend != 0);
        ASSERT_TRUE(l->insert_at != 0);

        l->append(l, 5);
        l->append(l, 7);
        l->append(l, 9);

        ASSERT_EQUAL((int_obj){l->get(l, 2)}, (int_obj){9});
        ASSERT_EQUAL((int_obj){l->remove_at(l, 1)}, (int_obj){7});
        ASSERT_EQUAL((int_obj){l->length}, (int_obj){2});

        l->append(l, 11);
        ASSERT_EQUAL((int_obj){l->remove_at(l, 1)}, (int_obj){9});
        ASSERT_EQUAL((int_obj){l->remove(l, 9)}, (int_obj){-1});
        ASSERT_EQUAL((int_obj){l->remove_at(l, 0)}, (int_obj){5});
        ASSERT_EQUAL((int_obj){l->remove_at(l, 0)}, (int_obj){11});
        ASSERT_EQUAL((int_obj){l->length}, (int_obj){0});

        l->prepend(l, 5);
        l->prepend(l, 7);
        l->prepend(l, 9);

        ASSERT_EQUAL((int_obj){l->get(l, 2)}, (int_obj){5});
        ASSERT_EQUAL((int_obj){l->get(l, 0)}, (int_obj){9});
        ASSERT_EQUAL((int_obj){l->remove(l, 9)}, (int_obj){9});
        ASSERT_EQUAL((int_obj){l->length}, (int_obj){2});
        ASSERT_EQUAL((int_obj){l->get(l, 0)}, (int_obj){7});
}
