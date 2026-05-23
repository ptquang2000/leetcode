import unittest
from test import (
    can_perform_palindrome,
    find_all_substrings,
    find_nearest_repetition,
    find_smallest_sequentially_covering_set,
    find_smallest_subarray_covering_set,
    is_letter_constructible_from_magazine,
    longest_contained_range,
    longest_subarray_with_distinct_entries,
    test_collatz_conjecture,
)


class TestMap(unittest.TestCase):
    def test_can_perform_palindrome(self):
        self.assertFalse(can_perform_palindrome('travel'))
        self.assertTrue(can_perform_palindrome('deified'))
        self.assertTrue(can_perform_palindrome(''))
        self.assertTrue(can_perform_palindrome('a'))
        self.assertTrue(can_perform_palindrome('aabb'))
        self.assertTrue(can_perform_palindrome('aabbc'))
        self.assertFalse(can_perform_palindrome('abc'))
        self.assertTrue(can_perform_palindrome('aaaaaa'))
        self.assertFalse(can_perform_palindrome('AaBb'))
        self.assertTrue(can_perform_palindrome('taco cat'))
        self.assertTrue(can_perform_palindrome('@@##!!@@##!!'))

    def test_find_all_substrings(self):
        self.assertCountEqual(find_all_substrings('barfoothefoobarman', ['foo', 'bar']), [0, 9])
        self.assertCountEqual(
            find_all_substrings('wordgoodgoodgoodbestword', ['word', 'good', 'best', 'good']), [8]
        )
        self.assertCountEqual(find_all_substrings('barfoofoobarthefoobarman', ['xyz', 'abc']), [])
        self.assertCountEqual(find_all_substrings('barfoofoobarthefoobarman', ['foo', 'bar', 'foo']), [0, 3])
        self.assertCountEqual(find_all_substrings('catdograt', ['cat', 'dog', 'rat']), [0])
        self.assertCountEqual(find_all_substrings('', ['a', 'b']), [])
        self.assertCountEqual(find_all_substrings('something', []), [])
        self.assertCountEqual(find_all_substrings('foobarbaz', ['foo', 'bar', 'bat']), [])
        self.assertCountEqual(find_all_substrings('foobarfoobar', ['foo', 'bar', 'foo']), [0])
        self.assertCountEqual(find_all_substrings('aaaabaaaabaa', ['aa', 'ab']), [1, 3, 6, 8])
        self.assertCountEqual(
            find_all_substrings('lingmindraboofooowingdingbarrwingmonkeypoundcake',
                                ['fooo', 'barr', 'wing', 'ding', 'wing']),
            [13],
        )

    def test_find_nearest_repetition(self):
        self.assertEqual(
            find_nearest_repetition(['All', 'work', 'and', 'no', 'play', 'makes', 'for',
                                     'no', 'work', 'no', 'fun', 'and', 'no', 'results']), 2
        )
        self.assertEqual(find_nearest_repetition(['a', 'b', 'c', 'a', 'd', 'b']), 3)
        self.assertEqual(find_nearest_repetition(['x', 'y', 'z', 'x', 'x']), 1)
        self.assertEqual(find_nearest_repetition(['one', 'two', 'three']), -1)
        self.assertEqual(
            find_nearest_repetition(['apple', 'banana', 'apple', 'orange', 'banana', 'apple']), 2
        )

    def test_find_smallest_sequentially_covering_set(self):
        self.assertEqual(
            find_smallest_sequentially_covering_set(['x', 'a', 'y', 'b', 'z', 'c', 'd'], ['a', 'b', 'c']),
            [1, 5],
        )
        self.assertEqual(
            find_smallest_sequentially_covering_set(['a', 'x', 'b', 'c', 'a', 'b', 'c'], ['a', 'b', 'c']),
            [4, 6],
        )
        self.assertEqual(
            find_smallest_sequentially_covering_set(['a', 'b', 'c', 'd'], ['b', 'a']),
            [-1, -1],
        )
        self.assertEqual(
            find_smallest_sequentially_covering_set(['a', 'x', 'y', 'z'], ['a', 'b']),
            [-1, -1],
        )
        self.assertEqual(
            find_smallest_sequentially_covering_set(['a', 'b', 'c', 'd', 'e'], ['a', 'b', 'c']),
            [0, 2],
        )
        self.assertEqual(
            find_smallest_sequentially_covering_set(['x', 'y', 'target', 'z'], ['target']),
            [2, 2],
        )
        self.assertEqual(
            find_smallest_sequentially_covering_set(['x', 'y', 'a', 'b', 'c'], ['a', 'b', 'c']),
            [2, 4],
        )
        self.assertEqual(
            find_smallest_sequentially_covering_set(['a', 'x', 'x', 'b', 'x', 'c', 'd'], ['a', 'b', 'c']),
            [0, 5],
        )
        self.assertEqual(
            find_smallest_sequentially_covering_set(['a', 'b', 'a', 'b', 'c'], ['a', 'b', 'c']),
            [2, 4],
        )

    def test_find_smallest_subarray_covering_set(self):
        self.assertEqual(
            find_smallest_subarray_covering_set(['a', 'b', 'c', 'a', 'e', 'b', 'c'], ['b', 'c', 'e']),
            [4, 6],
        )
        self.assertIn(
            find_smallest_subarray_covering_set(['x', 'b', 'c', 'e', 'a', 'b', 'c', 'e', 'z'], ['b', 'c', 'e']),
            [[1, 3], [5, 7]],
        )
        self.assertEqual(
            find_smallest_subarray_covering_set(['a', 'b', 'c'], ['x', 'y']),
            [-1, -1],
        )
        self.assertEqual(
            find_smallest_subarray_covering_set(['a', 'b', 'c'], ['a', 'b', 'c']),
            [0, 2],
        )
        self.assertEqual(
            find_smallest_subarray_covering_set(['z', 'y', 'x', 'w'], ['x']),
            [2, 2],
        )
        self.assertEqual(
            find_smallest_subarray_covering_set(['m', 'n', 'o', 'p'], ['m', 'n', 'o', 'p']),
            [0, 3],
        )
        self.assertEqual(
            find_smallest_subarray_covering_set(['a', 'x', 'b', 'x', 'c', 'x', 'e'], ['b', 'c', 'e']),
            [2, 6],
        )

    def test_is_letter_constructible_from_magazine(self):
        self.assertFalse(is_letter_constructible_from_magazine('a', 'b'))
        self.assertFalse(is_letter_constructible_from_magazine('aa', 'ab'))
        self.assertTrue(is_letter_constructible_from_magazine('aa', 'aab'))
        self.assertTrue(is_letter_constructible_from_magazine('hello friend', 'hello old friend from school'))
        self.assertFalse(is_letter_constructible_from_magazine('help me', 'some random phrase'))
        self.assertTrue(is_letter_constructible_from_magazine('dear friend', 'dear old friend from school'))
        self.assertTrue(is_letter_constructible_from_magazine('hello', 'hello'))

    def test_longest_contained_range(self):
        self.assertEqual(longest_contained_range([3, 4, 2, 1, 100, 200]), 4)
        self.assertEqual(longest_contained_range([5, 6, 7, 8, 9, 10]), 6)
        self.assertEqual(longest_contained_range([1, 2, 2, 3]), 3)
        self.assertEqual(longest_contained_range([10, 30, 20, 11, 21, 12]), 3)
        self.assertEqual(longest_contained_range([10, 20, 30, 40]), 1)
        self.assertEqual(longest_contained_range([-2, -1, 0, 1, 2]), 5)
        self.assertEqual(longest_contained_range([]), 0)
        self.assertEqual(longest_contained_range([7]), 1)
        self.assertEqual(longest_contained_range([100, 4, 200, 1, 3, 2]), 4)
        self.assertEqual(longest_contained_range([10, 5, 3, 12, 4, 2, 100, 6]), 5)

    def test_longest_subarray_with_distinct_entries(self):
        self.assertEqual(longest_subarray_with_distinct_entries(['a', 'b', 'c', 'a', 'b', 'c', 'd']), 4)
        self.assertEqual(longest_subarray_with_distinct_entries(['1', '2', '3', '4', '5']), 5)
        self.assertEqual(longest_subarray_with_distinct_entries(['x', 'x', 'x']), 1)
        self.assertEqual(longest_subarray_with_distinct_entries(['a', 'b', 'a', 'c', 'd', 'e', 'c']), 5)
        self.assertEqual(longest_subarray_with_distinct_entries([]), 0)
        self.assertEqual(longest_subarray_with_distinct_entries(['x', 'y', 'z', 'x', 'a', 'b', 'c']), 6)
        self.assertEqual(longest_subarray_with_distinct_entries(['a', 'b', 'c', 'a', 'a']), 3)
        self.assertEqual(longest_subarray_with_distinct_entries(['1', '2', '3', '2', '4', '5']), 4)
        self.assertEqual(longest_subarray_with_distinct_entries(['a']), 1)
        self.assertEqual(longest_subarray_with_distinct_entries(['a', 'a', 'b', 'c', 'd', 'a', 'a']), 4)

    def test_collatz_conjecture(self):
        self.assertTrue(test_collatz_conjecture(1))
        self.assertTrue(test_collatz_conjecture(2))
        self.assertTrue(test_collatz_conjecture(3))
        self.assertTrue(test_collatz_conjecture(27))
        self.assertTrue(test_collatz_conjecture(64))
        self.assertTrue(test_collatz_conjecture(1000000))
        self.assertFalse(test_collatz_conjecture(0))
        self.assertFalse(test_collatz_conjecture(-5))
        self.assertTrue(test_collatz_conjecture(10000000))
