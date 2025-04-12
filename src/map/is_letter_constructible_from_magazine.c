#include "utils/asserts.h"

extern bool map_is_letter_constructible_from_magazine(const char *letter, const char *magazine);

void test_map_is_letter_constructible_from_magazine()
{
        ASSERT_FALSE(map_is_letter_constructible_from_magazine("a", "b"));
        ASSERT_FALSE(map_is_letter_constructible_from_magazine("aa", "ab"));
        ASSERT_TRUE(map_is_letter_constructible_from_magazine("aa", "aab"));
        ASSERT_TRUE(map_is_letter_constructible_from_magazine("hello friend", "hello old friend from school"));
        ASSERT_FALSE(map_is_letter_constructible_from_magazine("help me", "some random phrase"));
        ASSERT_TRUE(map_is_letter_constructible_from_magazine("dear_friend", "dear old friend from school"));
        ASSERT_TRUE(map_is_letter_constructible_from_magazine("hello", "hello"));
}
