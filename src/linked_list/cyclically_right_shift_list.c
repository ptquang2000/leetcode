#include "list_node.h"
#include "utils/asserts.h"
#include "utils/type.h"

extern struct list_node *linked_list_cyclicallyRightShiftList(struct list_node *L, int k);

void test_linked_list_cyclicallyRightShiftList()
{
        ll_node_obj actual, expected;
        {
                struct list_node *node, *L;
                node = &(struct list_node){5, 0};
                node = &(struct list_node){4, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){1, node};
                actual.data = linked_list_cyclicallyRightShiftList(L, 2);

                int foo[] = {4, 5, 1, 2, 3};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){5, 0};
                node = &(struct list_node){4, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){1, node};
                actual.data = linked_list_cyclicallyRightShiftList(L, 12);

                int foo[] = {4, 5, 1, 2, 3};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){2, 0};
                node = &(struct list_node){1, node};
                L = &(struct list_node){0, node};
                actual.data = linked_list_cyclicallyRightShiftList(L, 4);

                int foo[] = {2, 0, 1};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L;
                L = 0;
                actual.data = linked_list_cyclicallyRightShiftList(L, 4);
                ASSERT_IS_NULL((ll_node_obj){node});
        }
}
