#include "btree_node.h"
#include "utils/asserts.h"

#include <stdbool.h>

extern bool binary_tree_is_balanced_binary_tree(struct btree_node *root);

void test_binary_tree_is_balanced_binary_tree()
{
        {
                int data[] = {3, 9, 20, NONE, NONE, 15, 7};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                ASSERT_TRUE(binary_tree_is_balanced_binary_tree(tree));
                free_btree(tree);
        }
        {
                int data[] = {1, 2, 2, 3, 3, NONE, NONE, 4, 4};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                ASSERT_FALSE(binary_tree_is_balanced_binary_tree(tree));
                free_btree(tree);
        }
        {
                int data[] = {};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                ASSERT_TRUE(binary_tree_is_balanced_binary_tree(tree));
                free_btree(tree);
        }
}
