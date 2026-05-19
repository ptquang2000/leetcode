import unittest
from test import replace_and_remove

class TestReplaceAndRemove(unittest.TestCase):
    def test_replace_and_remove(self):
        s = ['a','c','a','a',None,None,None]
        self.assertEqual(replace_and_remove(4, s), 7)
        self.assertEqual(s, ['d','d','c','d','d','d','d'])

        s = ['a','c','d','b','b','c','a']
        self.assertEqual(replace_and_remove(7, s), 7)
        self.assertEqual(s, ['d','d','c','d','c','d','d'])

        s = ['a','b','a','c',None]
        self.assertEqual(replace_and_remove(4, s), 5)
        self.assertEqual(s, ['d','d','d','d','c'])
