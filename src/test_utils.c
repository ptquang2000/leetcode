#include "utils.h"

void test_utils()
{
        bool trueValue = true;
        bool falseValue = false;
        int intValue = 69420;
        char xValue = 'x';
        char charValue = '=';
        char DValue = 'D';
        const char* stringValue = "B==D";
        const char* B0085 = "B0085";
        void* noneValue = 0;
        bool boolArrayExpected[3] = {true, false, true};
        bool boolArrayActual1[3] = {true, false, true};
        bool boolArrayActual2[3] = {true, true, true};
        char charArrayExpected[3] = {'x', 'x', 'x'};
        char charArrayActual1[3] = {'x', 'x', 'x'};
        char charArrayActual2[3] = {'x', 'y', 'x'};
        int intArrayExpected[3] = {69, 69, 69};
        int intArrayActual1[3] = {69, 69, 69};
        int intArrayActual2[3] = {69, 420, 69};
        const char* stringArrayExpected[3] = {"B==D", "B==D", "B==D"};
        const char* stringArrayActual1[3] = {"B==D", "B==D", "B==D"};
        const char* stringArrayActual2[3] = {"B==D", "B0085", "B==D"};
        int intArrayIn[3] = {69420, 69420, 69420};

        UTILS_LOG("\nTest UTILS_LOG\n");
        UTILS_LOG("bool:{}/{}, char:{}, int:{}, string:{}", UTYPE(trueValue), UTYPE(falseValue), UTYPE(charValue),
                  UTYPE(intValue), UTYPE(stringValue));
        UTILS_LOG("bool array:{}, char array:{}, int array:{}, string array:{}", UARRAY(intArrayActual2, 3),
                  UARRAY(charArrayActual2, 3), UTYPE(intValue), UARRAY(stringArrayExpected, 3));

        UTILS_LOG("\nTest UTILS_ASSERT_EQUAL bool");
        UTILS_ASSERT_EQUAL(trueValue, trueValue);
        UTILS_ASSERT_EQUAL(trueValue, falseValue);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL char");
        UTILS_ASSERT_EQUAL(xValue, xValue);
        UTILS_ASSERT_EQUAL(charValue, DValue);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL int");
        UTILS_ASSERT_EQUAL(69, 69);
        UTILS_ASSERT_EQUAL(420, 69);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL string");
        UTILS_ASSERT_EQUAL(B0085, B0085);
        UTILS_ASSERT_EQUAL(B0085, stringValue);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL bool array");
        UTILS_ASSERT_EQUAL(boolArrayActual1, boolArrayExpected, 3);
        UTILS_ASSERT_EQUAL(boolArrayActual2, boolArrayExpected, 3);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL char array");
        UTILS_ASSERT_EQUAL(charArrayActual1, charArrayExpected, 3);
        UTILS_ASSERT_EQUAL(charArrayActual2, charArrayExpected, 3);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL int array");
        UTILS_ASSERT_EQUAL(intArrayActual1, intArrayExpected, 3);
        UTILS_ASSERT_EQUAL(intArrayActual2, intArrayExpected, 3);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL string array");
        UTILS_ASSERT_EQUAL(stringArrayActual1, stringArrayExpected, 3);
        UTILS_ASSERT_EQUAL(stringArrayActual2, stringArrayExpected, 3);

        UTILS_LOG("Test UTILS_ASSERT_IS");
        UTILS_ASSERT_IS(stringArrayExpected, stringArrayExpected);
        UTILS_ASSERT_IS(stringArrayActual1, stringArrayExpected);

        UTILS_LOG("Test UTILS_ASSERT_IS_NONE");
        UTILS_ASSERT_IS_NONE(noneValue);
        UTILS_ASSERT_IS_NONE(stringArrayExpected);

        UTILS_LOG("Test UTILS_ASSERT_IN bool array");
        UTILS_ASSERT_IN(trueValue, boolArrayActual2, 3);
        UTILS_ASSERT_IN(falseValue, boolArrayActual2, 3);

        UTILS_LOG("Test UTILS_ASSERT_IN char array");
        UTILS_ASSERT_IN(xValue, charArrayExpected, 3);
        UTILS_ASSERT_IN(charValue, charArrayExpected, 3);

        UTILS_LOG("Test UTILS_ASSERT_IN int array");
        UTILS_ASSERT_IN(intValue, intArrayIn, 3);
        UTILS_ASSERT_IN(intValue, intArrayExpected, 3);

        UTILS_LOG("Test UTILS_ASSERT_IN string array");
        UTILS_ASSERT_IN(stringValue, stringArrayExpected, 3);
        UTILS_ASSERT_IN(B0085, stringArrayExpected, 3);
}
