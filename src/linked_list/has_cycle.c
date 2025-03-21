#include "list_node.h"
#include "utils/asserts.h"

extern struct list_node *linked_list_hasCycle(struct list_node *L);

void test_linked_list_hasCycle()
{
        ll_node_obj actual;
        ll_node_obj expected;
        {
                struct list_node *node, *L, *end;
                end = &(struct list_node){-4, 0};
                node = &(struct list_node){0, end};
                expected.data = &(struct list_node){2, node};
                L = &(struct list_node){3, expected.data};
                end->next = expected.data;
                actual.data = linked_list_hasCycle(L);
                ASSERT_IS(actual, expected);
        }
        {
                struct list_node *node, *L, *end;
                end = &(struct list_node){2, 0};
                expected.data = &(struct list_node){1, end};
                L = expected.data;
                end->next = expected.data;
                actual.data = linked_list_hasCycle(L);
                ASSERT_IS(actual, expected);
        }
        {
                struct list_node *node, *L, *end;
                end = &(struct list_node){2, 0};
                actual.data = linked_list_hasCycle(end);
                ASSERT_IS_NULL(actual);
        }
}
