#include "utils/asserts.h"

extern int *map_find_all_substrings(const char *s, int wlen, const char *wors[wlen], int *o_len);

void test_map_find_all_substrings()
{
        int_array actual = {}, expected = {};

        actual.data = map_find_all_substrings("barfoothefoobarman", 2, (const char *[]){"foo", "bar"}, &actual.len);
        expected = (int_array){.data = (int[]){0, 9}, .len = 2};
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_all_substrings("wordgoodgoodgoodbestword", 4,
                                              (const char *[]){"word", "good", "best", "good"}, &actual.len);
        expected = (int_array){.data = (int[]){8}, .len = 1};
        ASSERT_EQUAL(actual, expected);

        actual.data =
                map_find_all_substrings("barfoofoobarthefoobarman", 2, (const char *[]){"xyz", "abc"}, &actual.len);
        expected = (int_array){.data = (int[]){}, .len = 0};
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_all_substrings("barfoofoobarthefoobarman", 3, (const char *[]){"foo", "bar", "foo"},
                                              &actual.len);
        expected = (int_array){.data = (int[]){0, 3}, .len = 2};
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_all_substrings("catdogmouse", 3, (const char *[]){"cat", "dog", "mouse"}, &actual.len);
        expected = (int_array){.data = (int[]){0}, .len = 1};
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_all_substrings("", 2, (const char *[]){"a", "b"}, &actual.len);
        expected = (int_array){.data = (int[]){}, .len = 0};
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_all_substrings("something", 0, (const char *[]){}, &actual.len);
        expected = (int_array){.data = (int[]){}, .len = 0};
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_all_substrings("foobarbaz", 3, (const char *[]){"foo", "bar", "ba"}, &actual.len);
        expected = (int_array){.data = (int[]){}, .len = 0};
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_all_substrings("foobarfoobar", 3, (const char *[]){"foo", "bar", "foo"}, &actual.len);
        expected = (int_array){.data = (int[]){0}, .len = 1};
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_all_substrings("aaaabaaaabaa", 2, (const char *[]){"aa", "ab"}, &actual.len);
        expected = (int_array){.data = (int[]){2}, .len = 1};
        ASSERT_EQUAL(actual, expected);

        actual.data = map_find_all_substrings("lingmindraboofooowingdingbarrwingmonkeypoundcake", 5,
                                              (const char *[]){"fooo", "barr", "wing", "ding", "wing"}, &actual.len);
        expected = (int_array){.data = (int[]){13}, .len = 1};
        ASSERT_EQUAL(actual, expected);
}
