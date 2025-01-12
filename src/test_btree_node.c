#include "btree_node.h"
#include "utils.h"

void test_btree_node()
{
        struct btree_node *tree;

        UTILS_LOG("\n====== tree 1 =======\n");
        /*
         *   3
         *  / \
         * 9   20
         *    /  \
         *   15   7
         */
        size_t data1[] = {3, 9, 20, BTREE_NULL, BTREE_NULL, 15, 7};
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
        tree = btree(data1, ARRAY_SIZE(data1));
        UTILS_LOG("tree={}", UTYPE(tree));
        free_btree(tree);

        UTILS_LOG("\n====== tree 2 =======\n");
        /*
         *       1
         *      / \
         *     2   2
         *    / \
         *   3   3
         *  / \
         * 4   4
         */
        size_t data2[] = {1, 2, 2, 3, 3, BTREE_NULL, BTREE_NULL, 4, 4};
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
        tree = btree(data2, ARRAY_SIZE(data2));
        UTILS_LOG("tree={}", UTYPE(tree));
        free_btree(tree);

        UTILS_LOG("\n====== tree 3 =======\n");
        /*
         *       5
         *      / \
         *     4   8
         *    /   / \
         *   11  13  4
         *  / \       \
         * 7   2       1
         */
        size_t data3[] = {5, 4, 8, 11, BTREE_NULL, 13, 4, 7, 2, BTREE_NULL, BTREE_NULL, BTREE_NULL, 1};
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
                                                .right =
                                                        &(struct btree_node){
                                                                .value = 1,
                                                                .left = 0,
                                                                .right = 0,
                                                        },
                                        },
                        },
        };
        UTILS_LOG("tree3={}", UTYPE(tree3));
        tree = btree(data3, ARRAY_SIZE(data3));
        UTILS_LOG("tree={}", UTYPE(tree));
        free_btree(tree);

        UTILS_LOG("\n====== tree 4 =======\n");
        /*
         *   1
         *  / \
         * 2   3
         */
        size_t data4[] = {1, 2, 3};
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
        tree = btree(data4, ARRAY_SIZE(data4));
        UTILS_LOG("tree={}", UTYPE(tree));
        free_btree(tree);

        UTILS_LOG("\n====== tree 5 =======\n");
        /*
         *     1
         *    / \
         *   2   5
         *  / \   \
         * 3   4   6
         */
        size_t data5[] = {1, 2, 5, 3, 4, BTREE_NULL, 6};
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
        tree = btree(data5, ARRAY_SIZE(data5));
        UTILS_LOG("tree={}", UTYPE(tree));
        free_btree(tree);

        UTILS_LOG("\n====== tree 6 =======\n");
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
        size_t data6[] = {1, BTREE_NULL, 2, BTREE_NULL, 3, BTREE_NULL, 4, BTREE_NULL, 5};
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
        tree = btree(data6, ARRAY_SIZE(data6));
        UTILS_LOG("tree={}", UTYPE(tree));
        free_btree(tree);

        UTILS_LOG("\n====== tree 7 =======\n");
        /*
         *       5
         *      / \
         *     4   8
         *    /   / \
         *   11  13  4
         *  / \     / \
         * 7   2   5   1
         */
        size_t data7[] = {5, 4, 8, 11, BTREE_NULL, 13, 4, 7, 2, BTREE_NULL, BTREE_NULL, 5, 1};
        struct btree_node *tree7 = &(struct btree_node){
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
                                                .left =
                                                        &(struct btree_node){
                                                                .value = 5,
                                                                .left = 0,
                                                                .right = 0,
                                                        },
                                                .right =
                                                        &(struct btree_node){
                                                                .value = 1,
                                                                .left = 0,
                                                                .right = 0,
                                                        },
                                        },
                        },
        };
        UTILS_LOG("tree7={}", UTYPE(tree7));
        tree = btree(data7, ARRAY_SIZE(data7));
        UTILS_LOG("tree={}", UTYPE(tree));
        free_btree(tree);

        UTILS_LOG("\n====== tree 8 =======\n");
        /*
         *        1
         *      /   \
         *     2     3
         *    / \   / \
         *   4   5 6   7
         */
        size_t data8[] = {1, 2, 3, 4, 5, 6, 7};
        struct btree_node *tree8 = &(struct btree_node){
                .value = 1,
                .left =
                        &(struct btree_node){
                                .value = 2,
                                .left =
                                        &(struct btree_node){
                                                .value = 4,
                                                .left = 0,
                                                .right = 0,
                                        },
                                .right =
                                        &(struct btree_node){
                                                .value = 5,
                                                .left = 0,
                                                .right = 0,
                                        },
                        },
                .right =
                        &(struct btree_node){
                                .value = 3,
                                .left =
                                        &(struct btree_node){
                                                .value = 6,
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
        UTILS_LOG("tree8={}", UTYPE(tree8));
        tree = btree(data8, ARRAY_SIZE(data8));
        UTILS_LOG("tree={}", UTYPE(tree));
        free_btree(tree);

        UTILS_LOG("\n====== tree 9 =======\n");
        /*
         *        1
         *      /   \
         *     2     3
         *    / \     \
         *   4   5     8
         *      / \   /
         *     6   7 9
         */
        size_t data9[] = {1, 2, 3, 4, 5, BTREE_NULL, 8, BTREE_NULL, BTREE_NULL, 6, 7, 9};
        struct btree_node *tree9 = &(struct btree_node){
                .value = 1,
                .left =
                        &(struct btree_node){
                                .value = 2,
                                .left =
                                        &(struct btree_node){
                                                .value = 4,
                                                .left = 0,
                                                .right = 0,
                                        },
                                .right =
                                        &(struct btree_node){
                                                .value = 5,
                                                .left =
                                                        &(struct btree_node){
                                                                .value = 6,
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
                        },
                .right =
                        &(struct btree_node){
                                .value = 3,
                                .left = 0,
                                .right =
                                        &(struct btree_node){
                                                .value = 8,
                                                .left =
                                                        &(struct btree_node){
                                                                .value = 9,
                                                                .left = 0,
                                                                .right = 0,
                                                        },
                                                .right = 0,
                                        },
                        },
        };
        UTILS_LOG("tree9={}", UTYPE(tree9));
        tree = btree(data9, ARRAY_SIZE(data9));
        UTILS_LOG("tree={}", UTYPE(tree));
        free_btree(tree);

        UTILS_LOG("\n====== tree 10 =======\n");
        /*
         * 1
         *  \
         *   2
         *  /
         * 3
         */
        size_t data10[] = {1, BTREE_NULL, 2, 3};
        struct btree_node *tree10 = &(struct btree_node){
                .value = 1,
                .left = 0,
                .right =
                        &(struct btree_node){
                                .value = 2,
                                .left =
                                        &(struct btree_node){
                                                .value = 3,
                                                .left = 0,
                                                .right = 0,
                                        },
                                .right = 0,
                        },
        };
        UTILS_LOG("tree10={}", UTYPE(tree10));
        tree = btree(data10, ARRAY_SIZE(data10));
        UTILS_LOG("tree={}", UTYPE(tree));
        free_btree(tree);
}
