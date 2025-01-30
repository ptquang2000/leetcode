#include "list_node.h"
#include "utils/utils.h"

extern struct list_node *linked_list_evenOddMerge(struct list_node *L);

void test_linked_list_evenOddMerge()
{
        {
                struct list_node *node, *L;
                node = &(struct list_node){5, 0};
                node = &(struct list_node){4, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){1, node};
                node = linked_list_evenOddMerge(L);

                int expected[] = {1, 3, 5, 2, 4};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){7, 0};
                node = &(struct list_node){4, node};
                node = &(struct list_node){6, node};
                node = &(struct list_node){5, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){1, node};
                L = &(struct list_node){2, node};
                node = linked_list_evenOddMerge(L);

                int expected[] = {2, 3, 6, 7, 1, 5, 4};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L;
                node = linked_list_evenOddMerge(0);
                UTILS_ASSERT_IS_NONE(node);
        }
}
