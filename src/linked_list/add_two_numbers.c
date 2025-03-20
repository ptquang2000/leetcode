#include "list_node.h"
#include "utils/asserts.h"

extern struct list_node *linked_list_addTwoNumbers(struct list_node *L1, struct list_node *L2);

void test_linked_list_addTwoNumbers()
{
        ll_node_obj actual = {}, expected = {};
        {
                struct list_node *node, *L1, *L2;
                node = &(struct list_node){4, 0};
                node = &(struct list_node){1, node};
                L1 = &(struct list_node){3, node};
                node = &(struct list_node){9, 0};
                node = &(struct list_node){0, node};
                L2 = &(struct list_node){7, node};
                actual.data = linked_list_addTwoNumbers(L1, L2);

                int foo[] = {0, 2, 3, 1};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L1, *L2;
                node = &(struct list_node){3, 0};
                node = &(struct list_node){4, node};
                L1 = &(struct list_node){2, node};
                node = &(struct list_node){4, 0};
                node = &(struct list_node){6, node};
                L2 = &(struct list_node){5, node};
                actual.data = linked_list_addTwoNumbers(L1, L2);

                int foo[] = {7, 0, 8};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
        }
        {
                struct list_node *node, *L1, *L2;
                L1 = &(struct list_node){0, 0};
                L2 = &(struct list_node){0, 0};
                actual.data = linked_list_addTwoNumbers(L1, L2);

                int foo[] = {0};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L1, *L2;
                node = &(struct list_node){9, 0};
                node = &(struct list_node){9, node};
                node = &(struct list_node){9, node};
                node = &(struct list_node){9, node};
                node = &(struct list_node){9, node};
                node = &(struct list_node){9, node};
                L1 = &(struct list_node){9, node};
                node = &(struct list_node){9, 0};
                node = &(struct list_node){9, node};
                node = &(struct list_node){9, node};
                L2 = &(struct list_node){9, node};
                actual.data = linked_list_addTwoNumbers(L1, L2);

                int foo[] = {8, 9, 9, 9, 0, 0, 0, 1};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
}
