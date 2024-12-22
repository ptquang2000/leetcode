#include "ListNode.h"
#include "utils.h"

// Declaration:
ListNode* LinkedList_mergeTwoSortedLists(ListNode* L1, ListNode* L2);

void test_LinkedList_mergeTwoSortedLists()
{
        {
                ListNode *node, *L1, *L2;
                node = &(ListNode){4, 0};
                node = &(ListNode){2, node};
                L1 = &(ListNode){1, node};
                node = &(ListNode){4, 0};
                node = &(ListNode){3, node};
                L2 = &(ListNode){1, node};
                node = LinkedList_mergeTwoSortedLists(L1, L2);

                int expected[] = {1, 1, 2, 3, 4, 4};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L1, *L2;
                node = &(ListNode){7, 0};
                node = &(ListNode){5, node};
                L1 = &(ListNode){2, node};
                node = &(ListNode){11, 0};
                L2 = &(ListNode){3, node};
                node = LinkedList_mergeTwoSortedLists(L1, L2);

                int expected[] = {2, 3, 5, 7, 11};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L1, *L2;
                node = LinkedList_mergeTwoSortedLists(0, 0);
                UTILS_ASSERT_IS_NONE(node);
        }
        {
                ListNode *node, *L1, *L2;
                L2 = &(ListNode){0, 0};
                node = LinkedList_mergeTwoSortedLists(0, L2);

                int expected[] = {0};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
}
