#include "utils/asserts.h"

extern int *map_find_smallest_sequentially_covering_set(int plen, const char *paragraph[plen], int klen,
                                                        const char *keywords[klen]);

void test_map_find_smallest_sequentially_covering_set()
{
        int_array actual = {.len = 2}, expected = {.len = 2};

        actual.data = map_find_smallest_sequentially_covering_set(
                7, (const char *[]){"x", "a", "y", "b", "z", "c", "d"}, 3, (const char *[]){"a", "b", "c"});
        expected.data = (int[]){1, 5};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        actual.data = map_find_smallest_sequentially_covering_set(
                7, (const char *[]){"a", "x", "b", "c", "a", "b", "c"}, 3, (const char *[]){"a", "b", "c"});
        expected.data = (int[]){4, 6};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        actual.data = map_find_smallest_sequentially_covering_set(4, (const char *[]){"a", "b", "c", "d"}, 2,
                                                                  (const char *[]){"b", "a"});
        expected.data = (int[]){-1, -1};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        actual.data = map_find_smallest_sequentially_covering_set(4, (const char *[]){"a", "x", "y", "z"}, 2,
                                                                  (const char *[]){"a", "b"});
        expected.data = (int[]){-1, -1};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        actual.data = map_find_smallest_sequentially_covering_set(5, (const char *[]){"a", "b", "c", "d", "e"}, 3,
                                                                  (const char *[]){"a", "b", "c"});
        expected.data = (int[]){0, 2};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        actual.data = map_find_smallest_sequentially_covering_set(4, (const char *[]){"x", "y", "target", "z"}, 1,
                                                                  (const char *[]){"target"});
        expected.data = (int[]){2, 2};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        actual.data = map_find_smallest_sequentially_covering_set(5, (const char *[]){"x", "y", "a", "b", "c"}, 3,
                                                                  (const char *[]){"a", "b", "c"});
        expected.data = (int[]){2, 4};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        actual.data = map_find_smallest_sequentially_covering_set(
                7, (const char *[]){"a", "x", "x", "b", "x", "c", "d"}, 3, (const char *[]){"a", "b", "c"});
        expected.data = (int[]){0, 5};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        actual.data = map_find_smallest_sequentially_covering_set(5, (const char *[]){"a", "b", "a", "b", "c"}, 3,
                                                                  (const char *[]){"a", "b", "c"});
        expected.data = (int[]){2, 4};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);
}
