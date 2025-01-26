#include "list_node.h"
#include "utils.h"

// Declaration:
struct list_node *linked_list_addTwoNumbers(struct list_node *L1, struct list_node *L2);

void test_linked_list_addTwoNumbers()
{
        {
                struct list_node *node, *L1, *L2;
                node = &(struct list_node){4, 0};
                node = &(struct list_node){1, node};
                L1 = &(struct list_node){3, node};
                node = &(struct list_node){9, 0};
                node = &(struct list_node){0, node};
                L2 = &(struct list_node){7, node};
                node = linked_list_addTwoNumbers(L1, L2);

                int expected[] = {0, 2, 3, 1};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
                FREE_LIST(node);
        }
        {
                struct list_node *node, *L1, *L2;
                node = &(struct list_node){3, 0};
                node = &(struct list_node){4, node};
                L1 = &(struct list_node){2, node};
                node = &(struct list_node){4, 0};
                node = &(struct list_node){6, node};
                L2 = &(struct list_node){5, node};
                node = linked_list_addTwoNumbers(L1, L2);

                int expected[] = {7, 0, 8};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L1, *L2;
                L1 = &(struct list_node){0, 0};
                L2 = &(struct list_node){0, 0};
                node = linked_list_addTwoNumbers(L1, L2);

                int expected[] = {0};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L1, *L2;
                node = &(struct list_node){9, 0};
                node = &(struct list_node){9, node};
                node = &(struct list_node){9, node};
                node = &(struct list_node){9, node};
                node = &(struct list_node){9, node};
                node = &(struct list_node){9, node};
                L1 = &(struct list_node){9, node};
                node = &(struct list_node){9, 0};
                node = &(struct list_node){9, node};
                node = &(struct list_node){9, node};
                L2 = &(struct list_node){9, node};
                node = linked_list_addTwoNumbers(L1, L2);

                int expected[] = {8, 9, 9, 9, 0, 0, 0, 1};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
                FREE_LIST(node);
        }
}
