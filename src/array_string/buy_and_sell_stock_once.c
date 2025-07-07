#include "array_string.h"
#include "utils/asserts.h"

extern int array_string_buyAndSellStockOnce(int priceSize, int prices[priceSize]);

void test_array_string_buyAndSellStockOnce()
{
        {
                int_array A = {(int[]){310, 315, 275, 295, 260, 270, 290, 230, 255, 250}, 10};
                int_obj actual = {array_string_buyAndSellStockOnce(A.len, A.data)};
                ASSERT_EQUAL(actual, (int_obj){30});
        }
        {
                int_array A = {(int[]){10, 12, 9, 6, 8, 12}, 6};
                int_obj actual = {array_string_buyAndSellStockOnce(A.len, A.data)};
                ASSERT_EQUAL(actual, (int_obj){6});
        }
        {
                int_array A = {(int[]){7, 1, 5, 3, 6, 4}, 6};
                int_obj actual = {array_string_buyAndSellStockOnce(A.len, A.data)};
                ASSERT_EQUAL(actual, (int_obj){5});
        }
        {
                int_array A = {(int[]){7, 6, 4, 3, 1}, 5};
                int_obj actual = {array_string_buyAndSellStockOnce(A.len, A.data)};
                ASSERT_EQUAL(actual, (int_obj){0});
        }
}
