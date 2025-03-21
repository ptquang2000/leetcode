#include "common.h"
#include "utils/asserts.h"
#include <stdbool.h>

extern bool dsa_compare(struct dsa_bt *a, struct dsa_bt *b);

void test_dsa_compare()
{
        ASSERT_TRUE(dsa_compare(tree, tree));
        ASSERT_FALSE(dsa_compare(tree, tree2));
}
