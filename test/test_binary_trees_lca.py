from unittest import TestCase
from common.binary_node import find_node_by_index, form_binary_tree
from test import lca


class TestLCA(TestCase):
    def test_lca(self):
        tree = form_binary_tree([3,5,1,6,2,0,8,None,None,7,4])
        assert tree
        self.assertIs(lca(tree, find_node_by_index(tree, 1), find_node_by_index(tree, 2)), find_node_by_index(tree, 0))
        self.assertIs(lca(tree, find_node_by_index(tree, 1), find_node_by_index(tree, 10)), find_node_by_index(tree, 1))

        tree = form_binary_tree([1,2])
        assert tree
        self.assertIs(lca(tree, find_node_by_index(tree, 0), find_node_by_index(tree, 1)), find_node_by_index(tree, 0))
