#include "utils/asserts.h"

extern int map_longest_subarray_with_distinct_entries(int len, const char *A[len]);

void test_map_longest_subarray_with_distinct_entries()
{
        int_obj actual = {}, expected = {};

        actual.data =
                map_longest_subarray_with_distinct_entries(7, (const char *[]){"a", "b", "c", "a", "b", "c", "d"});
        expected.data = 4;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_subarray_with_distinct_entries(5, (const char *[]){"1", "2", "3", "4", "5"});
        expected.data = 5;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_subarray_with_distinct_entries(3, (const char *[]){"x", "x", "x"});
        expected.data = 1;
        ASSERT_EQUAL(actual, expected);

        actual.data =
                map_longest_subarray_with_distinct_entries(7, (const char *[]){"a", "b", "a", "c", "d", "e", "c"});
        expected.data = 5;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_subarray_with_distinct_entries(0, (const char *[]){});
        expected.data = 0;
        ASSERT_EQUAL(actual, expected);

        actual.data =
                map_longest_subarray_with_distinct_entries(7, (const char *[]){"x", "y", "z", "x", "a", "b", "c"});
        expected.data = 6;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_subarray_with_distinct_entries(5, (const char *[]){"a", "b", "c", "a", "a"});
        expected.data = 3;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_subarray_with_distinct_entries(6, (const char *[]){"1", "2", "3", "2", "4", "5"});
        expected.data = 4;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_subarray_with_distinct_entries(1, (const char *[]){"a"});
        expected.data = 1;
        ASSERT_EQUAL(actual, expected);

        actual.data =
                map_longest_subarray_with_distinct_entries(7, (const char *[]){"a", "a", "b", "c", "d", "a", "a"});
        expected.data = 4;
        ASSERT_EQUAL(actual, expected);
}
