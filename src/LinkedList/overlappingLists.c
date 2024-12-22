#include "ListNode.h"
#include "utils.h"

// Declaration:
ListNode* LinkedList_overlappingLists(ListNode* L1, ListNode* L2);

void test_LinkedList_overlappingLists()
{
        // NOTE: None is cyclic
        {
                ListNode *node, *L1, *L2, *A;
                node = &(ListNode){0, 0};
                node = &(ListNode){0, node};
                A = &(ListNode){0, node};
                node = &(ListNode){0, A};
                L1 = &(ListNode){0, node};
                node = &(ListNode){0, A};
                L2 = &(ListNode){0, node};
                UTILS_ASSERT_IS(LinkedList_overlappingLists(L1, L2), A);
        }
        {
                ListNode *node, *L1, *L2, *A;
                node = &(ListNode){0, 0};
                node = &(ListNode){0, node};
                L1 = &(ListNode){0, node};
                node = &(ListNode){0, 0};
                node = &(ListNode){0, node};
                L2 = &(ListNode){0, node};
                UTILS_ASSERT_IS_NONE(LinkedList_overlappingLists(L1, L2));
        }

        // NOTE: Different cycles
        {
                ListNode *node, *L1, *L2, *A, *B;
                A = &(ListNode){0, 0};
                node = &(ListNode){0, A};
                node = &(ListNode){0, node};
                A->next = node;
                L1 = &(ListNode){0, A};
                B = &(ListNode){0, 0};
                node = &(ListNode){0, B};
                node = &(ListNode){0, node};
                B->next = node;
                L2 = &(ListNode){0, B};
                UTILS_ASSERT_IS_NONE(LinkedList_overlappingLists(L1, L2));
        }

        // NOTE: Only one is cyclic
        {
                ListNode *node, *L1, *L2, *A, *B;
                A = &(ListNode){0, 0};
                node = &(ListNode){0, A};
                node = &(ListNode){0, node};
                A->next = node;
                L1 = &(ListNode){0, A};
                B = &(ListNode){0, 0};
                node = &(ListNode){0, B};
                node = &(ListNode){0, node};
                B->next = node;
                L2 = &(ListNode){0, B};
                UTILS_ASSERT_IS_NONE(LinkedList_overlappingLists(L1, L2));
        }

        // NOTE: Merge at cycle node
        {
                ListNode *node, *L1, *L2, *A, *B;
                B = &(ListNode){0, 0};
                A = &(ListNode){0, B};
                node = &(ListNode){0, A};
                node = &(ListNode){0, node};
                B->next = node;
                node = &(ListNode){0, B};
                A->next = node;
                L1 = &(ListNode){0, node};
                L2 = A;

                void* expected[] = {A, B};
                UTILS_ASSERT_IN((void*)LinkedList_overlappingLists(L1, L2), expected,
                                sizeof(expected) / sizeof(*expected));
        }

        // NOTE: Merge before cycle
        {
                ListNode *node, *L1, *L2, *A, *B;
                B = &(ListNode){0, 0};
                node = &(ListNode){0, B};
                node = &(ListNode){0, node};
                B->next = node;
                A = &(ListNode){0, B};
                L1 = &(ListNode){0, A};
                L2 = &(ListNode){0, A};
                UTILS_ASSERT_IS(LinkedList_overlappingLists(L1, L2), A);
        }
}
