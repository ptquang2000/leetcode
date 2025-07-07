#include "utils/asserts.h"

extern int array_string_buyAndSellStockTwice(int priceSize, int prices[priceSize]);

void test_array_string_buyAndSellStockTwice()
{
        {
                int_array A = {(int[]){12, 11, 13, 9, 12, 8, 14, 13, 15}, 10};
                int_obj actual = (int_obj){array_string_buyAndSellStockTwice(A.len, A.data)};
                ASSERT_EQUAL(actual, (int_obj){10});
        }
        {
                int_array A = {(int[]){2, 30, 15, 10, 8, 25, 80}, 10};
                int_obj actual = (int_obj){array_string_buyAndSellStockTwice(A.len, A.data)};
                ASSERT_EQUAL(actual, (int_obj){100});
        }
        {
                int_array A = {(int[]){7, 1, 5, 3, 6, 4}, 6};
                int_obj actual = (int_obj){array_string_buyAndSellStockTwice(A.len, A.data)};
                ASSERT_EQUAL(actual, (int_obj){7});
        }
        {
                int_array A = {(int[]){1, 2, 3, 4, 5}, 5};
                int_obj actual = (int_obj){array_string_buyAndSellStockTwice(A.len, A.data)};
                ASSERT_EQUAL(actual, (int_obj){4});
        }
        {
                int_array A = {(int[]){7, 6, 4, 3, 1}, 5};
                int_obj actual = (int_obj){array_string_buyAndSellStockTwice(A.len, A.data)};
                ASSERT_EQUAL(actual, (int_obj){0});
        }
}
