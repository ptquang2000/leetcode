from unittest import TestCase
from test import pre_order_search
from test.test_core_tree import tree

class TestBTPreOrder(TestCase):
    def test_bt_pre_order(self):
        self.assertEqual(pre_order_search(tree), [
            20,
            10,
            5,
            7,
            15,
            50,
            30,
            29,
            45,
            100,
        ])
