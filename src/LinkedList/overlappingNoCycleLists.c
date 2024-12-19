#include "ListNode.h"
#include "utils.h"

// Declaration:
ListNode* LinkedList_overlappingNoCycleLists(ListNode* L1, ListNode* L2);

void test_LinkedList_overlappingNoCycleLists()
{
        {
                ListNode *node, *L1, *L2, *L3;
                node = &(ListNode){5, 0};
                node = &(ListNode){4, node};
                L3 = &(ListNode){8, node};
                node = &(ListNode){1, L3};
                L1 = &(ListNode){4, node};
                node = &(ListNode){1, L3};
                node = &(ListNode){6, node};
                L2 = &(ListNode){5, node};
                UTILS_ASSERT_IS(LinkedList_overlappingNoCycleLists(L1, L2), L3);
        }
        {
                ListNode *node, *L1, *L2, *L3;
                node = &(ListNode){4, 0};
                L3 = &(ListNode){2, node};
                node = &(ListNode){1, L3};
                node = &(ListNode){9, node};
                L1 = &(ListNode){1, node};
                L2 = &(ListNode){3, L3};
                UTILS_ASSERT_IS(LinkedList_overlappingNoCycleLists(L1, L2), L3);
        }
        {
                ListNode *node, *L1, *L2, *L3;
                node = &(ListNode){4, 0};
                node = &(ListNode){6, node};
                L1 = &(ListNode){2, node};
                node = &(ListNode){5, 0};
                L2 = &(ListNode){1, node};
                UTILS_ASSERT_IS_NONE(LinkedList_overlappingNoCycleLists(L1, L2));
        }
}
