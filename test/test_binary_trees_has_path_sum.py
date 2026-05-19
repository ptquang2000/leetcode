from unittest import TestCase
from common.binary_node import form_binary_tree
from test import has_path_sum


class TestHasPathSum(TestCase):
    def test_has_path_sum(self):
        self.assertTrue(has_path_sum(form_binary_tree([5,4,8,11,None,13,4,7,2,None,None,None,1]),22))
        self.assertFalse(has_path_sum(form_binary_tree([1,2,3]),5))
        self.assertFalse(has_path_sum(None,0))
