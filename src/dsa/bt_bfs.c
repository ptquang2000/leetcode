#include "common.h"
#include "utils/utils.h"
#include <stdbool.h>

extern bool dsa_bt_bfs(struct dsa_bt *head, int needle);

void test_dsa_bt_bfs()
{
        UTILS_ASSERT_TRUE(dsa_bt_bfs(tree, 45));
        UTILS_ASSERT_TRUE(dsa_bt_bfs(tree, 7));
        UTILS_ASSERT_FALSE(dsa_bt_bfs(tree, 69));
}
