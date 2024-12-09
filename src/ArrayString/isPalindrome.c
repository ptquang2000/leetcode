#include "utils.h"

// Declaration:
bool ArrayString_isPalindrome(const char* s);

void test_ArrayString_isPalindrome()
{
        UTILS_ASSERT_TRUE(ArrayString_isPalindrome("A man, a plan, a canal Panama."));
        UTILS_ASSERT_TRUE(ArrayString_isPalindrome("Able was I, ere I saw Elba!"));
        UTILS_ASSERT_FALSE(ArrayString_isPalindrome("Ray a Ray"));
}
