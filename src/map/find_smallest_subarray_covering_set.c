#include "utils/asserts.h"

extern void map_find_smallest_subarray_covering_set(int plen, const char *paragraph[plen], int klen,
                                                    const char *keywords[klen], int (**r)[2]);

void test_map_find_smallest_subarray_covering_set()
{
        int_array actual = {.len = 2}, expected = {.len = 2};

        map_find_smallest_subarray_covering_set(7, (const char *[]){"a", "b", "c", "a", "e", "b", "c"}, 3,
                                                (const char *[]){"b", "c", "e"}, (int(**)[2])(&actual.data));
        expected.data = (int[]){4, 6};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        map_find_smallest_subarray_covering_set(9, (const char *[]){"x", "b", "c", "e", "a", "b", "c", "e", "z"}, 3,
                                                (const char *[]){"b", "c", "e"}, (int(**)[2])(&actual.data));
        expected.data = (int[]){1, 3};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        map_find_smallest_subarray_covering_set(3, (const char *[]){"a", "b", "c"}, 2, (const char *[]){"x", "y"},
                                                (int(**)[2])(&actual.data));
        expected.data = (int[]){-1, -1};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        map_find_smallest_subarray_covering_set(3, (const char *[]){"a", "b", "c"}, 3, (const char *[]){"a", "b", "c"},
                                                (int(**)[2])(&actual.data));
        expected.data = (int[]){0, 2};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        map_find_smallest_subarray_covering_set(4, (const char *[]){"z", "y", "x", "w"}, 1, (const char *[]){"x"},
                                                (int(**)[2])(&actual.data));
        expected.data = (int[]){2, 2};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        map_find_smallest_subarray_covering_set(10, (const char *[]){"a", "b", "a", "c", "e", "b", "c", "e", "b", "c"},
                                                3, (const char *[]){"b", "c", "e"}, (int(**)[2])(&actual.data));
        _Container c = {(void *[]){
                                &(int_array){(int[]){3, 5}, 2},
                                &(int_array){(int[]){4, 6}, 2},
                                &(int_array){(int[]){5, 7}, 2},
                                &(int_array){(int[]){6, 8}, 2},
                                &(int_array){(int[]){7, 9}, 2},
                        },
                        5};
        ASSERT_IN(actual, c);
        free(actual.data);

        map_find_smallest_subarray_covering_set(4, (const char *[]){"m", "n", "o", "p"}, 4,
                                                (const char *[]){"m", "n", "o", "p"}, (int(**)[2])(&actual.data));
        expected.data = (int[]){0, 3};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);

        map_find_smallest_subarray_covering_set(7, (const char *[]){"a", "x", "b", "x", "c", "x", "e"}, 3,
                                                (const char *[]){"b", "c", "e"}, (int(**)[2])(&actual.data));
        expected.data = (int[]){2, 6};
        ASSERT_EQUAL(actual, expected);
        free(actual.data);
}
