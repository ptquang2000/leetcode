#include "list_node.h"
#include "utils/utils.h"

// Declaration:
struct list_node *linked_list_removeKthLast(struct list_node *L, int k);

void test_linked_list_removeKthLast()
{
        {
                struct list_node *node, *L;
                node = &(struct list_node){5, 0};
                node = &(struct list_node){4, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){1, node};
                node = linked_list_removeKthLast(L, 2);

                int expected[] = {1, 2, 3, 5};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L;
                L = &(struct list_node){1, 0};
                node = linked_list_removeKthLast(L, 1);

                int expected[] = {};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){2, 0};
                L = &(struct list_node){1, node};
                node = linked_list_removeKthLast(L, 1);

                int expected[] = {1};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
}
