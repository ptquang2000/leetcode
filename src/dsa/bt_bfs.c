#include "common.h"
#include "utils/asserts.h"
#include <stdbool.h>

extern bool dsa_bt_bfs(struct dsa_bt *head, int needle);

void test_dsa_bt_bfs()
{
        ASSERT_TRUE(dsa_bt_bfs(tree, 45));
        ASSERT_TRUE(dsa_bt_bfs(tree, 7));
        ASSERT_FALSE(dsa_bt_bfs(tree, 69));
}
