#include "utils/utils.h"

// Declaration:
bool array_string_isPalindrome(const char* s);

void test_array_string_isPalindrome()
{
        UTILS_ASSERT_TRUE(array_string_isPalindrome("A man, a plan, a canal Panama."));
        UTILS_ASSERT_TRUE(array_string_isPalindrome("Able was I, ere I saw Elba!"));
        UTILS_ASSERT_FALSE(array_string_isPalindrome("Ray a Ray"));
}
