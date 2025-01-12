#include "btree_node.h"
#include "utils.h"

void test_btree_node()
{
        /*
         *   3
         *  / \
         * 9   20
         *    /  \
         *   15   7
         */
        struct btree_node *tree1 = &(struct btree_node){
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
        UTILS_LOG("tree1={}", UTYPE(tree1));

        /*
         *       1
         *      / \
         *     2   2
         *    / \
         *   3   3
         *  / \
         * 4   4
         */
        struct btree_node *tree2 = &(struct btree_node){
                .value = 1,
                .left =
                        &(struct btree_node){
                                .value = 2,
                                .left =
                                        &(struct btree_node){
                                                .value = 3,
                                                .left =
                                                        &(struct btree_node){
                                                                .value = 4,
                                                                .left = 0,
                                                                .right = 0,
                                                        },
                                                .right =
                                                        &(struct btree_node){
                                                                .value = 4,
                                                                .left = 0,
                                                                .right = 0,
                                                        },
                                        },
                                .right =
                                        &(struct btree_node){
                                                .value = 3,
                                                .left = 0,
                                                .right = 0,
                                        },
                        },
                .right =
                        &(struct btree_node){
                                .value = 2,
                                .left = 0,
                                .right = 0,
                        },
        };
        UTILS_LOG("tree2={}", UTYPE(tree2));

        /*
         *       5
         *      / \
         *     4   8
         *    /   / \
         *   11  13  4
         *  / \
         * 7   2
         */
        struct btree_node *tree3 = &(struct btree_node){
                .value = 5,
                .left =
                        &(struct btree_node){
                                .value = 4,
                                .left =
                                        &(struct btree_node){
                                                .value = 11,
                                                .left =
                                                        &(struct btree_node){
                                                                .value = 7,
                                                                .left = 0,
                                                                .right = 0,
                                                        },
                                                .right =
                                                        &(struct btree_node){
                                                                .value = 2,
                                                                .left = 0,
                                                                .right = 0,
                                                        },
                                        },
                                .right = 0,
                        },
                .right =
                        &(struct btree_node){
                                .value = 8,
                                .left =
                                        &(struct btree_node){
                                                .value = 13,
                                                .left = 0,
                                                .right = 0,
                                        },
                                .right =
                                        &(struct btree_node){
                                                .value = 4,
                                                .left = 0,
                                                .right = 0,
                                        },
                        },
        };
        UTILS_LOG("tree3={}", UTYPE(tree3));

        /*
         *   1
         *  / \
         * 2   3
         */
        struct btree_node *tree4 = &(struct btree_node){
                .value = 1,
                .left =
                        &(struct btree_node){
                                .value = 2,
                                .left = 0,
                                .right = 0,
                        },
                .right =
                        &(struct btree_node){
                                .value = 3,
                                .left = 0,
                                .right = 0,
                        },
        };
        UTILS_LOG("tree4={}", UTYPE(tree4));

        /*
         *     1
         *    / \
         *   2   5
         *  / \   \
         * 3   4   6
         */
        struct btree_node *tree5 = &(struct btree_node){
                .value = 1,
                .left =
                        &(struct btree_node){
                                .value = 2,
                                .left =
                                        &(struct btree_node){
                                                .value = 3,
                                                .left = 0,
                                                .right = 0,
                                        },
                                .right =
                                        &(struct btree_node){
                                                .value = 4,
                                                .left = 0,
                                                .right = 0,
                                        },
                        },
                .right =
                        &(struct btree_node){
                                .value = 5,
                                .left = 0,
                                .right =
                                        &(struct btree_node){
                                                .value = 6,
                                                .left = 0,
                                                .right = 0,
                                        },
                        },
        };
        UTILS_LOG("tree5={}", UTYPE(tree5));

        /*
         * 1
         *  \
         *   2
         *    \
         *     3
         *      \
         *       4
         *        \
         *         5
         */
        struct btree_node *tree6 = &(struct btree_node){
                .value = 1,
                .left = 0,
                .right =
                        &(struct btree_node){
                                .value = 2,
                                .left = 0,
                                .right =
                                        &(struct btree_node){
                                                .value = 3,
                                                .left = 0,
                                                .right =
                                                        &(struct btree_node){
                                                                .value = 4,
                                                                .left = 0,
                                                                .right =
                                                                        &(struct btree_node){
                                                                                .value = 5,
                                                                                .left = 0,
                                                                                .right = 0,
                                                                        },
                                                        },
                                        },
                        },
        };
        UTILS_LOG("tree6={}", UTYPE(tree6));
}
