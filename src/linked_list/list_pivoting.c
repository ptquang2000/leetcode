#include "list_node.h"
#include "utils/asserts.h"

extern struct list_node *linked_list_listPivoting(struct list_node *L, int x);

void test_linked_list_listPivoting()
{
        ll_node_obj actual = {}, expected = {};
        {
                struct list_node *node, *L;
                node = &(struct list_node){11, 0};
                node = &(struct list_node){5, node};
                node = &(struct list_node){7, node};
                node = &(struct list_node){11, node};
                node = &(struct list_node){2, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){3, node};
                actual.data = linked_list_listPivoting(L, 7);

                int foo[] = {3, 2, 2, 5, 7, 11, 11};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){2, 0};
                node = &(struct list_node){5, node};
                node = &(struct list_node){2, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){4, node};
                L = &(struct list_node){1, node};
                actual.data = linked_list_listPivoting(L, 3);

                int foo[] = {1, 2, 2, 3, 4, 5};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){1, 0};
                L = &(struct list_node){2, node};
                actual.data = linked_list_listPivoting(L, 2);

                int foo[] = {1, 2};
                expected.data = FROM_LIST(ARRAY_SIZE(foo), foo);
                ASSERT_EQUAL(actual, expected);
                FREE_LIST(actual.data);
                FREE_LIST(expected.data);
        }
}
