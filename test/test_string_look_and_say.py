import unittest 
from test import look_and_say

class TestLookAndSay(unittest.TestCase):
    def test_look_and_say(self):
        self.assertEqual(look_and_say(8), "1113213211")
