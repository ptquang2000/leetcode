from unittest import TestCase
from test import bt_bfs
from test.test_core_tree import tree

class TestBTBFS(TestCase):
    def test_bt_bfs(self):
        self.assertTrue(bt_bfs(tree, 45))
        self.assertTrue(bt_bfs(tree, 7))
        self.assertFalse(bt_bfs(tree, 69))
