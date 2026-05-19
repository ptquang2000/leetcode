import unittest
from test import buy_and_sell_stock_twice

class TestBuyAndSellStockTwice(unittest.TestCase):
    def test_buy_and_sell_stock_twice(self):
        A = [12,11,13,9,12,8,14,13,15]
        self.assertEqual(buy_and_sell_stock_twice(A), 10)
