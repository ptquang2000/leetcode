package dp

import (
	"testing"

	. "leetcode/day"
)

func TestNumberOfWaysToTopToTop(T *testing.T) {
	var actual, expected int

	expected = 0
	if actual = NumberOfWaysToTop(0, 3); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 1
	if actual = NumberOfWaysToTop(1, 2); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 2
	if actual = NumberOfWaysToTop(2, 2); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 3
	if actual = NumberOfWaysToTop(3, 2); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 7
	if actual = NumberOfWaysToTop(4, 3); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 1
	if actual = NumberOfWaysToTop(5, 1); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 13
	if actual = NumberOfWaysToTop(6, 2); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 24
	if actual = NumberOfWaysToTop(6, 3); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 401
	if actual = NumberOfWaysToTop(10, 4); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 10609
	if actual = NumberOfWaysToTop(20, 5); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
}
