#include "btree_node.h"
#include "utils.h"

// Declaration:
struct btree_node *binary_tree_find_kth_node_binary_tree(struct btree_node *root, int k);

void test_binary_tree_find_kth_node_binary_tree()
{
        /*
         *     25(4)
         *    /     \
         *   20(2)   13(0)
         *  /    \
         * 1(0)   4(0)
         */
        struct btree_node *node4 = &(struct btree_node){
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
        struct btree_node *tree = &(struct btree_node){
                .value = 4,
                .left = node20,
                .right =
                        &(struct btree_node){
                                .value = 0,
                                .left = 0,
                                .right = 0,
                        },
        };

        UTILS_ASSERT_IS(binary_tree_find_kth_node_binary_tree(tree, 3), node4);
        UTILS_ASSERT_IS(binary_tree_find_kth_node_binary_tree(tree, 2), node20);
}
