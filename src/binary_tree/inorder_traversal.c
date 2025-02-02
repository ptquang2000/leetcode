#include "btree_node.h"
#include "utils/utils.h"

extern int *binary_tree_inorder_traversal(struct btree_node *root, int *o_size);

void test_binary_tree_inorder_traversal()
{
        {
                int data[] = {1, NONE, 2, 3};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                int expected[] = {1, 3, 2};
                int actual_size;
                int *actual = binary_tree_inorder_traversal(tree, &actual_size);
                UTILS_ASSERT_EQUAL(actual_size, ARRAY_SIZE(expected));
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, actual_size);
                free_btree(tree);
        }
        {
                int data[] = {};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                int expected[] = {};
                int actual_size;
                int *actual = binary_tree_inorder_traversal(tree, &actual_size);
                UTILS_ASSERT_EQUAL(actual_size, ARRAY_SIZE(expected));
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, actual_size);
                free_btree(tree);
        }
        {
                int data[] = {1};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                int expected[] = {1};
                int actual_size;
                int *actual = binary_tree_inorder_traversal(tree, &actual_size);
                UTILS_ASSERT_EQUAL(actual_size, ARRAY_SIZE(expected));
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, actual_size);
                free_btree(tree);
        }
}
