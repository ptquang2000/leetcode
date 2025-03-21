#include "list_node.h"
#include "utils/asserts.h"

extern void linked_list_deletionFromList(struct list_node *nodeToDelete);

void test_linked_list_deletionFromList()
{
        {
                struct list_node *node, *L, *deletedNode;
                node = &(struct list_node){9, 0};
                node = &(struct list_node){1, node};
                deletedNode = &(struct list_node){5, node};
                L = &(struct list_node){4, node};
                linked_list_deletionFromList(deletedNode);

                ASSERT_EQUAL((int_obj){deletedNode->data}, (int_obj){1});
                ASSERT_EQUAL((int_obj){deletedNode->next->data}, (int_obj){9});

                int_array expected = {(int[]){4, 1, 9}, 3};
                int_array actual = {(int[]){}, 0};
                TO_LIST(L, actual.len, actual.data);
                ASSERT_EQUAL(actual, expected);
        }
        {
                struct list_node *node, *L, *deletedNode;
                node = &(struct list_node){9, 0};
                deletedNode = &(struct list_node){1, node};
                node = &(struct list_node){5, node};
                L = &(struct list_node){4, node};
                linked_list_deletionFromList(deletedNode);

                ASSERT_EQUAL((int_obj){deletedNode->data}, (int_obj){9});
                ASSERT_IS_NULL((ll_node_obj){deletedNode->next});

                int_array expected = {(int[]){4, 5, 9}, 3};
                int_array actual = {(int[]){}, 0};
                TO_LIST(L, actual.len, actual.data);
                ASSERT_EQUAL(actual, expected);
        }
}
