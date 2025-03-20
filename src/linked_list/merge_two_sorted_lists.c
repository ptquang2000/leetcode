#include "list_node.h"
#include "utils/asserts.h"

extern struct list_node *linked_list_mergeTwoSortedLists(struct list_node *L1, struct list_node *L2);

void test_linked_list_mergeTwoSortedLists()
{
        ll_node_obj actual = {}, expected = {};
        {
                struct list_node *node, *L1, *L2;
                node = &(struct list_node){4, 0};
                node = &(struct list_node){2, node};
                L1 = &(struct list_node){1, node};
                node = &(struct list_node){4, 0};
                node = &(struct list_node){3, node};
                L2 = &(struct list_node){1, node};
                actual.data = linked_list_mergeTwoSortedLists(L1, L2);

                int foo[] = {1, 1, 2, 3, 4, 4};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L1, *L2;
                node = &(struct list_node){7, 0};
                node = &(struct list_node){5, node};
                L1 = &(struct list_node){2, node};
                node = &(struct list_node){11, 0};
                L2 = &(struct list_node){3, node};
                actual.data = linked_list_mergeTwoSortedLists(L1, L2);

                int foo[] = {2, 3, 5, 7, 11};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L1, *L2;
                actual.data = linked_list_mergeTwoSortedLists(0, 0);
                ASSERT_IS_NULL(actual);
        }
        {
                struct list_node *node, *L1, *L2;
                L2 = &(struct list_node){0, 0};
                actual.data = linked_list_mergeTwoSortedLists(0, L2);

                int foo[] = {0};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
}
