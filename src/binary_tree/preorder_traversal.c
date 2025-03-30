#include "btree_node.h"
#include "utils/asserts.h"

extern int *binary_tree_preorder_traversal(struct btree_node *root, int *o_size);

void test_binary_tree_preorder_traversal()
{
        int_array actual = {}, expected = {};
        {
                int data[] = {1, NONE, 2, 3};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                expected = (int_array){(int[]){1, 2, 3}, 3};
                actual.data = binary_tree_preorder_traversal(tree, &actual.len);
                ASSERT_EQUAL(actual, expected);
                free_btree(tree);
        }
        {
                int data[] = {};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                expected = (int_array){(int[]){}, 0};
                actual.data = binary_tree_preorder_traversal(tree, &actual.len);
                ASSERT_EQUAL(actual, expected);
                free_btree(tree);
        }
        {
                int data[] = {1};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                expected = (int_array){(int[]){1}, 1};
                actual.data = binary_tree_preorder_traversal(tree, &actual.len);
                ASSERT_EQUAL(actual, expected);
                free_btree(tree);
        }
        {
                int data[] = {1, 2, 3, 4, 5, NONE, 8, NONE, NONE, 6, 7, 9};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                expected = (int_array){(int[]){1, 2, 4, 5, 6, 7, 3, 8, 9}, 9};
                actual.data = binary_tree_preorder_traversal(tree, &actual.len);
                ASSERT_EQUAL(actual, expected);
                free_btree(tree);
        }
}
