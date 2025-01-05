#include "list_node.h"
#include "utils.h"

// Declaration:
struct list_node *linked_list_mergeTwoSortedLists(struct list_node *L1, struct list_node *L2);

void test_linked_list_mergeTwoSortedLists()
{
        {
                struct list_node *node, *L1, *L2;
                node = &(struct list_node){4, 0};
                node = &(struct list_node){2, node};
                L1 = &(struct list_node){1, node};
                node = &(struct list_node){4, 0};
                node = &(struct list_node){3, node};
                L2 = &(struct list_node){1, node};
                node = linked_list_mergeTwoSortedLists(L1, L2);

                int expected[] = {1, 1, 2, 3, 4, 4};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L1, *L2;
                node = &(struct list_node){7, 0};
                node = &(struct list_node){5, node};
                L1 = &(struct list_node){2, node};
                node = &(struct list_node){11, 0};
                L2 = &(struct list_node){3, node};
                node = linked_list_mergeTwoSortedLists(L1, L2);

                int expected[] = {2, 3, 5, 7, 11};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L1, *L2;
                node = linked_list_mergeTwoSortedLists(0, 0);
                UTILS_ASSERT_IS_NONE(node);
        }
        {
                struct list_node *node, *L1, *L2;
                L2 = &(struct list_node){0, 0};
                node = linked_list_mergeTwoSortedLists(0, L2);

                int expected[] = {0};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
}
