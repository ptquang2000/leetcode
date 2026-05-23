import unittest
from test import (
    evaluate,
    examine_buildings_with_sunset,
    is_well_formed,
    shortest_equivalent_path,
)


class TestStack(unittest.TestCase):
    def test_evaluate(self):
        self.assertEqual(evaluate(["2","1","+","3","*"]), 9)
        self.assertEqual(evaluate(["4","13","5","/","+"]), 6)
        self.assertEqual(evaluate(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]), 22)

    def test_examine_buildings_with_sunset(self):
        self.assertEqual(examine_buildings_with_sunset([15,14,13,12,11]), [4,3,2,1,0])
        self.assertEqual(examine_buildings_with_sunset([9,2,8,4,7]), [4,2,0])

    def test_is_well_formed(self):
        self.assertTrue(is_well_formed("()"))
        self.assertTrue(is_well_formed("()[]{}"))
        self.assertTrue(is_well_formed("([]){()}"))
        self.assertTrue(is_well_formed("[()[]{()()}]"))
        self.assertFalse(is_well_formed("(]"))
        self.assertFalse(is_well_formed("{)"))
        self.assertFalse(is_well_formed("[()[]{()()"))

    def test_shortest_equivalent_path(self):
        self.assertEqual(shortest_equivalent_path("/home/"), "/home")
        self.assertEqual(shortest_equivalent_path("/../"), "/")
        self.assertEqual(shortest_equivalent_path("/home//foo/"), "/home/foo")
        self.assertEqual(shortest_equivalent_path("sc//./../tc/awk/././"), "tc/awk")
        self.assertEqual(shortest_equivalent_path("/usr/lib/../bin/gcc"), "/usr/bin/gcc")
        self.assertEqual(shortest_equivalent_path("scripts//./../scripts/awkscripts/././"), "scripts/awkscripts")
