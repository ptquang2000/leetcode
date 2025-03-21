#include "dsa/common.h"
#include "utils/asserts.h"
#include <stdbool.h>

extern bool dsa_bst_dfs(struct dsa_bt *tree, int v);

void test_dsa_bst_dfs()
{
        ASSERT_TRUE(dsa_bst_dfs(tree, 45));
        ASSERT_TRUE(dsa_bst_dfs(tree, 7));
        ASSERT_FALSE(dsa_bst_dfs(tree, 69));
}
