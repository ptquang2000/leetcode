#include "dsa/common.h"
#include "utils/utils.h"
#include <stdbool.h>

extern bool dsa_bst_dfs(struct dsa_bt *tree, int v);

void test_dsa_bst_dfs()
{
        UTILS_ASSERT_TRUE(dsa_bst_dfs(tree, 45));
        UTILS_ASSERT_TRUE(dsa_bst_dfs(tree, 7));
        UTILS_ASSERT_FALSE(dsa_bst_dfs(tree, 69));
}
