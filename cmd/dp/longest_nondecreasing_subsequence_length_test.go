package dp

import (
	"testing"

	. "leetcode/day"
)

func TestLongestNondecreasingSubsequenceLength(T *testing.T) {
	var actual, expected int

	expected = 4
	if actual = LongestNondecreasingSubsequenceLength([]int{8, 4, 12, 2, 10, 6, 14, 1, 9}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 5
	if actual = LongestNondecreasingSubsequenceLength([]int{1, 2, 3, 4, 5}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 1
	if actual = LongestNondecreasingSubsequenceLength([]int{5, 4, 3, 2, 1}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 4
	if actual = LongestNondecreasingSubsequenceLength([]int{3, 3, 3, 3}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 4
	if actual = LongestNondecreasingSubsequenceLength([]int{1, 3, 2, 4, 3, 5}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 1
	if actual = LongestNondecreasingSubsequenceLength([]int{7}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 5
	if actual = LongestNondecreasingSubsequenceLength([]int{-2, -1, 0, 1, 2}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 4
	if actual = LongestNondecreasingSubsequenceLength([]int{1, 3, 2, 4, 3, 5, 2}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 4
	if actual = LongestNondecreasingSubsequenceLength([]int{1, 2, 2, 1, 3}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 4
	if actual = LongestNondecreasingSubsequenceLength([]int{10, 20, 10, 30, 20, 50}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 0
	if actual = LongestNondecreasingSubsequenceLength([]int{}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
}
