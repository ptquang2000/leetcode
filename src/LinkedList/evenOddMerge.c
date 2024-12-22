#include "ListNode.h"
#include "utils.h"

// Declaration:
ListNode* LinkedList_evenOddMerge(ListNode* L);

void test_LinkedList_evenOddMerge()
{
        {
                ListNode *node, *L;
                node = &(ListNode){5, 0};
                node = &(ListNode){4, node};
                node = &(ListNode){3, node};
                node = &(ListNode){2, node};
                L = &(ListNode){1, node};
                node = LinkedList_evenOddMerge(L);

                int expected[] = {1, 3, 5, 2, 4};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                node = &(ListNode){7, 0};
                node = &(ListNode){4, node};
                node = &(ListNode){6, node};
                node = &(ListNode){5, node};
                node = &(ListNode){3, node};
                node = &(ListNode){1, node};
                L = &(ListNode){2, node};
                node = LinkedList_evenOddMerge(L);

                int expected[] = {2, 3, 6, 7, 1, 5, 4};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                node = LinkedList_evenOddMerge(0);
                UTILS_ASSERT_IS_NONE(node);
        }
}
