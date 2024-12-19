#include "ListNode.h"
#include "utils.h"

// Declaration:
ListNode* LinkedList_removeKthLast(ListNode* L, int k);

void test_LinkedList_removeKthLast()
{
        {
                ListNode *node, *L;
                node = &(ListNode){5, 0};
                node = &(ListNode){4, node};
                node = &(ListNode){3, node};
                node = &(ListNode){2, node};
                L = &(ListNode){1, node};
                node = LinkedList_removeKthLast(L, 2);

                int expected[] = {1, 2, 3, 5};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                L = &(ListNode){1, 0};
                node = LinkedList_removeKthLast(L, 1);

                int expected[] = {};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                node = &(ListNode){2, 0};
                L = &(ListNode){1, node};
                node = LinkedList_removeKthLast(L, 1);

                int expected[] = {1};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
}
