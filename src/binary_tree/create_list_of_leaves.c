#include "btree_node.h"
#include "utils/asserts.h"

extern struct btree_node **binary_tree_create_list_of_leaves(struct btree_node *root, int *o_size);

void test_binary_tree_create_list_of_leaves()
{
        bt_node_array actual = {}, expected = {};
        {
                struct btree_node l3 = {
                        .value = 3,
                        .left = 0,
                        .right = 0,
                };
                struct btree_node l5 = {
                        .value = 5,
                        .left = 0,
                        .right = 0,
                };
                struct btree_node l4 = {
                        .value = 4,
                        .left = 0,
                        .right = 0,
                };
                struct btree_node *tree = &(struct btree_node){
                        .value = 1,
                        .left =
                                &(struct btree_node){
                                        .value = 2,
                                        .left = &l4,
                                        .right = &l5,
                                },
                        .right = &l3,
                };
                expected = (bt_node_array){(struct btree_node *[]){&l4, &l5, &l3}, 3};
                actual.data = binary_tree_create_list_of_leaves(tree, &actual.len);
                ASSERT_EQUAL(actual, expected);
        }
        {
                struct btree_node *tree = &(struct btree_node){
                        .value = 1,
                        .left = 0,
                        .right = 0,
                };
                expected = (bt_node_array){(struct btree_node *[]){tree}, 1};
                actual.data = binary_tree_create_list_of_leaves(tree, &actual.len);
                ASSERT_EQUAL(actual, expected);
        }
}
