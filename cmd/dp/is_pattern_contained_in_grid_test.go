package dp

import (
	"testing"

	. "leetcode/day"
)

func TestIsPatternContainedInGrid(T *testing.T) {
	var actual, expected bool

	expected = true
	if actual = IsPatternContainedInGrid([][]int{
		{1, 2, 3},
		{4, 5, 6},
	}, []int{2, 3, 6}); actual != expected {
		T.Logf("Expected %t got %t", expected, actual)
		T.Fail()
	}

	expected = true
	if actual = IsPatternContainedInGrid([][]int{
		{7, 2},
		{6, 3},
		{5, 4},
	}, []int{2, 3, 4}); actual != expected {
		T.Logf("Expected %t got %t", expected, actual)
		T.Fail()
	}

	expected = true
	if actual = IsPatternContainedInGrid([][]int{
		{1, 2, 3},
	}, []int{1, 2, 1}); actual != expected {
		T.Logf("Expected %t got %t", expected, actual)
		T.Fail()
	}

	expected = false
	if actual = IsPatternContainedInGrid([][]int{
		{1, 2},
		{3, 4},
	}, []int{1, 4, 3}); actual != expected {
		T.Logf("Expected %t got %t", expected, actual)
		T.Fail()
	}

	expected = true
	if actual = IsPatternContainedInGrid([][]int{
		{9},
	}, []int{9}); actual != expected {
		T.Logf("Expected %t got %t", expected, actual)
		T.Fail()
	}

	expected = false
	if actual = IsPatternContainedInGrid([][]int{}, []int{1, 2}); actual != expected {
		T.Logf("Expected %t got %t", expected, actual)
		T.Fail()
	}

	expected = true
	if actual = IsPatternContainedInGrid([][]int{
		{1, 2},
	}, []int{}); actual != expected {
		T.Logf("Expected %t got %t", expected, actual)
		T.Fail()
	}

	expected = true
	if actual = IsPatternContainedInGrid([][]int{
		{1, 2, 3},
		{3, 4, 5},
		{5, 6, 7},
	}, []int{1, 3, 4, 6}); actual != expected {
		T.Logf("Expected %t got %t", expected, actual)
		T.Fail()
	}
}
