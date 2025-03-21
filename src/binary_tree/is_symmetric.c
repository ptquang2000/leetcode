#include "btree_node.h"
#include "utils/asserts.h"

#include <stdbool.h>

extern bool binary_tree_is_symmetric(struct btree_node *root);

void test_binary_tree_is_symmetric()
{
        bt_node_obj actual = {}, expected = {};
        {
                int data[] = {1, 2, 2, 3, 4, 4, 3};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                ASSERT_TRUE(binary_tree_is_symmetric(tree));
                free_btree(tree);
        }
        {
                int data[] = {1, 2, 2, NONE, 3, NONE, 3};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                ASSERT_FALSE(binary_tree_is_symmetric(tree));
                free_btree(tree);
        }
}
