from unittest import TestCase
from test import preorder_traversal
from common.binary_node import form_binary_tree


class TestPreorderTraversal(TestCase):
    def test_preorder_traversal(self):
        self.assertEqual(preorder_traversal(form_binary_tree([1,None,2,3])),[1,2,3])
        self.assertEqual(preorder_traversal(None),[])
        self.assertEqual(preorder_traversal(form_binary_tree([1])),[1])
