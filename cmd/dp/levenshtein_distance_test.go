package dp

import (
	"strings"
	"testing"

	. "leetcode/day"
)

func TestLevenshteinDistance(T *testing.T) {
	var actual, expected int

	expected = 0
	if actual = LevenshteinDistance("kitten", "kitten"); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 1
	if actual = LevenshteinDistance("kitten", "sitten"); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 1
	if actual = LevenshteinDistance("kitten", "kittenc"); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 1
	if actual = LevenshteinDistance("kitten", "kittn"); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 3
	if actual = LevenshteinDistance("abc", "xyz"); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 0
	if actual = LevenshteinDistance("", ""); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 3
	if actual = LevenshteinDistance("abc", ""); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 3
	if actual = LevenshteinDistance("", "abc"); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 5
	if actual = LevenshteinDistance("intention", "execution"); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 1
	if actual = LevenshteinDistance(strings.Repeat("a", 100), strings.Repeat("a", 99)); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 4
	if actual = LevenshteinDistance("Saturday", "Sundays"); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 8
	if actual = LevenshteinDistance("Carthorse", "Orchestra"); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
}
