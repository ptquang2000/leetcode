import unittest
from test import rabin_karp

class TestRabinKarp(unittest.TestCase):
    def test_rabin_karp(self):
        text = "GACGCCA"
        string = "CGC"
        self.assertEqual(rabin_karp(text, string), text.find(string))
        text = "GACGCCA"
        string = "CCA"
        self.assertEqual(rabin_karp(text, string), text.find(string))
        text = "GACGCCA"
        string = "BBA"
        self.assertEqual(rabin_karp(text, string), text.find(string))
        text = "hello how are you?"
        string = "how are"
        self.assertEqual(rabin_karp(text, string), text.find(string))
        text = " hello world is the first code of every programmer"
        string = "first"
        self.assertEqual(rabin_karp(text, string), text.find(string))
