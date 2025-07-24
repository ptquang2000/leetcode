package dp

import (
	"testing"

	. "leetcode/day"
)

func TestMinimumMessiness(T *testing.T) {
	var actual, expected int

	expected = 4
	if actual = MinimumMessiness([]string{"a", "b", "c"}, 3); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 13
	if actual = MinimumMessiness([]string{"aaa", "bb", "c"}, 6); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 13
	if actual = MinimumMessiness([]string{"a", "ab", "abc"}, 6); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 25
	if actual = MinimumMessiness([]string{"word", "wrap", "test"}, 9); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 8
	if actual = MinimumMessiness([]string{"longword", "tiny", "fit"}, 10); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 4
	if actual = MinimumMessiness([]string{"Go", "is", "fun"}, 11); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 4
	if actual = MinimumMessiness([]string{"a", "b", "c", "d", "e"}, 3); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 26
	if actual = MinimumMessiness([]string{"hello", "world", "a", "b"}, 10); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 0
	if actual = MinimumMessiness([]string{"a", "b", "c"}, 5); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 36
	if actual = MinimumMessiness([]string{"aaa", "bbb", "c", "d", "ee", "ff", "ggggggg"}, 11); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
}
