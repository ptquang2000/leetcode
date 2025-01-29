#include "btree_node.h"
#include "utils/utils.h"

// Declaration:
struct btree_node **binary_tree_create_list_of_leaves(struct btree_node *root, int *o_size);

void test_binary_tree_create_list_of_leaves()
{
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
                struct btree_node *expected[] = {&l4, &l5, &l3};
                int actual_size;
                struct btree_node **actual = binary_tree_create_list_of_leaves(tree, &actual_size);
                UTILS_ASSERT_EQUAL(actual_size, ARRAY_SIZE(expected));
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, ARRAY_SIZE(expected));
        }
        {
                struct btree_node *tree = &(struct btree_node){
                        .value = 1,
                        .left = 0,
                        .right = 0,
                };
                struct btree_node *expected[] = {tree};
                int actual_size;
                struct btree_node **actual = binary_tree_create_list_of_leaves(tree, &actual_size);
                UTILS_ASSERT_EQUAL(actual_size, ARRAY_SIZE(expected));
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, ARRAY_SIZE(expected));
        }
}
