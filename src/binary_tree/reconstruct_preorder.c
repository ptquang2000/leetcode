#include "btree_node.h"
#include "utils/utils.h"

// Declaration:
struct btree_node *binary_tree_reconstruct_preorder(int size, int preorder[size]);

void test_binary_tree_reconstruct_preorder()
{
        {
                int preorder[] = {'H', 'B',  'F', NONE, NONE, 'E', 'A',  NONE, NONE, NONE,
                                  'C', NONE, 'D', NONE, 'G',  'I', NONE, NONE, NONE};
                struct btree_node *expected = &(struct btree_node){
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
                struct btree_node *actual = binary_tree_reconstruct_preorder(ARRAY_SIZE(preorder), preorder);
                UTILS_ASSERT_EQUAL(actual, expected);
                free_btree(actual);
        }
        {
                int preorder[] = {8, 5, 1, NONE, NONE, 7, NONE, NONE, 10, NONE, 12, NONE, NONE};
                struct btree_node *expected = &(struct btree_node){
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
                struct btree_node *actual = binary_tree_reconstruct_preorder(ARRAY_SIZE(preorder), preorder);
                UTILS_ASSERT_EQUAL(actual, expected);
                free_btree(actual);
        }
        {
                int preorder[] = {1, 3, NONE, NONE, NONE};
                struct btree_node *expected = &(struct btree_node){
                        .value = 1,
                        .left =
                                &(struct btree_node){
                                        .value = 3,
                                        .left = 0,
                                        .right = 0,
                                },

                        .right = 0,
                };
                struct btree_node *actual = binary_tree_reconstruct_preorder(ARRAY_SIZE(preorder), preorder);
                UTILS_ASSERT_EQUAL(actual, expected);
                free_btree(actual);
        }
}
