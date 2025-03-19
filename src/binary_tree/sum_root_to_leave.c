#include "btree_node.h"
#include "utils/asserts.h"

extern int binary_tree_sum_root_to_leave(struct btree_node *root);

void test_binary_tree_sum_root_to_leave()
{
        {
                int data[] = {1, 2, 3};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                ASSERT_EQUAL(binary_tree_sum_root_to_leave(tree), 25);
                free_btree(tree);
        }
        {
                int data[] = {4, 9, 0, 5, 1};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                ASSERT_EQUAL(binary_tree_sum_root_to_leave(tree), 1026);
                free_btree(tree);
        }
}
