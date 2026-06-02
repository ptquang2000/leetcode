import unittest
import random
from common import BinaryNode
from test import (
    binary_search,
    bst_dfs,
    bt_bfs,
    bubble_sort,
    compare,
    dijkstra_list,
    DoublyLinkedList,
    graph_list_dfs,
    graph_matrix_bfs,
    in_order_search,
    linear_search,
    LRU,
    MinHeap,
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

list1 = [
    [(1, 3), (2, 1)],
    [(0, 3), (2, 4), (4, 1)],
    [(1, 4), (3, 7), (0, 1)],
    [(2, 7), (4, 5), (6, 1)],
    [(1, 1), (3, 5), (5, 2)],
    [(6, 1), (4, 2), (2, 18)],
    [(3, 1), (5, 1)],
]

list2 = [
    [(1, 3), (2, 1)],
    [(4, 1)],
    [(3, 7)],
    [],
    [(1, 1), (3, 5), (5, 2)],
    [(2, 18), (6, 1)],
    [(3, 1)],
]

matrix2 = [
    [0, 3, 1, 0, 0, 0, 0],
    [0, 0, 0, 0, 1, 0, 0],
    [0, 0, 7, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 5, 0, 2, 0],
    [0, 0, 18, 0, 0, 0, 1],
    [0, 0, 0, 1, 0, 0, 1],
]


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
        self.assertEqual(in_order_search(tree2), [5, 7, 10, 15, 20, 21, 29, 30, 45, 49, 50])
        self.assertEqual(in_order_search(BinaryNode(1, None, None)), [1])

    def test_bt_post_order(self):
        self.assertEqual(post_order_search(tree), [7, 5, 15, 10, 29, 45, 30, 100, 50, 20])
        self.assertEqual(post_order_search(tree2), [7, 5, 15, 10, 21, 29, 49, 45, 30, 50, 20])
        self.assertEqual(post_order_search(BinaryNode(1, None, None)), [1])

    def test_bt_pre_order(self):
        self.assertEqual(pre_order_search(tree), [20, 10, 5, 7, 15, 50, 30, 29, 45, 100])
        self.assertEqual(pre_order_search(tree2), [20, 10, 5, 7, 15, 50, 30, 29, 21, 45, 49])
        self.assertEqual(pre_order_search(BinaryNode(1, None, None)), [1])

    def test_bubble_sort(self):
        arr = [9, 3, 7, 4, 69, 420, 42]
        bubble_sort(arr)
        self.assertEqual(arr, [3, 4, 7, 9, 42, 69, 420])
        arr = [1, 2, 3, 4, 5]
        bubble_sort(arr)
        self.assertEqual(arr, [1, 2, 3, 4, 5])
        arr = [5, 4, 3, 2, 1]
        bubble_sort(arr)
        self.assertEqual(arr, [1, 2, 3, 4, 5])
        arr = [5]
        bubble_sort(arr)
        self.assertEqual(arr, [5])
        arr = [3, 3, 1, 2, 3]
        bubble_sort(arr)
        self.assertEqual(arr, [1, 2, 3, 3, 3])

    def test_compare_binary_trees(self):
        self.assertTrue(compare(tree, tree))
        self.assertFalse(compare(tree, tree2))

    def test_doubly_linked_list(self):
        lst = DoublyLinkedList()

        self.assertIsNone(lst.get(0))
        self.assertIsNone(lst.get(-1))

        got = lst.append(1)
        self.assertEqual(got, 1)
        self.assertEqual(lst.length, 1)
        self.assertEqual(lst.get(0), 1)
        lst.append(2)
        lst.append(3)
        self.assertEqual(lst.length, 3)
        self.assertEqual(lst.get(0), 1)
        self.assertEqual(lst.get(1), 2)
        self.assertEqual(lst.get(2), 3)

        got = lst.prepend(0)
        self.assertEqual(got, 0)
        self.assertEqual(lst.length, 4)
        self.assertEqual(lst.get(0), 0)
        lst.prepend(-1)
        self.assertEqual(lst.get(0), -1)
        self.assertEqual(lst.length, 5)

        self.assertIsNone(lst.get(10))
        self.assertIsNone(lst.get(-1))

        got = lst.remove_at(2)
        self.assertEqual(got, 1)
        self.assertEqual(lst.length, 4)
        self.assertEqual(lst.get(0), -1)
        self.assertEqual(lst.get(1), 0)
        self.assertEqual(lst.get(2), 2)
        self.assertEqual(lst.get(3), 3)

        got = lst.remove_at(0)
        self.assertEqual(got, -1)
        self.assertEqual(lst.length, 3)

        got = lst.remove_at(2)
        self.assertEqual(got, 3)
        self.assertEqual(lst.length, 2)
        self.assertEqual(lst.get(0), 0)
        self.assertEqual(lst.get(1), 2)

        got = lst.remove_at(0)
        self.assertEqual(got, 0)
        got = lst.remove_at(0)
        self.assertEqual(got, 2)
        self.assertEqual(lst.length, 0)

        self.assertIsNone(lst.remove_at(0))
        self.assertIsNone(lst.remove_at(-1))

        lst.append(7)
        lst.append(8)
        lst.append(9)
        self.assertIsNone(lst.remove_at(5))
        self.assertIsNone(lst.remove_at(-1))
        self.assertEqual(lst.length, 3)

        got = lst.remove(8)
        self.assertEqual(got, 8)
        self.assertEqual(lst.length, 2)
        self.assertEqual(lst.get(0), 7)
        self.assertEqual(lst.get(1), 9)

        got = lst.remove(7)
        self.assertEqual(got, 7)
        self.assertEqual(lst.length, 1)
        self.assertEqual(lst.get(0), 9)

        got = lst.remove(10)
        self.assertIsNone(got)

        got = lst.remove(9)
        self.assertEqual(got, 9)
        self.assertEqual(lst.length, 0)
        self.assertIsNone(lst.get(0))

        lst = DoublyLinkedList()
        for v in (1, 2, 3, 2, 4):
            lst.append(v)
        got = lst.remove(2)
        self.assertEqual(got, 2)
        self.assertEqual(lst.length, 3)
        self.assertEqual(lst.get(0), 1)
        self.assertEqual(lst.get(1), 3)
        self.assertEqual(lst.get(2), 4)

        lst = DoublyLinkedList()
        self.assertIsNone(lst.remove(1))

        lst = DoublyLinkedList()
        self.assertIsNone(lst.insert_at(100, -1))
        self.assertIsNone(lst.insert_at(100, 10))

        lst = DoublyLinkedList()
        for i in range(5):
            lst.append(i)
        self.assertEqual(lst.length, 5)

        for i in range(5):
            got = lst.remove_at(0)
            self.assertEqual(got, i)
        self.assertEqual(lst.length, 0)

        for i in range(5):
            lst.prepend(i)
        self.assertEqual(lst.length, 5)
        self.assertEqual(lst.get(0), 4)
        self.assertEqual(lst.get(4), 0)

        lst.remove(3)
        self.assertEqual(lst.length, 4)
        self.assertEqual(lst.get(0), 4)
        self.assertEqual(lst.get(1), 2)
        self.assertEqual(lst.get(2), 1)
        self.assertEqual(lst.get(3), 0)

        for i in range(lst.length - 1, -1, -1):
            lst.remove_at(i)
        self.assertEqual(lst.length, 0)

        # insert_at in the middle
        lst = DoublyLinkedList()
        for v in (1, 2, 4, 5):
            lst.append(v)
        got = lst.insert_at(3, 2)
        self.assertEqual(got, 3)
        self.assertEqual(lst.length, 5)
        self.assertEqual(lst.get(0), 1)
        self.assertEqual(lst.get(1), 2)
        self.assertEqual(lst.get(2), 3)
        self.assertEqual(lst.get(3), 4)
        self.assertEqual(lst.get(4), 5)

        # insert_at at the beginning
        got = lst.insert_at(0, 0)
        self.assertEqual(got, 0)
        self.assertEqual(lst.get(0), 0)
        self.assertEqual(lst.get(1), 1)
        self.assertEqual(lst.length, 6)

        # insert_at at the end
        got = lst.insert_at(6, lst.length)
        self.assertEqual(got, 6)
        self.assertEqual(lst.length, 7)
        self.assertEqual(lst.get(6), 6)

        # insert_at on empty list at idx 0 (should work like prepend)
        lst = DoublyLinkedList()
        got = lst.insert_at(42, 0)
        self.assertEqual(got, 42)
        self.assertEqual(lst.length, 1)
        self.assertEqual(lst.get(0), 42)

        # insert_at out of bounds
        self.assertIsNone(lst.insert_at(99, -1))
        self.assertIsNone(lst.insert_at(99, 10))
        self.assertEqual(lst.length, 1)

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
        arr = [1, 2, 3, 4, 5]
        quick_sort(arr)
        self.assertEqual(arr, [1, 2, 3, 4, 5])
        arr = [5, 4, 3, 2, 1]
        quick_sort(arr)
        self.assertEqual(arr, [1, 2, 3, 4, 5])
        arr = [5]
        quick_sort(arr)
        self.assertEqual(arr, [5])
        arr = [3, 3, 1, 2, 3]
        quick_sort(arr)
        self.assertEqual(arr, [1, 2, 3, 3, 3])

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

    def test_bst_dfs(self):
        self.assertTrue(bst_dfs(tree, 45))
        self.assertTrue(bst_dfs(tree, 7))
        self.assertFalse(bst_dfs(tree, 69))

    def test_min_heap(self):
        h = MinHeap()
        self.assertEqual(h.length, 0)
        h.insert(5)
        h.insert(3)
        h.insert(69)
        h.insert(420)
        h.insert(4)
        h.insert(1)
        h.insert(8)
        h.insert(7)
        self.assertEqual(h.length, 8)
        self.assertEqual(h.delete(), 1)
        self.assertEqual(h.delete(), 3)
        self.assertEqual(h.delete(), 4)
        self.assertEqual(h.delete(), 5)
        self.assertEqual(h.length, 4)
        self.assertEqual(h.delete(), 7)
        self.assertEqual(h.delete(), 8)
        self.assertEqual(h.delete(), 69)
        self.assertEqual(h.delete(), 420)
        self.assertEqual(h.length, 0)

    def test_graph_list_dfs(self):
        self.assertEqual(graph_list_dfs(list2, 0, 6), [0, 1, 4, 5, 6])
        self.assertIsNone(graph_list_dfs(list2, 6, 0))

    def test_graph_matrix_bfs(self):
        self.assertEqual(graph_matrix_bfs(matrix2, 0, 6), [0, 1, 4, 5, 6])
        self.assertIsNone(graph_matrix_bfs(matrix2, 6, 0))

    def test_dijkstra_list(self):
        self.assertEqual(dijkstra_list(list1, 0, 6), [0, 1, 4, 5, 6])

    def test_lru(self):
        lru = LRU(3)
        self.assertEqual(lru.get('foo'), -1)
        lru.update('foo', 69)
        self.assertEqual(lru.get('foo'), 69)
        lru.update('bar', 420)
        self.assertEqual(lru.get('bar'), 420)
        lru.update('baz', 1337)
        self.assertEqual(lru.get('baz'), 1337)
        lru.update('ball', 69420)
        self.assertEqual(lru.get('ball'), 69420)
        self.assertEqual(lru.get('foo'), -1)
        self.assertEqual(lru.get('bar'), 420)
        lru.update('foo', 69)
        self.assertEqual(lru.get('bar'), 420)
        self.assertEqual(lru.get('foo'), 69)
        self.assertEqual(lru.get('baz'), -1)
