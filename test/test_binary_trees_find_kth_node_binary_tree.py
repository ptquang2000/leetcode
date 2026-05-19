from unittest import TestCase
from common.binary_node import form_binary_tree
from test import find_kth_node_binary_tree

class TestFindKThNodeBinaryTree(TestCase):
    def test_find_kth_noed_binary_tree(self):
        tree = form_binary_tree([3,1,4,None,2])
        assert tree
        node = find_kth_node_binary_tree(tree, 1)
        self.assertIsNotNone(node)
        self.assertEqual(node.data, 1)
        tree = form_binary_tree([5,3,6,2,4,None,None,1])
        assert tree
        node = find_kth_node_binary_tree(tree, 3)
        self.assertIsNotNone(node)
        self.assertEqual(node.data, 3)

