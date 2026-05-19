from unittest import TestCase
from common.binary_node import to_bfs
from test import reconstruct_preorder


class TestReconstructPreorder(TestCase):
    def test_reconstruct_preorder(self):
        tree = reconstruct_preorder([8,5,1,7,10,12])
        self.assertEqual(to_bfs(tree),[8,5,10,1,7,None,12])
        tree = reconstruct_preorder([1,None,3])
        self.assertEqual(to_bfs(tree),[1,None,3])
