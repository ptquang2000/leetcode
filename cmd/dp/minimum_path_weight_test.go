package dp

import (
	"testing"

	. "leetcode/day"
)

func TestMinimumPathWeight(T *testing.T) {
	var actual, expected int

	expected = 11
	if actual = MinimumPathWeight([][]int{
		{2},
		{3, 4},
		{6, 5, 7},
		{4, 1, 8, 3},
	}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 3
	if actual = MinimumPathWeight([][]int{
		{1},
		{1, 1},
		{1, 1, 1},
	}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 10
	if actual = MinimumPathWeight([][]int{
		{10},
	}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 7
	if actual = MinimumPathWeight([][]int{
		{1},
		{2, 3},
		{4, 5, 6},
	}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 8
	if actual = MinimumPathWeight([][]int{
		{5},
		{4, 3},
		{2, 1, 0},
	}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = -1
	if actual = MinimumPathWeight([][]int{
		{-1},
		{2, 3},
		{1, -1, -3},
	}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 0
	if actual = MinimumPathWeight([][]int{}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}
}
