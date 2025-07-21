package dp

import (
	"testing"

	. "leetcode/day"
)

func TestNumberOfWays(T *testing.T) {
	var actual, expected int

	expected = 1
	if actual = NumberOfWays(1, 1); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 1
	if actual = NumberOfWays(1, 5); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 1
	if actual = NumberOfWays(4, 1); actual != expected {
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

	expected = 6
	if actual = NumberOfWays(3, 3); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 10
	if actual = NumberOfWays(4, 3); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 70
	if actual = NumberOfWays(5, 5); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 48620
	if actual = NumberOfWays(10, 10); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	//expected = 137846528820
	//if actual = NumberOfWays(20, 20); actual != expected {
	//	T.Logf("Expected %d got %d", expected, actual)
	//	T.Fail()
	//}
}
