import unittest
from test import buy_and_sell_stock_once

class TestBuyAndSellStockOnce(unittest.TestCase):
    def test_buy_and_sell_stock_once(self):
        A = [310,315,275,295,260,270,290,230,255,250]
        self.assertEqual(buy_and_sell_stock_once(A), 30)
