#include "array_string.h"
#include "utils/asserts.h"

extern int array_string_buyAndSellStockOnce(int priceSize, int prices[]);

void test_array_string_buyAndSellStockOnce()
{
        int_array A = {(int[]){310, 315, 275, 295, 260, 270, 290, 230, 255, 250}, 10};
        int_obj actual = {array_string_buyAndSellStockOnce(A.len, A.data)};
        ASSERT_EQUAL(actual, (int_obj){30});
}
