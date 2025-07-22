package dp

import (
	"testing"

	. "leetcode/day"
)

func TestMaximumRevenue(T *testing.T) {
	var actual, expected int

	expected = 5
	if actual = MaximumRevenue([]int{5, 3}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 8
	if actual = MaximumRevenue([]int{4, 4, 4, 4}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 15
	if actual = MaximumRevenue([]int{5, 3, 7, 10}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 22
	if actual = MaximumRevenue([]int{8, 15, 3, 7}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 6
	if actual = MaximumRevenue([]int{1, 2, 3, 4}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 18
	if actual = MaximumRevenue([]int{10, 9, 8, 7}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 200
	if actual = MaximumRevenue([]int{100, 1, 100, 1}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 101
	if actual = MaximumRevenue([]int{100, 1, 1, 100}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 42
	if actual = MaximumRevenue([]int{20, 30, 2, 2, 2, 10}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 27
	if actual = MaximumRevenue([]int{6, 9, 1, 2, 16, 8, 3, 4}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = 140
	if actual = MaximumRevenue([]int{25, 5, 10, 5, 10, 5, 10, 25, 1, 25, 1, 25, 1, 25, 5, 10}); actual != expected {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}
}
