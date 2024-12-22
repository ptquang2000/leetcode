#include "utils.h"

#include <stdbool.h>

// Declaration:
bool Stack_isWellFormed(const char* s);

void test_Stack_isWellFormed()
{
        UTILS_ASSERT_TRUE(Stack_isWellFormed("()"));
        UTILS_ASSERT_TRUE(Stack_isWellFormed("()[]{}"));
        UTILS_ASSERT_TRUE(Stack_isWellFormed("([]){()}"));
        UTILS_ASSERT_TRUE(Stack_isWellFormed("[()[]{()()}]"));
        UTILS_ASSERT_FALSE(Stack_isWellFormed("(]"));
        UTILS_ASSERT_FALSE(Stack_isWellFormed("{)"));
        UTILS_ASSERT_FALSE(Stack_isWellFormed("[()[]{()()"));
}
