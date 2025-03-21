#include "utils/asserts.h"

extern int array_string_replaceAndRemove(int size, char *s);

void test_array_string_replaceAndRemove()
{
        {
                char_array actual = {(char[]){'a', 'c', 'a', 'a', '\0', '\0', '\0'}, 7};
                ASSERT_EQUAL((int_obj){array_string_replaceAndRemove(4, actual.data)}, (int_obj){7});
                char_array expected = {(char[]){'d', 'd', 'c', 'd', 'd', 'd', 'd'}, 7};
                ASSERT_EQUAL(actual, expected);
        }
        {
                char_array actual = {(char[]){'a', 'c', 'd', 'b', 'b', 'c', 'a'}, 7};
                ASSERT_EQUAL((int_obj){array_string_replaceAndRemove(7, actual.data)}, (int_obj){7});
                char_array expected = {(char[]){'d', 'd', 'c', 'd', 'c', 'd', 'd'}, 7};
                ASSERT_EQUAL(actual, expected);
        }
        {
                char_array actual = {(char[]){'a', 'b', 'a', 'c', '\0'}, 5};
                ASSERT_EQUAL((int_obj){array_string_replaceAndRemove(4, actual.data)}, (int_obj){5});
                char_array expected = {(char[]){'d', 'd', 'd', 'd', 'c'}, 5};
                ASSERT_EQUAL(actual, expected);
        }
}
