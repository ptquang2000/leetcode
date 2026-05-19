import unittest
from test import generate_balanced_parentheses

class TestGenerateBalancedParentheses(unittest.TestCase):
    def test_generate_balanced_parentheses(self):
        self.assertCountEqual(generate_balanced_parentheses(3), ["((()))","(()())","(())()","()(())","()()()"])
        self.assertCountEqual(generate_balanced_parentheses(2), ["(())", "()()"])
        self.assertCountEqual(generate_balanced_parentheses(1), ["()"])
