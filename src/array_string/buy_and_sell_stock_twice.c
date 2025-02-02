#include "array_string.h"
#include "utils/utils.h"

extern int array_string_buyAndSellStockTwice(int priceSize, int prices[]);

void test_array_string_buyAndSellStockTwice()
{
        int A[] = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
        int actual = array_string_buyAndSellStockTwice(10, A);
        UTILS_ASSERT_EQUAL(actual, 30);
}
