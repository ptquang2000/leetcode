#include "utils/asserts.h"

extern int map_longest_contained_range(int len, int A[len]);

void test_map_longest_contained_range()
{
        int_obj actual = {}, expected = {};

        actual.data = map_longest_contained_range(6, (int[]){3, 4, 2, 1, 100, 200});
        expected.data = 4;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_contained_range(6, (int[]){5, 6, 7, 8, 9, 10});
        expected.data = 6;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_contained_range(4, (int[]){1, 2, 2, 3});
        expected.data = 3;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_contained_range(6, (int[]){10, 30, 20, 11, 21, 12});
        expected.data = 3;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_contained_range(4, (int[]){10, 20, 30, 40});
        expected.data = 1;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_contained_range(5, (int[]){-2, -1, 0, 1, 2});
        expected.data = 5;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_contained_range(0, (int[]){});
        expected.data = 0;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_contained_range(1, (int[]){7});
        expected.data = 1;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_contained_range(6, (int[]){100, 4, 200, 1, 3, 2});
        expected.data = 4;
        ASSERT_EQUAL(actual, expected);

        actual.data = map_longest_contained_range(8, (int[]){10, 5, 3, 12, 4, 2, 100, 6});
        expected.data = 5;
        ASSERT_EQUAL(actual, expected);
}
