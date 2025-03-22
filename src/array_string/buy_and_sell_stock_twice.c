#include "array_string.h"
#include "utils/asserts.h"

extern int array_string_buyAndSellStockTwice(int priceSize, int prices[priceSize]);

void test_array_string_buyAndSellStockTwice()
{
        int_array A = {(int[]){310, 315, 275, 295, 260, 270, 290, 230, 255, 250}, 10};
        int_obj actual = (int_obj){array_string_buyAndSellStockTwice(A.len, A.data)};
        ASSERT_EQUAL(actual, (int_obj){30});
}
