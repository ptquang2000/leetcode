import unittest
from test import plus_one

class TestPlusOne(unittest.TestCase):
    def test_plus_one(self):
        self.assertEqual(plus_one([1,2,9]), [1,3,0])
        self.assertEqual(plus_one([9,9,9]), [1,0,0,0])
