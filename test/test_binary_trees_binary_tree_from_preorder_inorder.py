from unittest import TestCase
from common.binary_node import to_bfs
from test import binary_tree_from_preorder_inorder

class TestBinaryTreeFromPreorderInorder(TestCase):
    def test_binary_tree_from_preorder_inorder(self):
        tree = binary_tree_from_preorder_inorder([3,9,20,15,7],[9,3,15,20,7])
        self.assertEqual(to_bfs(tree), [3,9,20,None,None,15,7])
        tree = binary_tree_from_preorder_inorder([-1],[-1])
        self.assertEqual(to_bfs(tree), [-1])
