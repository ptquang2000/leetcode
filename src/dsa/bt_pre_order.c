#include "common.h"
#include "utils/asserts.h"

extern int *dsa_bt_pre_order(struct dsa_bt *head, int *o_len);

void test_dsa_bt_pre_order()
{
        int expected[] = {20, 10, 5, 7, 15, 50, 30, 29, 45, 100};
        int len;
        int *actual = dsa_bt_pre_order(tree, &len);
        ASSERT_EQUAL(actual, expected, ARRAY_SIZE(expected));
        free(actual);
}
