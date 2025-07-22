package dp

import (
	"testing"

	. "leetcode/day"
)

func TestNumberOfWaysToTop(T *testing.T) {
	var actual, expected int

	expected = 0
	if actual = NumberOfWays(0, 3); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 1
	if actual = NumberOfWays(1, 2); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 2
	if actual = NumberOfWays(2, 2); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 3
	if actual = NumberOfWays(3, 2); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 7
	if actual = NumberOfWays(4, 3); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 1
	if actual = NumberOfWays(5, 1); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 13
	if actual = NumberOfWays(6, 2); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 24
	if actual = NumberOfWays(6, 3); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 401
	if actual = NumberOfWays(10, 4); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 10609
	if actual = NumberOfWays(20, 5); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
}
