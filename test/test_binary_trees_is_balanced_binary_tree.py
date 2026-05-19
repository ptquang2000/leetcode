from unittest import TestCase
from common.binary_node import form_binary_tree
from test import is_balanced_binary_tree


class TestIsBalancedBinaryTree(TestCase):
    def test_is_balanced_binary_tree(self):
        self.assertTrue(is_balanced_binary_tree(form_binary_tree([3,9,20,None,None,15,7])))
        self.assertFalse(is_balanced_binary_tree(form_binary_tree([1,2,2,3,3,None,None,4,4])))
        self.assertTrue(is_balanced_binary_tree(form_binary_tree([])))
