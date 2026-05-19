import unittest
from test import reverse_words

class TestReverseWords(unittest.TestCase):
    def test_reverse_words(self):
        s = ['A','l','i','c','e',' ','l','i','k','e','s',' ','B','o','b']
        reverse_words(s)
        self.assertEqual(s, ['B','o','b',' ','l','i','k','e','s',' ','A','l','i','c','e'])
        s = ['r','a','m',' ','i','s',' ','c','o','s','t','l','y']
        reverse_words(s)
        self.assertEqual(s, ['c','o','s','t','l','y',' ','i','s',' ','r','a','m'])
