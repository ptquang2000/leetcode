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

	expected = 9
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
}
