#include "utils.h"

// Declaration:
int Stack_evaluate(int size, const char* rpnExpression[size]);

void test_Stack_evaluate()
{
        {
                const char* rpn[] = {"2", "1", "+", "3", "*"};
                UTILS_ASSERT_EQUAL(Stack_evaluate(sizeof(rpn) / sizeof(*rpn), rpn), 9);
        }
        {
                const char* rpn[] = {"4", "13", "5", "/", "+"};
                UTILS_ASSERT_EQUAL(Stack_evaluate(sizeof(rpn) / sizeof(*rpn), rpn), 6);
        }
        {
                const char* rpn[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
                UTILS_ASSERT_EQUAL(Stack_evaluate(sizeof(rpn) / sizeof(*rpn), rpn), 22);
        }
}
