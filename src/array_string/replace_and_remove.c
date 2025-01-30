#include "utils/utils.h"

extern int array_string_replaceAndRemove(int size, char* s);

void test_array_string_replaceAndRemove()
{
        {
                char actual[] = {'a', 'c', 'a', 'a', '\0', '\0', '\0'};
                UTILS_ASSERT_EQUAL(array_string_replaceAndRemove(4, actual), 7);
                char expected[] = {'d', 'd', 'c', 'd', 'd', 'd', 'd'};
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, 7);
        }
        {
                char actual[] = {'a', 'c', 'd', 'b', 'b', 'c', 'a'};
                UTILS_ASSERT_EQUAL(array_string_replaceAndRemove(7, actual), 7);
                char expected[] = {'d', 'd', 'c', 'd', 'c', 'd', 'd'};
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, 7);
        }
        {
                char actual[] = {'a', 'b', 'a', 'c', '\0'};
                UTILS_ASSERT_EQUAL(array_string_replaceAndRemove(4, actual), 5);
                char expected[] = {'d', 'd', 'd', 'd', 'c'};
                UTILS_ASSERT_EQUAL_ARRAY(actual, expected, 5);
        }
}
