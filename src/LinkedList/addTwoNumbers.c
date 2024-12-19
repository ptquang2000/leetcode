#include "ListNode.h"
#include "utils.h"

#include <stdlib.h>

// Declaration:
ListNode* LinkedList_addTwoNumbers(ListNode* L1, ListNode* L2);

void test_LinkedList_addTwoNumbers()
{
        {
                ListNode *node, *L1, *L2;
                node = &(ListNode){4, 0};
                node = &(ListNode){1, node};
                L1 = &(ListNode){3, node};
                node = &(ListNode){9, 0};
                node = &(ListNode){0, node};
                L2 = &(ListNode){7, node};
                node = LinkedList_addTwoNumbers(L1, L2);

                int expected[] = {0, 2, 3, 1};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
                free(node);
        }
        {
                ListNode *node, *L1, *L2;
                node = &(ListNode){3, 0};
                node = &(ListNode){4, node};
                L1 = &(ListNode){2, node};
                node = &(ListNode){4, 0};
                node = &(ListNode){6, node};
                L2 = &(ListNode){5, node};
                node = LinkedList_addTwoNumbers(L1, L2);

                int expected[] = {7, 0, 8};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L1, *L2;
                L1 = &(ListNode){0, node};
                L2 = &(ListNode){0, node};
                node = LinkedList_addTwoNumbers(L1, L2);

                int expected[] = {0};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L1, *L2;
                node = &(ListNode){9, 0};
                node = &(ListNode){9, node};
                node = &(ListNode){9, node};
                node = &(ListNode){9, node};
                node = &(ListNode){9, node};
                node = &(ListNode){9, node};
                L1 = &(ListNode){9, node};
                node = &(ListNode){9, 0};
                node = &(ListNode){9, node};
                node = &(ListNode){9, node};
                L2 = &(ListNode){9, node};
                node = LinkedList_addTwoNumbers(L1, L2);

                int expected[] = {8, 9, 9, 9, 0, 0, 0, 1};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
                free(node);
        }
}
