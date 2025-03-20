#include "list_node.h"
#include "utils/asserts.h"

extern struct list_node *linked_list_overlappingNoCycleLists(struct list_node *L1, struct list_node *L2);

void test_linked_list_overlappingNoCycleLists()
{
        ll_node_obj actual, expected;
        {
                struct list_node *node, *L1, *L2, *L3;
                node = &(struct list_node){5, 0};
                node = &(struct list_node){4, node};
                expected.data = L3 = &(struct list_node){8, node};
                node = &(struct list_node){1, L3};
                L1 = &(struct list_node){4, node};
                node = &(struct list_node){1, L3};
                node = &(struct list_node){6, node};
                L2 = &(struct list_node){5, node};
                actual.data = linked_list_overlappingNoCycleLists(L1, L2);
                ASSERT_IS(actual, expected);
        }
        {
                struct list_node *node, *L1, *L2, *L3;
                node = &(struct list_node){4, 0};
                expected.data = L3 = &(struct list_node){2, node};
                node = &(struct list_node){1, L3};
                node = &(struct list_node){9, node};
                L1 = &(struct list_node){1, node};
                L2 = &(struct list_node){3, L3};
                actual.data = linked_list_overlappingNoCycleLists(L1, L2);
                ASSERT_IS(actual, expected);
        }
        {
                struct list_node *node, *L1, *L2, *L3;
                node = &(struct list_node){4, 0};
                node = &(struct list_node){6, node};
                L1 = &(struct list_node){2, node};
                node = &(struct list_node){5, 0};
                L2 = &(struct list_node){1, node};
                actual.data = linked_list_overlappingNoCycleLists(L1, L2);
                ASSERT_IS_NULL(actual);
        }
}
