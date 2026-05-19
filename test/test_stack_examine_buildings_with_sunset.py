import unittest
from test import examine_buildings_with_sunset

class TestExamineBuildingsWithSunset(unittest.TestCase):
    def test_examine_buildings_with_sunset(self):
        self.assertEqual(examine_buildings_with_sunset([15,14,13,12,11]), [4,3,2,1,0])
        self.assertEqual(examine_buildings_with_sunset([9,2,8,4,7]), [4,2,0])
