#include "list_node.h"
#include "utils.h"

// Declaration:
struct list_node *linked_list_reverseSublist(struct list_node *L, int start, int finish);

void test_linked_list_reverseSublist()
{
        {
                struct list_node *node, *L;
                node = &(struct list_node){5, 0};
                node = &(struct list_node){4, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){1, node};
                node = linked_list_reverseSublist(L, 2, 4);

                int expected[] = {1, 4, 3, 2, 5};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){2, 0};
                node = &(struct list_node){7, node};
                node = &(struct list_node){5, node};
                node = &(struct list_node){3, node};
                L = &(struct list_node){11, node};
                node = linked_list_reverseSublist(L, 2, 4);

                int expected[] = {11, 7, 5, 3, 2};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L;
                L = &(struct list_node){5, 0};
                node = linked_list_reverseSublist(L, 1, 1);

                int expected[] = {5};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
}
