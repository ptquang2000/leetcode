import unittest
from test import delete_duplicates

class TestDeleteDuplicates(unittest.TestCase):
    def test_delete_duplicates(self):
        A = [2,3,5,5,7,11,11,11,13]
        self.assertEqual(delete_duplicates(A), 6)
        self.assertEqual(A[:6], [2,3,5,7,11,13])
