import unittest
from test import ss_decode_col_id

class TestSSDecodeColId(unittest.TestCase):
    def test_ss_decode_col_id(self):
        self.assertEqual(ss_decode_col_id("D"), 4)
        self.assertEqual(ss_decode_col_id("AA"), 27)
        self.assertEqual(ss_decode_col_id("ZZ"), 702)
        
