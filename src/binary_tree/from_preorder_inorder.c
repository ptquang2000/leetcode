#include "btree_node.h"
#include "utils.h"

// Declaration:
struct btree_node *binary_tree_from_preorder_inorder(int preorder_size, int preorder[preorder_size], int inorder_size, int inorder[inorder_size]);

void test_binary_tree_from_preorder_inorder()
{
        {
                int preorder[] = {3, 9, 20, 15, 7};
                int inorder[] = {9, 3, 15, 20, 7};
                struct btree_node *expected = &(struct btree_node){
                        .value = 3,
                        .left =
                                &(struct btree_node){
                                        .value = 9,
                                        .left = 0,
                                        .right = 0,
                                },

                        .right =
                                &(struct btree_node){
                                        .value = 20,
                                        .left =
                                                &(struct btree_node){
                                                        .value = 15,
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
                };
                struct btree_node *actual =
                        binary_tree_from_preorder_inorder(ARRAY_SIZE(preorder), preorder, ARRAY_SIZE(inorder), inorder);
                UTILS_ASSERT_EQUAL(actual, expected);
                free_btree(actual);
        }
        {
                int preorder[] = {-1};
                int inorder[] = {-1};
                struct btree_node *expected = &(struct btree_node){
                        .value = -1,
                        .left = 0,
                        .right = 0,
                };
                struct btree_node *actual =
                        binary_tree_from_preorder_inorder(ARRAY_SIZE(preorder), preorder, ARRAY_SIZE(inorder), inorder);
                UTILS_ASSERT_EQUAL(actual, expected);
                free_btree(actual);
        }
}
