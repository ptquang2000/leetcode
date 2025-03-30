#include "utils/asserts.h"

extern struct list_node *linked_list_removeKthLast(struct list_node *L, int k);

void test_linked_list_removeKthLast()
{
        ll_node_obj actual = {}, expected = {};
        {
                struct list_node *node, *L;
                node = &(struct list_node){5, 0};
                node = &(struct list_node){4, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){1, node};
                actual.data = linked_list_removeKthLast(L, 2);

                int foo[] = {1, 2, 3, 5};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L;
                L = &(struct list_node){1, 0};
                actual.data = linked_list_removeKthLast(L, 1);

                int foo[] = {};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){2, 0};
                L = &(struct list_node){1, node};
                actual.data = linked_list_removeKthLast(L, 1);

                int foo[] = {1};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(expected.data);
        }
}
