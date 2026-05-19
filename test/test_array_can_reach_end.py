import unittest
from test import can_reach_end

class TestCanReachEnd(unittest.TestCase):
    def test_can_reach_end(self):
        self.assertTrue(can_reach_end([2,4,1,1,0,2,3]))
        self.assertTrue(can_reach_end([3,3,7,0,2,0,1]))
        self.assertFalse(can_reach_end([3,2,0,0,2,0,7]))
