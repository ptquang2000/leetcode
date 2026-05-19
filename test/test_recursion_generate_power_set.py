import unittest
from test import generate_power_set

class TestGeneratePowerSet(unittest.TestCase):
    def test_generate_power_set(self):
        self.assertCountEqual(generate_power_set([1,2,3]), [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]])
        self.assertCountEqual(generate_power_set([0]), [[],[0]])
