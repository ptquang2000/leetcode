#include "ListNode.h"
#include "utils.h"

// Declaration:
ListNode* LinkedList_reverseSublist(ListNode* L, int start, int finish);

void test_LinkedList_reverseSublist()
{
        {
                ListNode *node, *L;
                node = &(ListNode){5, 0};
                node = &(ListNode){4, node};
                node = &(ListNode){3, node};
                node = &(ListNode){2, node};
                L = &(ListNode){1, node};
                node = LinkedList_reverseSublist(L, 2, 4);

                int expected[] = {1, 4, 3, 2, 5};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                node = &(ListNode){2, 0};
                node = &(ListNode){7, node};
                node = &(ListNode){5, node};
                node = &(ListNode){3, node};
                L = &(ListNode){11, node};
                node = LinkedList_reverseSublist(L, 2, 4);

                int expected[] = {11, 7, 5, 3, 2};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                L = &(ListNode){5, 0};
                node = LinkedList_reverseSublist(L, 1, 1);

                int expected[] = {5};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
}
