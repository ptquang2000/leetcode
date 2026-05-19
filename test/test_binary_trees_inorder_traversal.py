from unittest import TestCase
from test import inorder_traversal
from common.binary_node import form_binary_tree


class TestInorderTraversal(TestCase):
    def test_inorder_traversal(self):
        self.assertEqual(inorder_traversal(form_binary_tree([1,None,2,3])),[1,3,2])
        self.assertEqual(inorder_traversal(None),[])
        self.assertEqual(inorder_traversal(form_binary_tree([1])),[1])
