import unittest
from common.binary_node import to_bfs, form_binary_tree, find_node_by_index
from test import (
    binary_tree_from_preorder_inorder,
    create_list_of_leaves,
    find_kth_node_binary_tree,
    has_path_sum,
    inorder_traversal,
    is_balanced_binary_tree,
    is_symmetric,
    lca,
    preorder_traversal,
    reconstruct_preorder,
    sum_root_to_leaf,
)


class TestBinaryTrees(unittest.TestCase):
    def test_binary_tree_from_preorder_inorder(self):
        tree = binary_tree_from_preorder_inorder([3,9,20,15,7],[9,3,15,20,7])
        self.assertEqual(to_bfs(tree), [3,9,20,None,None,15,7])
        tree = binary_tree_from_preorder_inorder([-1],[-1])
        self.assertEqual(to_bfs(tree), [-1])

    def test_create_list_of_leaves(self):
        leaves = create_list_of_leaves(form_binary_tree([1,2,3,4,5,None,None]))
        self.assertCountEqual([leave.value for leave in leaves],[3,5,4])
        leaves = create_list_of_leaves(form_binary_tree([1]))
        self.assertCountEqual([leave.value for leave in leaves],[1])

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

    def test_has_path_sum(self):
        self.assertTrue(has_path_sum(form_binary_tree([5,4,8,11,None,13,4,7,2,None,None,None,1]),22))
        self.assertFalse(has_path_sum(form_binary_tree([1,2,3]),5))
        self.assertFalse(has_path_sum(None,0))

    def test_inorder_traversal(self):
        self.assertEqual(inorder_traversal(form_binary_tree([1,None,2,3])),[1,3,2])
        self.assertEqual(inorder_traversal(None),[])
        self.assertEqual(inorder_traversal(form_binary_tree([1])),[1])

    def test_is_balanced_binary_tree(self):
        self.assertTrue(is_balanced_binary_tree(form_binary_tree([3,9,20,None,None,15,7])))
        self.assertFalse(is_balanced_binary_tree(form_binary_tree([1,2,2,3,3,None,None,4,4])))
        self.assertTrue(is_balanced_binary_tree(form_binary_tree([])))

    def test_is_symmetric(self):
        self.assertTrue(is_symmetric(form_binary_tree([1,2,2,3,4,4,3])))
        self.assertFalse(is_symmetric(form_binary_tree([1,2,2,None,3,None,3])))

    def test_lca(self):
        tree = form_binary_tree([3,5,1,6,2,0,8,None,None,7,4])
        assert tree
        self.assertIs(lca(tree, find_node_by_index(tree, 1), find_node_by_index(tree, 2)), find_node_by_index(tree, 0))
        self.assertIs(lca(tree, find_node_by_index(tree, 1), find_node_by_index(tree, 10)), find_node_by_index(tree, 1))
        tree = form_binary_tree([1,2])
        assert tree
        self.assertIs(lca(tree, find_node_by_index(tree, 0), find_node_by_index(tree, 1)), find_node_by_index(tree, 0))

    def test_preorder_traversal(self):
        self.assertEqual(preorder_traversal(form_binary_tree([1,None,2,3])),[1,2,3])
        self.assertEqual(preorder_traversal(None),[])
        self.assertEqual(preorder_traversal(form_binary_tree([1])),[1])

    def test_reconstruct_preorder(self):
        tree = reconstruct_preorder([8,5,1,7,10,12])
        self.assertEqual(to_bfs(tree),[8,5,10,1,7,None,12])
        tree = reconstruct_preorder([1,None,3])
        self.assertEqual(to_bfs(tree),[1,None,3])

    def test_sum_root_to_leaf(self):
        self.assertEqual(sum_root_to_leaf(form_binary_tree([1,2,3])), 25)
        self.assertEqual(sum_root_to_leaf(form_binary_tree([4,9,0,5,1])), 1026)
