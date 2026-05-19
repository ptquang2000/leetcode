import unittest
from test import evaluate

class TestEvaluate(unittest.TestCase):
    def test_evaluate(self):
        self.assertEqual(evaluate(["2","1","+","3","*"]), 9)
        self.assertEqual(evaluate(["4","13","5","/","+"]), 6)
        self.assertEqual(evaluate(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]), 22)
