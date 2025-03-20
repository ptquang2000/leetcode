#include "list_node.h"
#include "utils/asserts.h"

extern struct list_node *linked_list_reverseSublist(struct list_node *L, int start, int finish);

void test_linked_list_reverseSublist()
{
        ll_node_obj actual, expected;
        {
                struct list_node *node, *L;
                node = &(struct list_node){5, 0};
                node = &(struct list_node){4, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){1, node};
                actual.data = linked_list_reverseSublist(L, 2, 4);

                int foo[] = {1, 4, 3, 2, 5};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){2, 0};
                node = &(struct list_node){7, node};
                node = &(struct list_node){5, node};
                node = &(struct list_node){3, node};
                L = &(struct list_node){11, node};
                actual.data = linked_list_reverseSublist(L, 2, 4);

                int foo[] = {11, 7, 5, 3, 2};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L;
                L = &(struct list_node){5, 0};
                actual.data = linked_list_reverseSublist(L, 1, 1);

                int foo[] = {5};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
}
