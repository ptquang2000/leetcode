import unittest
from test import generate_primes

class TestGeneratePrimes(unittest.TestCase):
    def test_generate_primes(self):
        self.assertEqual(generate_primes(18), [2,3,5,7,11,13,17])
