#include "list_node.h"
#include "utils/asserts.h"

extern struct list_node *linked_list_overlappingLists(struct list_node *L1, struct list_node *L2);

void test_linked_list_overlappingLists()
{
        // NOTE: None is cyclic
        {
                struct list_node *node, *L1, *L2, *A;
                node = &(struct list_node){0, 0};
                node = &(struct list_node){0, node};
                A = &(struct list_node){0, node};
                node = &(struct list_node){0, A};
                L1 = &(struct list_node){0, node};
                node = &(struct list_node){0, A};
                L2 = &(struct list_node){0, node};
                UTILS_ASSERT_IS(linked_list_overlappingLists(L1, L2), A);
        }
        {
                struct list_node *node, *L1, *L2, *A;
                node = &(struct list_node){0, 0};
                node = &(struct list_node){0, node};
                L1 = &(struct list_node){0, node};
                node = &(struct list_node){0, 0};
                node = &(struct list_node){0, node};
                L2 = &(struct list_node){0, node};
                UTILS_ASSERT_IS_NONE(linked_list_overlappingLists(L1, L2));
        }

        // NOTE: Different cycles
        {
                struct list_node *node, *L1, *L2, *A, *B;
                A = &(struct list_node){0, 0};
                node = &(struct list_node){0, A};
                node = &(struct list_node){0, node};
                A->next = node;
                L1 = &(struct list_node){0, A};
                B = &(struct list_node){0, 0};
                node = &(struct list_node){0, B};
                node = &(struct list_node){0, node};
                B->next = node;
                L2 = &(struct list_node){0, B};
                UTILS_ASSERT_IS_NONE(linked_list_overlappingLists(L1, L2));
        }

        // NOTE: Only one is cyclic
        {
                struct list_node *node, *L1, *L2, *A, *B;
                A = &(struct list_node){0, 0};
                node = &(struct list_node){0, A};
                node = &(struct list_node){0, node};
                A->next = node;
                L1 = &(struct list_node){0, A};
                B = &(struct list_node){0, 0};
                node = &(struct list_node){0, B};
                node = &(struct list_node){0, node};
                B->next = node;
                L2 = &(struct list_node){0, B};
                UTILS_ASSERT_IS_NONE(linked_list_overlappingLists(L1, L2));
        }

        // NOTE: Merge at cycle node
        {
                struct list_node *node, *L1, *L2, *A, *B;
                B = &(struct list_node){0, 0};
                A = &(struct list_node){0, B};
                node = &(struct list_node){0, A};
                node = &(struct list_node){0, node};
                B->next = node;
                node = &(struct list_node){0, B};
                A->next = node;
                L1 = &(struct list_node){0, node};
                L2 = A;

                void* expected[] = {A, B};
                UTILS_ASSERT_IN((void*)linked_list_overlappingLists(L1, L2), expected,
                                sizeof(expected) / sizeof(*expected));
        }

        // NOTE: Merge before cycle
        {
                struct list_node *node, *L1, *L2, *A, *B;
                B = &(struct list_node){0, 0};
                node = &(struct list_node){0, B};
                node = &(struct list_node){0, node};
                B->next = node;
                A = &(struct list_node){0, B};
                L1 = &(struct list_node){0, A};
                L2 = &(struct list_node){0, A};
                UTILS_ASSERT_IS(linked_list_overlappingLists(L1, L2), A);
        }
}
