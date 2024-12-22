#include "ListNode.h"
#include "utils.h"

// Declaration:
ListNode* LinkedList_listPivoting(ListNode* L, int x);

void test_LinkedList_listPivoting()
{
        {
                ListNode *node, *L;
                node = &(ListNode){11, 0};
                node = &(ListNode){5, node};
                node = &(ListNode){7, node};
                node = &(ListNode){11, node};
                node = &(ListNode){2, node};
                node = &(ListNode){2, node};
                L = &(ListNode){3, node};
                node = LinkedList_listPivoting(L, 7);

                int expected[] = {3, 2, 2, 5, 7, 11, 11};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                node = &(ListNode){2, 0};
                node = &(ListNode){5, node};
                node = &(ListNode){2, node};
                node = &(ListNode){3, node};
                node = &(ListNode){4, node};
                L = &(ListNode){1, node};
                node = LinkedList_listPivoting(L, 3);

                int expected[] = {1, 2, 2, 3, 4, 5};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                ListNode *node, *L;
                node = &(ListNode){1, 0};
                L = &(ListNode){2, node};
                node = LinkedList_listPivoting(L, 2);

                int expected[] = {1, 2};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected));
        }
}
