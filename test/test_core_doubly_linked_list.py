import unittest
from test import DoublyLinkedList
from test.test_core_list import test_list

class TestDoublyLinkedList(unittest.TestCase):
    def setUp(self):
        self.list = DoublyLinkedList()

    def test_list(self):
        test_list(self)

