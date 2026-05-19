from unittest import TestCase
from test import in_order_search
from test.test_core_tree import tree

class TestBTInOrder(TestCase):
    def test_bt_in_order(self):
        self.assertEqual(in_order_search(tree), [
            5,
            7,
            10,
            15,
            20,
            29,
            30,
            45,
            50,
            100,
        ])
