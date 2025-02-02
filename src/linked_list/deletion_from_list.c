#include "list_node.h"
#include "utils/utils.h"

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

                UTILS_ASSERT_EQUAL(deletedNode->data, 1);
                UTILS_ASSERT_EQUAL(deletedNode->next->data, 9);

                int expected[] = {4, 1, 9};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(L, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L, *deletedNode;
                node = &(struct list_node){9, 0};
                deletedNode = &(struct list_node){1, node};
                node = &(struct list_node){5, node};
                L = &(struct list_node){4, node};
                linked_list_deletionFromList(deletedNode);

                UTILS_ASSERT_EQUAL(deletedNode->data, 9);
                UTILS_ASSERT_IS_NONE(deletedNode->next);

                int expected[] = {4, 5, 9};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(L, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
}
