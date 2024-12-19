#include "ListNode.h"
#include "utils.h"

// Declaration:
ListNode* LinkedList_cyclicallyRightShiftList(ListNode* L, int k);

void test_LinkedList_cyclicallyRightShiftList()
{
        {
                ListNode *node, *L;
                node = &(ListNode){5, 0};
                node = &(ListNode){4, node};
                node = &(ListNode){3, node};
                node = &(ListNode){2, node};
                L = &(ListNode){1, node};
                node = LinkedList_cyclicallyRightShiftList(L, 2);

                int expected[] = {4, 5, 1, 2, 3};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                node = &(ListNode){5, 0};
                node = &(ListNode){4, node};
                node = &(ListNode){3, node};
                node = &(ListNode){2, node};
                L = &(ListNode){1, node};
                node = LinkedList_cyclicallyRightShiftList(L, 12);

                int expected[] = {4, 5, 1, 2, 3};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                node = &(ListNode){2, 0};
                node = &(ListNode){1, node};
                L = &(ListNode){0, node};
                node = LinkedList_cyclicallyRightShiftList(L, 4);

                int expected[] = {2, 0, 1};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                L = 0;
                node = LinkedList_cyclicallyRightShiftList(L, 4);
                UTILS_ASSERT_IS_NONE(node);
        }
}
