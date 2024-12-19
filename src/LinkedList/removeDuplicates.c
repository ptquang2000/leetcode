#include "ListNode.h"
#include "utils.h"

// Declaration:
ListNode* LinkedList_removeDuplicates(ListNode* L);

void test_LinkedList_removeDuplicates()
{
        {
                ListNode *node, *L;
                node = &(ListNode){2, 0};
                node = &(ListNode){1, node};
                L = &(ListNode){1, node};
                node = LinkedList_removeDuplicates(L);

                int expected[] = {1, 2};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                node = &(ListNode){3, 0};
                node = &(ListNode){3, node};
                node = &(ListNode){2, node};
                node = &(ListNode){1, node};
                L = &(ListNode){1, node};
                node = LinkedList_removeDuplicates(L);

                int expected[] = {1, 2, 3};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                node = &(ListNode){11, 0};
                node = &(ListNode){11, node};
                node = &(ListNode){7, node};
                node = &(ListNode){5, node};
                node = &(ListNode){3, node};
                node = &(ListNode){2, node};
                L = &(ListNode){2, node};
                node = LinkedList_removeDuplicates(L);

                int expected[] = {2, 3, 5, 7, 11};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                ListNode_ToList(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
}
