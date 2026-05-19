from unittest import TestCase
from common.binary_node import form_binary_tree
from test import sum_root_to_leaf


class TestSumRootToLeaf(TestCase):
    def test_sum_root_to_leaf(self):
        self.assertEqual(sum_root_to_leaf(form_binary_tree([1,2,3])), 25)
        self.assertEqual(sum_root_to_leaf(form_binary_tree([4,9,0,5,1])), 1026)

