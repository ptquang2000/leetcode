#include "array_string.h"
#include "utils.h"

// Declaration:
int array_string_buyAndSellStockOnce(int priceSize, int prices[]);

void test_array_string_buyAndSellStockOnce()
{
        int A[] = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
        int actual = array_string_buyAndSellStockOnce(10, A);
        UTILS_ASSERT_EQUAL(actual, 30);
}
