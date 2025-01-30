#include "utils/utils.h"

#include <stdbool.h>

extern bool stack_is_well_formed(const char* s);

void test_stack_is_well_formed()
{
        UTILS_ASSERT_TRUE(stack_is_well_formed("()"));
        UTILS_ASSERT_TRUE(stack_is_well_formed("()[]{}"));
        UTILS_ASSERT_TRUE(stack_is_well_formed("([]){()}"));
        UTILS_ASSERT_TRUE(stack_is_well_formed("[()[]{()()}]"));
        UTILS_ASSERT_FALSE(stack_is_well_formed("(]"));
        UTILS_ASSERT_FALSE(stack_is_well_formed("{)"));
        UTILS_ASSERT_FALSE(stack_is_well_formed("[()[]{()()"));
}
