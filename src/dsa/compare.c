#include "common.h"
#include "utils/utils.h"
#include <stdbool.h>

extern bool dsa_compare(struct dsa_bt *a, struct dsa_bt *b);

void test_dsa_compare()
{
        UTILS_ASSERT_TRUE(dsa_compare(tree, tree));
        UTILS_ASSERT_FALSE(dsa_compare(tree, tree2));
}
