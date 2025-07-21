package dp

import (
	"testing"

	. "leetcode/day"
)

func TestOptimumSubjectToCapacity(T *testing.T) {
	var actual, expected int

	expected = 7
	if actual = OptimumSubjectToCapacity([]struct {
		Capacity int
		Value    int
	}{
		{Capacity: 2, Value: 3},
		{Capacity: 3, Value: 4},
		{Capacity: 4, Value: 5},
		{Capacity: 5, Value: 6},
	}, 5); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 22
	if actual = OptimumSubjectToCapacity([]struct {
		Capacity int
		Value    int
	}{
		{Capacity: 1, Value: 6},
		{Capacity: 2, Value: 10},
		{Capacity: 3, Value: 12},
	}, 5); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 0
	if actual = OptimumSubjectToCapacity([]struct {
		Capacity int
		Value    int
	}{
		{Capacity: 1, Value: 10},
		{Capacity: 2, Value: 20},
		{Capacity: 3, Value: 30},
	}, 0); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 20
	if actual = OptimumSubjectToCapacity([]struct {
		Capacity int
		Value    int
	}{
		{Capacity: 5, Value: 10},
		{Capacity: 6, Value: 20},
		{Capacity: 7, Value: 30},
	}, 6); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 60
	if actual = OptimumSubjectToCapacity([]struct {
		Capacity int
		Value    int
	}{
		{Capacity: 1, Value: 10},
		{Capacity: 1, Value: 20},
		{Capacity: 1, Value: 30},
	}, 3); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 0
	if actual = OptimumSubjectToCapacity([]struct {
		Capacity int
		Value    int
	}{
		{Capacity: 10, Value: 100},
		{Capacity: 20, Value: 200},
		{Capacity: 30, Value: 300},
	}, 5); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 22
	if actual = OptimumSubjectToCapacity([]struct {
		Capacity int
		Value    int
	}{
		{Capacity: 1, Value: 6},
		{Capacity: 2, Value: 10},
		{Capacity: 3, Value: 12},
	}, 5); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}

	expected = 695
	if actual = OptimumSubjectToCapacity([]struct {
		Capacity int
		Value    int
	}{
		{Capacity: 20, Value: 65},
		{Capacity: 8, Value: 35},
		{Capacity: 60, Value: 245},
		{Capacity: 55, Value: 195},
		{Capacity: 40, Value: 65},
		{Capacity: 70, Value: 150},
		{Capacity: 85, Value: 275},
		{Capacity: 25, Value: 155},
		{Capacity: 30, Value: 120},
		{Capacity: 65, Value: 320},
		{Capacity: 75, Value: 75},
		{Capacity: 10, Value: 40},
		{Capacity: 95, Value: 200},
		{Capacity: 50, Value: 100},
		{Capacity: 40, Value: 220},
		{Capacity: 10, Value: 99},
	}, 130); actual != expected {
		T.Logf("Expected %d got %d", expected, actual)
		T.Fail()
	}
}
