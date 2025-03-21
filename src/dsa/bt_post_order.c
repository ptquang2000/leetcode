#include "common.h"
#include "utils/asserts.h"

extern int *dsa_bt_post_order(struct dsa_bt *head, int *o_len);

void test_dsa_bt_post_order()
{
        int_array expected = {(int[]){7, 5, 15, 10, 29, 45, 30, 100, 50, 20}, 10};
        int_array actual = {dsa_bt_post_order(tree, &actual.len)};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);
}
