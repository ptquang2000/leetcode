#include "utils/asserts.h"

extern int stack_evaluate(int size, const char* rpnExpression[size]);

void test_stack_evaluate()
{
        {
                const char* rpn[] = {"2", "1", "+", "3", "*"};
                ASSERT_EQUAL(stack_evaluate(sizeof(rpn) / sizeof(*rpn), rpn), 9);
        }
        {
                const char* rpn[] = {"4", "13", "5", "/", "+"};
                ASSERT_EQUAL(stack_evaluate(sizeof(rpn) / sizeof(*rpn), rpn), 6);
        }
        {
                const char* rpn[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
                ASSERT_EQUAL(stack_evaluate(sizeof(rpn) / sizeof(*rpn), rpn), 22);
        }
}
