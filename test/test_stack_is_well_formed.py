import unittest
from test import is_well_formed

class TestIsWellFormed(unittest.TestCase):
    def test_is_well_formed(self):
        self.assertTrue(is_well_formed("()"))
        self.assertTrue(is_well_formed("()[]{}"))
        self.assertTrue(is_well_formed("([]){()}"))
        self.assertTrue(is_well_formed("[()[]{()()}]"))
        self.assertFalse(is_well_formed("(]"))
        self.assertFalse(is_well_formed("{)"))
        self.assertFalse(is_well_formed("[()[]{()()"))
