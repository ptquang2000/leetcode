package dp

import (
	"slices"
	"testing"

	. "leetcode/day"
)

func TestDecomposeIntoDictionaryWords(T *testing.T) {
	var actual, expected []string

	expected = []string{"apple"}
	if actual = DecomposeIntoDictionaryWords("apple", []string{"apple"}); !slices.Equal(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = []string{"apple", "pie"}
	if actual = DecomposeIntoDictionaryWords("applepie", []string{"apple", "pie"}); !slices.Equal(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = []string{}
	if actual = DecomposeIntoDictionaryWords("xyz", []string{"a", "b", "c"}); !slices.Equal(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = []string{}
	if actual = DecomposeIntoDictionaryWords("applepie", []string{"app", "pie"}); !slices.Equal(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	if actual = DecomposeIntoDictionaryWords("pineapple", []string{"pine", "apple", "pineapple"}); !slices.Equal(actual, []string{"pine", "apple"}) &&
		!slices.Equal(actual, []string{"pineapple"}) {
		T.Logf("Expected %v got %v", []([]string){{"pine", "apple"}, []string{"pineapple"}}, actual)
		T.Fail()
	}

	expected = []string{}
	if actual = DecomposeIntoDictionaryWords("", []string{"a", "b"}); !slices.Equal(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = []string{}
	if actual = DecomposeIntoDictionaryWords("apple", []string{}); !slices.Equal(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = []string{"apple", "apple"}
	if actual = DecomposeIntoDictionaryWords("appleapple", []string{"apple"}); !slices.Equal(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	if actual = DecomposeIntoDictionaryWords("catsanddog", []string{"cat", "cats", "and", "sand", "dog"}); !slices.Equal(actual, []string{"cats", "and", "dog"}) &&
		!slices.Equal(actual, []string{"cat", "sand", "dog"}) {
		T.Logf("Expected %v got %v", []([]string){{"cats", "and", "dog"}, []string{"cat", "sand", "dog"}}, actual)
		T.Fail()
	}
}
