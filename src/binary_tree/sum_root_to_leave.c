#include "btree_node.h"
#include "utils/asserts.h"

extern int binary_tree_sum_root_to_leave(struct btree_node *root);

void test_binary_tree_sum_root_to_leave()
{
        int_obj actual = {}, expected = {};
        {
                int data[] = {1, 2, 3};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                actual.data = binary_tree_sum_root_to_leave(tree);
                expected.data = 25;
                ASSERT_EQUAL(actual, expected);
                free_btree(tree);
        }
        {
                int data[] = {4, 9, 0, 5, 1};
                struct btree_node *tree = btree(data, ARRAY_SIZE(data));
                actual.data = binary_tree_sum_root_to_leave(tree);
                expected.data = 1026;
                ASSERT_EQUAL(actual, expected);
                free_btree(tree);
        }
}
