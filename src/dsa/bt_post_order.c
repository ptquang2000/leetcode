#include "common.h"
#include "utils/asserts.h"

extern int *dsa_bt_post_order(struct dsa_bt *head, int *o_len);

void test_dsa_bt_post_order()
{
        int expected[] = {7, 5, 15, 10, 29, 45, 30, 100, 50, 20};
        int len;
        int *actual = dsa_bt_post_order(tree, &len);
        ASSERT_EQUAL(actual, expected, ARRAY_SIZE(expected));
        free(actual);
}
