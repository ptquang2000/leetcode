#include "ListNode.h"
#include "utils.h"

// Declaration:
void LinkedList_deletionFromList(ListNode* nodeToDelete);

void test_LinkedList_deletionFromList()
{
        {
                ListNode *node, *L, *deletedNode;
                node = &(ListNode){9, 0};
                node = &(ListNode){1, node};
                deletedNode = &(ListNode){5, node};
                L = &(ListNode){4, node};
                LinkedList_deletionFromList(deletedNode);

                UTILS_ASSERT_EQUAL(deletedNode->data, 1);
                UTILS_ASSERT_EQUAL(deletedNode->next->data, 9);

                int expected[] = {4, 1, 9};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(L, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L, *deletedNode;
                node = &(ListNode){9, 0};
                deletedNode = &(ListNode){1, node};
                node = &(ListNode){5, node};
                L = &(ListNode){4, node};
                LinkedList_deletionFromList(deletedNode);

                UTILS_ASSERT_EQUAL(deletedNode->data, 9);
                UTILS_ASSERT_IS_NONE(deletedNode->next);

                int expected[] = {4, 5, 9};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(L, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
}
