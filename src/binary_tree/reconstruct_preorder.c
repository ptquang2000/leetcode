#include "btree_node.h"
#include "utils/asserts.h"

extern struct btree_node *binary_tree_reconstruct_preorder(int size, int preorder[size]);

void test_binary_tree_reconstruct_preorder()
{
        bt_node_obj actual = {}, expected = {};
        {
                int preorder[] = {'H', 'B', 'F', 0, 0, 'E', 'A', 0, 0, 0, 'C', 0, 'D', 0, 'G', 'I', 0, 0, 0};
                expected.data = &(struct btree_node){
                        .value = 'H',
                        .left =
                                &(struct btree_node){
                                        .value = 'B',
                                        .left =
                                                &(struct btree_node){
                                                        .value = 'F',
                                                        .left = 0,
                                                        .right = 0,
                                                },
                                        .right =
                                                &(struct btree_node){
                                                        .value = 'E',
                                                        .left =
                                                                &(struct btree_node){
                                                                        .value = 'A',
                                                                        .left = 0,
                                                                        .right = 0,
                                                                },
                                                        .right = 0,
                                                },
                                },

                        .right =
                                &(struct btree_node){
                                        .value = 'C',
                                        .left = 0,
                                        .right =
                                                &(struct btree_node){
                                                        .value = 'D',
                                                        .left = 0,
                                                        .right =
                                                                &(struct btree_node){
                                                                        .value = 'G',
                                                                        .left =
                                                                                &(struct btree_node){
                                                                                        .value = 'I',
                                                                                        .left = 0,
                                                                                        .right = 0,
                                                                                },
                                                                        .right = 0,
                                                                },
                                                },
                                },
                };
                actual.data = binary_tree_reconstruct_preorder(ARRAY_SIZE(preorder), preorder);
                ASSERT_EQUAL(actual, expected);
                free_btree(actual.data);
        }
        {
                int preorder[] = {8, 5, 1, 0, 0, 7, 0, 0, 10, 0, 12, 0, 0};
                expected.data = &(struct btree_node){
                        .value = 8,
                        .left =
                                &(struct btree_node){
                                        .value = 5,
                                        .left =
                                                &(struct btree_node){
                                                        .value = 1,
                                                        .left = 0,
                                                        .right = 0,
                                                },
                                        .right =
                                                &(struct btree_node){
                                                        .value = 7,
                                                        .left = 0,
                                                        .right = 0,
                                                },
                                },

                        .right =
                                &(struct btree_node){
                                        .value = 10,
                                        .left = 0,
                                        .right =
                                                &(struct btree_node){
                                                        .value = 12,
                                                        .left = 0,
                                                        .right = 0,
                                                },
                                },
                };
                actual.data = binary_tree_reconstruct_preorder(ARRAY_SIZE(preorder), preorder);
                ASSERT_EQUAL(actual, expected);
                free_btree(actual.data);
        }
        {
                int preorder[] = {1, 3, 0, 0, 0};
                expected.data = &(struct btree_node){
                        .value = 1,
                        .left =
                                &(struct btree_node){
                                        .value = 3,
                                        .left = 0,
                                        .right = 0,
                                },

                        .right = 0,
                };
                actual.data = binary_tree_reconstruct_preorder(ARRAY_SIZE(preorder), preorder);
                ASSERT_EQUAL(actual, expected);
                free_btree(actual.data);
        }
}
