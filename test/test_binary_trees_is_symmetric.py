from unittest import TestCase
from common.binary_node import form_binary_tree
from test import is_symmetric


class TestIsSymmetric(TestCase):
    def test_is_symmetric(self):
        self.assertTrue(is_symmetric(form_binary_tree([1,2,2,3,4,4,3])))
        self.assertFalse(is_symmetric(form_binary_tree([1,2,2,None,3,None,3])))
