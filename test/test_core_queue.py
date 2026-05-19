import unittest
from test import Queue

class TestQueue(unittest.TestCase):
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
