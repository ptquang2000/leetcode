#include "btree_node.h"
#include "utils/asserts.h"

extern struct btree_node *binary_tree_lowest_common_ancestor(struct btree_node *root, struct btree_node *node0,
                                                             struct btree_node *node1);

void test_binary_tree_lowest_common_ancestor()
{
        bt_node_obj actual = {}, expected = {};
        {
                struct btree_node *node4 = &(struct btree_node){
                        .value = 4,
                        .left = 0,
                        .right = 0,
                };
                struct btree_node *node1 = &(struct btree_node){
                        .value = 1,
                        .left =
                                &(struct btree_node){
                                        .value = 0,
                                        .left = 0,
                                        .right = 0,
                                },
                        .right =
                                &(struct btree_node){
                                        .value = 8,
                                        .left = 0,
                                        .right = 0,
                                },
                };
                struct btree_node *node5 = &(struct btree_node){
                        .value = 5,
                        .left =
                                &(struct btree_node){
                                        .value = 6,
                                        .left = 0,
                                        .right = 0,
                                },
                        .right =
                                &(struct btree_node){
                                        .value = 2,
                                        .left =
                                                &(struct btree_node){
                                                        .value = 7,
                                                        .left = 0,
                                                        .right = 0,
                                                },
                                        .right = node4,
                                },
                };
                struct btree_node *tree = &(struct btree_node){
                        .value = 0,
                        .left = node5,
                        .right = node1,
                };
                actual.data = binary_tree_lowest_common_ancestor(tree, node5, node1);
                expected.data = tree;
                ASSERT_IS(actual, expected);
                actual.data = binary_tree_lowest_common_ancestor(tree, node5, node4);
                expected.data = node5;
                ASSERT_IS(actual, expected);
        }
        {
                struct btree_node *node2 = &(struct btree_node){
                        .value = 2,
                        .left = 0,
                        .right = 0,
                };
                struct btree_node *tree = &(struct btree_node){
                        .value = 1,
                        .left = node2,
                        .right = 0,
                };
                expected.data = tree;
                actual.data = binary_tree_lowest_common_ancestor(tree, tree, node2);
                ASSERT_IS(actual, expected);
                actual.data = binary_tree_lowest_common_ancestor(tree, node2, tree);
                ASSERT_IS(actual, expected);
        }
        {
                struct btree_node *node2 = &(struct btree_node){
                        .value = 2,
                        .left = 0,
                        .right = 0,
                };
                struct btree_node *node3 = &(struct btree_node){
                        .value = 3,
                        .left = 0,
                        .right = 0,
                };
                struct btree_node *tree = &(struct btree_node){
                        .value = 1,
                        .left = node2,
                        .right = node3,
                };
                expected.data = tree;
                actual.data = binary_tree_lowest_common_ancestor(tree, node3, node2);
                ASSERT_IS(actual, expected);
        }
}
