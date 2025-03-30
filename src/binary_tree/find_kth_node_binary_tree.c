#include "utils/asserts.h"

extern struct btree_node *binary_tree_find_kth_node_binary_tree(struct btree_node *root, int k);

void test_binary_tree_find_kth_node_binary_tree()
{
        bt_node_obj actual = {}, expected = {};
        /*
         * Node's value holds the number of children;
         *
         *           33(8)
         *          /     \
         *       25(4)     26(2)
         *      /   \     /   \
         *   20(2) 13(0) 2(0)  5(0)
         *   /   \
         * 1(0)  4(0)
         *
         */
        struct btree_node *node4 = &(struct btree_node){
                .value = 0,
                .left = 0,
                .right = 0,
        };
        struct btree_node *node2 = &(struct btree_node){
                .value = 0,
                .left = 0,
                .right = 0,
        };
        struct btree_node *node20 = &(struct btree_node){
                .value = 2,
                .left =
                        &(struct btree_node){
                                .value = 0,
                                .left = 0,
                                .right = 0,
                        },
                .right = node4,
        };
        struct btree_node *node25 = &(struct btree_node){
                .value = 4,
                .left = node20,
                .right =
                        &(struct btree_node){
                                .value = 0,
                                .left = 0,
                                .right = 0,
                        },
        };
        struct btree_node *tree = &(struct btree_node){
                .value = 8,
                .left = node25,
                .right =
                        &(struct btree_node){
                                .value = 2,
                                .left = node2,
                                .right =
                                        &(struct btree_node){
                                                .value = 0,
                                                .left = 0,
                                                .right = 0,
                                        },
                        },
        };

        actual.data = binary_tree_find_kth_node_binary_tree(node25, 3);
        expected.data = node4;
        ASSERT_IS(actual, expected);
        actual.data = binary_tree_find_kth_node_binary_tree(node25, 2);
        expected.data = node20;
        ASSERT_IS(actual, expected);
        actual.data = binary_tree_find_kth_node_binary_tree(tree, 7);
        expected.data = node2;
        ASSERT_IS(actual, expected);
}
