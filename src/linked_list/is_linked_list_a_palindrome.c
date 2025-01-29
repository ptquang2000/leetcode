#include "list_node.h"
#include "utils/utils.h"

#include <stdbool.h>

// Declaration:
bool linked_list_isLinkedListAPalindrome(struct list_node *L);

void test_linked_list_isLinkedListAPalindrome()
{
        {
                struct list_node *node, *L;
                node = &(struct list_node){1, 0};
                node = &(struct list_node){2, node};
                node = &(struct list_node){2, node};
                L = &(struct list_node){1, node};
                UTILS_ASSERT_TRUE(linked_list_isLinkedListAPalindrome(L));
        }
        {
                struct list_node *node, *L;
                node = &(struct list_node){1, 0};
                L = &(struct list_node){2, node};
                UTILS_ASSERT_FALSE(linked_list_isLinkedListAPalindrome(L));
        }
}
