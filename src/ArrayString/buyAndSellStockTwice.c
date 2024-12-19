#include "ArrayString.h"
#include "utils.h"

// Declaration:
int ArrayString_buyAndSellStockTwice(int priceSize, int prices[]);

void test_ArrayString_buyAndSellStockTwice()
{
        int A[] = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
        int actual = ArrayString_buyAndSellStockTwice(10, A);
        UTILS_ASSERT_EQUAL(actual, 30);
}
