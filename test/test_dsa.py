import unittest
import random
from common import BinaryNode
from test import (
    binary_search,
    bt_bfs,
    bubble_sort,
    compare,
    DoublyLinkedList,
    in_order_search,
    linear_search,
    post_order_search,
    pre_order_search,
    Queue,
    quick_sort,
    solve,
    Stack,
    two_crystal_balls,
)

tree = BinaryNode(
    value=20,
    right=BinaryNode(
        value=50,
        right=BinaryNode(value=100, right=None, left=None),
        left=BinaryNode(
            value=30,
            right=BinaryNode(value=45, right=None, left=None),
            left=BinaryNode(value=29, right=None, left=None),
        ),
    ),
    left=BinaryNode(
        value=10,
        right=BinaryNode(value=15, right=None, left=None),
        left=BinaryNode(
            value=5,
            right=BinaryNode(value=7, right=None, left=None),
            left=None,
        ),
    ),
)

tree2 = BinaryNode(
    value=20,
    right=BinaryNode(
        value=50,
        right=None,
        left=BinaryNode(
            value=30,
            right=BinaryNode(
                value=45,
                right=BinaryNode(value=49, right=None, left=None),
                left=None,
            ),
            left=BinaryNode(
                value=29,
                right=None,
                left=BinaryNode(value=21, right=None, left=None),
            ),
        ),
    ),
    left=BinaryNode(
        value=10,
        right=BinaryNode(value=15, right=None, left=None),
        left=BinaryNode(
            value=5,
            right=BinaryNode(value=7, right=None, left=None),
            left=None,
        ),
    ),
)


class TestDSA(unittest.TestCase):
    def test_binary_search(self):
        foo = [1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420]
        self.assertTrue(binary_search(foo, 69))
        self.assertFalse(binary_search(foo, 1336))
        self.assertTrue(binary_search(foo, 69420))
        self.assertFalse(binary_search(foo, 69421))
        self.assertTrue(binary_search(foo, 1))
        self.assertFalse(binary_search(foo, 0))

    def test_bt_bfs(self):
        self.assertTrue(bt_bfs(tree, 45))
        self.assertTrue(bt_bfs(tree, 7))
        self.assertFalse(bt_bfs(tree, 69))

    def test_bt_in_order(self):
        self.assertEqual(in_order_search(tree), [5, 7, 10, 15, 20, 29, 30, 45, 50, 100])

    def test_bt_post_order(self):
        self.assertEqual(post_order_search(tree), [7, 5, 15, 10, 29, 45, 30, 100, 50, 20])

    def test_bt_pre_order(self):
        self.assertEqual(pre_order_search(tree), [20, 10, 5, 7, 15, 50, 30, 29, 45, 100])

    def test_bubble_sort(self):
        arr = [9, 3, 7, 4, 69, 420, 42]
        bubble_sort(arr)
        self.assertEqual(arr, [3, 4, 7, 9, 42, 69, 420])

    def test_compare_binary_trees(self):
        self.assertTrue(compare(tree, tree))
        self.assertFalse(compare(tree, tree2))

    def test_doubly_linked_list(self):
        lst = DoublyLinkedList()
        lst.append(5)
        lst.append(7)
        lst.append(9)
        self.assertEqual(lst.get(2), 9)
        self.assertEqual(lst.removeAt(1), 7)
        self.assertEqual(lst.length, 2)
        lst.append(11)
        self.assertEqual(lst.removeAt(1), 9)
        self.assertEqual(lst.remove(9), None)
        self.assertEqual(lst.removeAt(0), 5)
        self.assertEqual(lst.removeAt(0), 11)
        self.assertEqual(lst.length, 0)
        lst.prepend(5)
        lst.prepend(7)
        lst.prepend(9)
        self.assertEqual(lst.get(2), 5)
        self.assertEqual(lst.get(0), 9)
        self.assertEqual(lst.remove(9), 9)
        self.assertEqual(lst.length, 2)
        self.assertEqual(lst.get(0), 7)

    def test_linear_search(self):
        foo = [1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420]
        self.assertTrue(linear_search(foo, 69))
        self.assertFalse(linear_search(foo, 1336))
        self.assertTrue(linear_search(foo, 69420))
        self.assertFalse(linear_search(foo, 69421))
        self.assertTrue(linear_search(foo, 1))
        self.assertFalse(linear_search(foo, 0))

    @staticmethod
    def _draw_path(data, path):
        data2 = [[c for c in line] for line in data]
        for p in path:
            if data2[p['y']] and data2[p['y']][p['x']]:
                data2[p['y']][p['x']] = '*'
        return [''.join(d) for d in data2]

    def test_solve(self):
        maze = [
            "xxxxxxxxxx x",
            "x        x x",
            "x        x x",
            "x xxxxxxxx x",
            "x          x",
            "x xxxxxxxxxx",
        ]
        maze_result = [
            {'x': 10, 'y': 0},
            {'x': 10, 'y': 1},
            {'x': 10, 'y': 2},
            {'x': 10, 'y': 3},
            {'x': 10, 'y': 4},
            {'x': 9, 'y': 4},
            {'x': 8, 'y': 4},
            {'x': 7, 'y': 4},
            {'x': 6, 'y': 4},
            {'x': 5, 'y': 4},
            {'x': 4, 'y': 4},
            {'x': 3, 'y': 4},
            {'x': 2, 'y': 4},
            {'x': 1, 'y': 4},
            {'x': 1, 'y': 5},
        ]
        result = solve(maze, 'x', {'x': 10, 'y': 0}, {'x': 1, 'y': 5})
        self.assertEqual(self._draw_path(maze, result), self._draw_path(maze, maze_result))

    def test_queue(self):
        queue = Queue()
        queue.enqueue(5)
        queue.enqueue(7)
        queue.enqueue(9)
        self.assertEqual(queue.deque(), 5)
        self.assertEqual(queue.length, 2)
        queue.enqueue(11)
        self.assertEqual(queue.deque(), 7)
        self.assertEqual(queue.deque(), 9)
        self.assertEqual(queue.peek(), 11)
        self.assertEqual(queue.deque(), 11)
        self.assertEqual(queue.deque(), None)
        self.assertEqual(queue.length, 0)
        queue.enqueue(69)
        self.assertEqual(queue.peek(), 69)
        self.assertEqual(queue.length, 1)

    def test_quick_sort(self):
        arr = [9, 3, 7, 4, 69, 420, 42]
        quick_sort(arr)
        self.assertEqual(arr, [3, 4, 7, 9, 42, 69, 420])

    def test_stack(self):
        stack = Stack()
        stack.push(5)
        stack.push(7)
        stack.push(9)
        self.assertEqual(stack.pop(), 9)
        self.assertEqual(stack.length, 2)
        stack.push(11)
        self.assertEqual(stack.pop(), 11)
        self.assertEqual(stack.pop(), 7)
        self.assertEqual(stack.peek(), 5)
        self.assertEqual(stack.pop(), 5)
        self.assertEqual(stack.pop(), None)
        stack.push(69)
        self.assertEqual(stack.peek(), 69)
        self.assertEqual(stack.length, 1)

    def test_two_crystal_balls(self):
        idx = random.randrange(0, 10000)
        data = [i >= idx for i in range(0, 10000)]
        self.assertEqual(two_crystal_balls(data), idx)
        self.assertEqual(two_crystal_balls([False for i in range(0, 821)]), -1)
