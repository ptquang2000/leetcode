from unittest import TestCase
from common.binary_node import form_binary_tree
from test import create_list_of_leaves


class TestCreateListOfLeaves(TestCase):
    def test_create_list_of_leaves(self):
        leaves = create_list_of_leaves(form_binary_tree([1,2,3,4,5,None,None]))
        self.assertCountEqual([leave.value for leave in leaves],[3,5,4])
        leaves = create_list_of_leaves(form_binary_tree([1]))
        self.assertCountEqual([leave.value for leave in leaves],[1])
