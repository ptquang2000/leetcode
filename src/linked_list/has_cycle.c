#include "list_node.h"
#include "utils.h"

// Declaration:
struct list_node *linked_list_hasCycle(struct list_node *L);

void test_linked_list_hasCycle()
{
        {
                struct list_node *node, *L, *end, *expected;
                end = &(struct list_node){-4, 0};
                node = &(struct list_node){0, end};
                expected = &(struct list_node){2, node};
                L = &(struct list_node){3, expected};
                end->next = expected;
                node = linked_list_hasCycle(L);
                UTILS_ASSERT_IS(node, expected);
        }
        {
                struct list_node *node, *L, *end, *expected;
                end = &(struct list_node){2, 0};
                expected = &(struct list_node){1, end};
                L = expected;
                end->next = expected;
                node = linked_list_hasCycle(L);
                UTILS_ASSERT_IS(node, expected);
        }
        {
                struct list_node *node, *L, *end, *expected;
                end = &(struct list_node){2, 0};
                UTILS_ASSERT_IS_NONE(linked_list_hasCycle(end));
        }
}
