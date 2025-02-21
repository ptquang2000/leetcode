#include "common.h"
#include "utils/utils.h"

extern int *dsa_bt_in_order(struct dsa_bt *head, int *o_len);

void test_dsa_bt_in_order()
{
        int expected[] = {5, 7, 10, 15, 20, 29, 30, 45, 50, 100};
        int len;
        int *actual = dsa_bt_in_order(tree, &len);
        UTILS_ASSERT_EQUAL_ARRAY(actual, expected, ARRAY_SIZE(expected));
        free(actual);
}
