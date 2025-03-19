#include "btree_node.h"
#include "utils/asserts.h"

extern bool binary_tree_has_path_sum(struct btree_node *root, int remaining_weight);

void test_binary_tree_has_path_sum()
{
        {
                int data[] = {5, 4, 8, 11, NONE, 13, 4, 7, 2, NONE, NONE, NONE, 1};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                ASSERT_TRUE(binary_tree_has_path_sum(tree, 22));
                free_btree(tree);
        }
        {
                int data[] = {1, 2, 3};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                ASSERT_FALSE(binary_tree_has_path_sum(tree, 5));
                free_btree(tree);
        }
        {
                int data[] = {};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                ASSERT_FALSE(binary_tree_has_path_sum(tree, 0));
                free_btree(tree);
        }
}
