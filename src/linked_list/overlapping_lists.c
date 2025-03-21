#include "list_node.h"
#include "utils/asserts.h"

extern struct list_node *linked_list_overlappingLists(struct list_node *L1, struct list_node *L2);

void test_linked_list_overlappingLists()
{
        ll_node_obj actual = {}, expected = {};
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
                expected.data = A;
                actual.data = linked_list_overlappingLists(L1, L2);
                ASSERT_IS(actual, expected);
        }
        {
                struct list_node *node, *L1, *L2, *A;
                node = &(struct list_node){0, 0};
                node = &(struct list_node){0, node};
                L1 = &(struct list_node){0, node};
                node = &(struct list_node){0, 0};
                node = &(struct list_node){0, node};
                L2 = &(struct list_node){0, node};
                actual.data = linked_list_overlappingLists(L1, L2);
                ASSERT_IS_NULL(actual);
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
                actual.data = linked_list_overlappingLists(L1, L2);
                ASSERT_IS_NULL(actual);
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
                actual.data = linked_list_overlappingLists(L1, L2);
                ASSERT_IS_NULL(actual);
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

                ll_node_array c = {(struct list_node *[]){A, B}, 2};
                actual.data = linked_list_overlappingLists(L1, L2);
                ASSERT_IN(actual, c);
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
                expected.data = A;
                actual.data = linked_list_overlappingLists(L1, L2);
                ASSERT_IS(actual, expected);
        }
}
