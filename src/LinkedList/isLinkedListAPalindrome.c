#include "ListNode.h"
#include "utils.h"

#include <stdbool.h>

// Declaration:
bool LinkedList_isLinkedListAPalindrome(ListNode* L);

void test_LinkedList_isLinkedListAPalindrome()
{
        {
                ListNode *node, *L;
                node = &(ListNode){1, 0};
                node = &(ListNode){2, node};
                node = &(ListNode){2, node};
                L = &(ListNode){1, node};
                UTILS_ASSERT_TRUE(LinkedList_isLinkedListAPalindrome(L));
        }
        {
                ListNode *node, *L;
                node = &(ListNode){1, 0};
                L = &(ListNode){2, node};
                UTILS_ASSERT_FALSE(LinkedList_isLinkedListAPalindrome(L));
        }
}
