#include "ListNode.h"
#include "utils.h"

// Declaration:
ListNode* LinkedList_hasCycle(ListNode* L);

void test_LinkedList_hasCycle()
{
        {
                ListNode *node, *L, *end, *expected;
                end = &(ListNode){-4, 0};
                node = &(ListNode){0, end};
                expected = &(ListNode){2, node};
                L = &(ListNode){3, expected};
                end->next = expected;
                node = LinkedList_hasCycle(L);
                UTILS_ASSERT_IS(node, expected);
        }
        {
                ListNode *node, *L, *end, *expected;
                end = &(ListNode){2, 0};
                expected = &(ListNode){1, end};
                L = expected;
                end->next = expected;
                node = LinkedList_hasCycle(L);
                UTILS_ASSERT_IS(node, expected);
        }
        {
                ListNode *node, *L, *end, *expected;
                end = &(ListNode){2, 0};
                UTILS_ASSERT_IS_NONE(LinkedList_hasCycle(end));
        }
}
