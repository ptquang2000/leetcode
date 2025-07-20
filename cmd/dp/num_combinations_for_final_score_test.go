package dp

import (
	"testing"

	. "leetcode/day"
)

func TestNumCombinationsForFinalScore(T *testing.T) {
	var actual, expected int

	expected = 4
	if actual = NumCombinationsForFinalScore(12, []int{2, 3, 7}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 2
	if actual = NumCombinationsForFinalScore(7, []int{2, 3, 6, 7}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
	expected = 1
	if actual = NumCombinationsForFinalScore(9, []int{3}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
	expected = 0
	if actual = NumCombinationsForFinalScore(3, []int{5, 10}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
	expected = 4
	if actual = NumCombinationsForFinalScore(8, []int{2, 3, 5}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
	expected = 0
	if actual = NumCombinationsForFinalScore(5, []int{}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
	expected = 10
	if actual = NumCombinationsForFinalScore(8, []int{1, 3, 4}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
	expected = 0
	if actual = NumCombinationsForFinalScore(5, []int{10, 20, 30}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
	expected = 30
	if actual = NumCombinationsForFinalScore(10, []int{2, 3, 7}); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
}
