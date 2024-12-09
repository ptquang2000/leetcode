#include "utils.h"

#include <string.h>

// Declaration:
int ArrayString_rabinKarp(const char* t, const char* s);

void test_ArrayString_rabinKarp()
{
        {
                const char* t = "GACGCCA";
                const char* s = "CGC";
                char* p = strstr(t, s);
                int expected = p == NULL ? -1 : p - t;
                UTILS_ASSERT_EQUAL(ArrayString_rabinKarp(t, s), expected);
        }
        {
                const char* t = "GACGCCA";
                const char* s = "CCA";
                char* p = strstr(t, s);
                int expected = p == NULL ? -1 : p - t;
                UTILS_ASSERT_EQUAL(ArrayString_rabinKarp(t, s), expected);
        }
        {
                const char* t = "GACGCCA";
                const char* s = "BBA";
                char* p = strstr(t, s);
                int expected = p == NULL ? -1 : p - t;
                UTILS_ASSERT_EQUAL(ArrayString_rabinKarp(t, s), expected);
        }
        {
                const char* t = "hello how are you?";
                const char* s = "how are";
                char* p = strstr(t, s);
                int expected = p == NULL ? -1 : p - t;
                UTILS_ASSERT_EQUAL(ArrayString_rabinKarp(t, s), expected);
        }
        {
                const char* t = " hello world is the first code of every programmer";
                const char* s = "first";
                char* p = strstr(t, s);
                int expected = p == NULL ? -1 : p - t;
                UTILS_ASSERT_EQUAL(ArrayString_rabinKarp(t, s), expected);
        }
}
