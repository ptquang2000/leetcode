#include "list_node.h"
#include "utils/utils.h"

// Declaration:
struct list_node *linked_list_removeDuplicates(struct list_node *L);

void test_linked_list_removeDuplicates()
{
        {
                struct list_node *node, *L;
                node = &(struct list_node){2, 0};
                node = &(struct list_node){1, node};
                L = &(struct list_node){1, node};
                node = linked_list_removeDuplicates(L);

                int expected[] = {1, 2};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){3, 0};
                node = &(struct list_node){3, node};
                node = &(struct list_node){2, node};
                node = &(struct list_node){1, node};
                L = &(struct list_node){1, node};
                node = linked_list_removeDuplicates(L);

                int expected[] = {1, 2, 3};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){11, 0};
                node = &(struct list_node){11, node};
                node = &(struct list_node){7, node};
                node = &(struct list_node){5, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){2, node};
                node = linked_list_removeDuplicates(L);

                int expected[] = {2, 3, 5, 7, 11};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
}
