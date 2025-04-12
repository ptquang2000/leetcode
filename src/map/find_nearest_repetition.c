#include "utils/asserts.h"

extern int map_find_nearest_repetition(int len, const char *paragraph[len]);

void test_map_find_nearest_repetition()
{
        int_obj actual = {}, expected = {};

        actual.data =
                map_find_nearest_repetition(14, (const char *[]){"All", "work", "and", "no", "play", "makes", "for",
                                                                 "nor", "work", "no", "fun", "and", "no", "results"});
        expected.data = 2;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_nearest_repetition(6, (const char *[]){"a", "b", "c", "a", "d", "b"});
        expected.data = 3;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_nearest_repetition(5, (const char *[]){"x", "y", "z", "x", "x"});
        expected.data = 1;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_nearest_repetition(3, (const char *[]){"one", "two", "three"});
        expected.data = -1;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_nearest_repetition(
                6, (const char *[]){"apple", "banana", "apple", "orange", "banana", "apple"});
        expected.data = 2;
        ASSERT_EQUAL(actual, expected);
}
