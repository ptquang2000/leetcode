from unittest import TestCase
from test import compare
from test.test_core_tree import tree, tree2

class TestCompareBinaryTrees(TestCase):
    def test_compare_binary_trees(self):
        self.assertTrue(compare(tree, tree))
        self.assertFalse(compare(tree, tree2))
