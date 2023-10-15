#include "max_profit.h"
#include "unity.h"
#include <limits.h>

static int maxProfit(int* prices, int pricesSize)
{
	int maxProfit = 0, minPrice = INT_MAX;

	for (int i = 0; i < pricesSize; i++) {
		int profit = prices[i] - minPrice;
		maxProfit = profit > maxProfit ? profit : maxProfit; 

		minPrice = prices[i] < minPrice ? prices[i] : minPrice;
	}

	return maxProfit;
}

void test0_max_profit(void)
{
	int expected = 5;
	int prices[] = {7,1,5,3,6,4};
	int output = maxProfit(prices, 6);
	TEST_ASSERT_EQUAL_INT(expected, output);
}

void test1_max_profit(void)
{
	int expected = 0;
	int prices[] = {7,6,4,3,1};
	int output = maxProfit(prices, 5);
	TEST_ASSERT_EQUAL_INT(expected, output);
}
