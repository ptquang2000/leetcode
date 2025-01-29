#include "list_node.h"
#include "utils/utils.h"

// Declaration:
struct list_node *linked_list_cyclicallyRightShiftList(struct list_node *L, int k);

void test_linked_list_cyclicallyRightShiftList()
{
        {
                struct list_node *node, *L;
                node = &(struct list_node){5, 0};
                node = &(struct list_node){4, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){1, node};
                node = linked_list_cyclicallyRightShiftList(L, 2);

                int expected[] = {4, 5, 1, 2, 3};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){5, 0};
                node = &(struct list_node){4, node};
                node = &(struct list_node){3, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){1, node};
                node = linked_list_cyclicallyRightShiftList(L, 12);

                int expected[] = {4, 5, 1, 2, 3};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){2, 0};
                node = &(struct list_node){1, node};
                L = &(struct list_node){0, node};
                node = linked_list_cyclicallyRightShiftList(L, 4);

                int expected[] = {2, 0, 1};
                int actual[sizeof(expected) / sizeof(*expected)] = {};
                TO_LIST(node, sizeof(expected) / sizeof(*expected), actual);
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, sizeof(expected) / sizeof(*expected));
        }
        {
                struct list_node *node, *L;
                L = 0;
                node = linked_list_cyclicallyRightShiftList(L, 4);
                UTILS_ASSERT_IS_NONE(node);
        }
}
