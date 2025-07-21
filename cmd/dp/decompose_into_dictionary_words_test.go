package dp

import (
	"reflect"
	"testing"

	. "leetcode/day"
)

func TestDecomposeIntoDictionaryWords(T *testing.T) {
	var actual, expected []string

	expected = []string{"apple"}
	if actual = DecomposeIntoDictionaryWords("apple", []string{"apple"}); !reflect.DeepEqual(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = []string{"apple", "pie"}
	if actual = DecomposeIntoDictionaryWords("applepie", []string{"apple", "pie"}); !reflect.DeepEqual(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = []string{}
	if actual = DecomposeIntoDictionaryWords("xyz", []string{"a", "b", "c"}); !reflect.DeepEqual(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = []string{}
	if actual = DecomposeIntoDictionaryWords("applepie", []string{"app", "pie"}); !reflect.DeepEqual(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	if actual = DecomposeIntoDictionaryWords("pineapple", []string{"pine", "apple", "pineapple"}); !reflect.DeepEqual(actual, []string{"pine", "apple"}) &&
		!reflect.DeepEqual(actual, []string{"pineapple"}) {
		T.Logf("Expected %v got %v", []([]string){{"pine", "apple"}, []string{"pineapple"}}, actual)
		T.Fail()
	}

	expected = []string{}
	if actual = DecomposeIntoDictionaryWords("", []string{"a", "b"}); !reflect.DeepEqual(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = []string{}
	if actual = DecomposeIntoDictionaryWords("apple", []string{}); !reflect.DeepEqual(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	expected = []string{"apple", "apple"}
	if actual = DecomposeIntoDictionaryWords("appleapple", []string{"apple"}); !reflect.DeepEqual(actual, expected) {
		T.Logf("Expected %v got %v", expected, actual)
		T.Fail()
	}

	if actual = DecomposeIntoDictionaryWords("catsanddog", []string{"cat", "cats", "and", "sand", "dog"}); !reflect.DeepEqual(actual, []string{"cats", "and", "dog"}) &&
		!reflect.DeepEqual(actual, []string{"cat", "sand", "dog"}) {
		T.Logf("Expected %v got %v", []([]string){{"cats", "and", "dog"}, []string{"cat", "sand", "dog"}}, actual)
		T.Fail()
	}
}
