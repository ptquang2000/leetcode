#include "list_node.h"
#include "utils.h"

// Declaration:
struct list_node *linked_list_overlappingNoCycleLists(struct list_node *L1, struct list_node *L2);

void test_linked_list_overlappingNoCycleLists()
{
        {
                struct list_node *node, *L1, *L2, *L3;
                node = &(struct list_node){5, 0};
                node = &(struct list_node){4, node};
                L3 = &(struct list_node){8, node};
                node = &(struct list_node){1, L3};
                L1 = &(struct list_node){4, node};
                node = &(struct list_node){1, L3};
                node = &(struct list_node){6, node};
                L2 = &(struct list_node){5, node};
                UTILS_ASSERT_IS(linked_list_overlappingNoCycleLists(L1, L2), L3);
        }
        {
                struct list_node *node, *L1, *L2, *L3;
                node = &(struct list_node){4, 0};
                L3 = &(struct list_node){2, node};
                node = &(struct list_node){1, L3};
                node = &(struct list_node){9, node};
                L1 = &(struct list_node){1, node};
                L2 = &(struct list_node){3, L3};
                UTILS_ASSERT_IS(linked_list_overlappingNoCycleLists(L1, L2), L3);
        }
        {
                struct list_node *node, *L1, *L2, *L3;
                node = &(struct list_node){4, 0};
                node = &(struct list_node){6, node};
                L1 = &(struct list_node){2, node};
                node = &(struct list_node){5, 0};
                L2 = &(struct list_node){1, node};
                UTILS_ASSERT_IS_NONE(linked_list_overlappingNoCycleLists(L1, L2));
        }
}
