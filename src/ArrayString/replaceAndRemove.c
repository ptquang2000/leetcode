#include "utils.h"

// Declaration:
int ArrayString_replaceAndRemove(int size, char* s);

void test_ArrayString_replaceAndRemove()
{
        {
                char actual[] = {'a', 'c', 'a', 'a', '\0', '\0', '\0'};
                UTILS_ASSERT_EQUAL(ArrayString_replaceAndRemove(4, actual), 7);
                char expected[] = {'d', 'd', 'c', 'd', 'd', 'd', 'd'};
                UTILS_ASSERT_EQUAL(actual, expected, 7);
        }
}
