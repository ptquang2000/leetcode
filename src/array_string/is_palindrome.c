#include "utils/asserts.h"

extern bool array_string_isPalindrome(const char* s);

void test_array_string_isPalindrome()
{
        ASSERT_TRUE(array_string_isPalindrome("A man, a plan, a canal Panama."));
        ASSERT_TRUE(array_string_isPalindrome("Able was I, ere I saw Elba!"));
        ASSERT_FALSE(array_string_isPalindrome("Ray a Ray"));
}
