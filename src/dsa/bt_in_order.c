#include "common.h"
#include "utils/asserts.h"

extern int *dsa_bt_in_order(struct dsa_bt *head, int *o_len);

void test_dsa_bt_in_order()
{
        int_array expected = {(int[]){5, 7, 10, 15, 20, 29, 30, 45, 50, 100}, 10};
        int_array actual = {dsa_bt_in_order(tree, &actual.len)};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);
}
