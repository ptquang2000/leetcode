#include "list_node.h"
#include "utils/asserts.h"

extern struct list_node *linked_list_evenOddMerge(struct list_node *L);

void test_linked_list_evenOddMerge()
{
        ll_node_obj actual = {}, expected = {};
        {
                struct list_node *node, *L;
                node = &(struct list_node){5, 0};
                node = &(struct list_node){4, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){1, node};
                actual.data = linked_list_evenOddMerge(L);

                int foo[] = {1, 3, 5, 2, 4};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){7, 0};
                node = &(struct list_node){4, node};
                node = &(struct list_node){6, node};
                node = &(struct list_node){5, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){1, node};
                L = &(struct list_node){2, node};
                node = linked_list_evenOddMerge(L);

                int foo[] = {2, 3, 6, 7, 1, 5, 4};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L;
                actual.data = linked_list_evenOddMerge(0);
                ASSERT_IS_NULL(actual);
        }
}
