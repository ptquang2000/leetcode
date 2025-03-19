#include "utils/asserts.h"

#include <string.h>

extern int array_string_rabinKarp(const char *t, const char *s);

void test_array_string_rabinKarp()
{
        {
                const char *t = "GACGCCA";
                const char *s = "CGC";
                char *p = strstr(t, s);
                int expected = p == NULL ? -1 : p - t;
                ASSERT_EQUAL((int_obj){array_string_rabinKarp(t, s)}, (int_obj){expected});
        }
        {
                const char *t = "GACGCCA";
                const char *s = "CCA";
                char *p = strstr(t, s);
                int expected = p == NULL ? -1 : p - t;
                ASSERT_EQUAL((int_obj){array_string_rabinKarp(t, s)}, (int_obj){expected});
        }
        {
                const char *t = "GACGCCA";
                const char *s = "BBA";
                char *p = strstr(t, s);
                int expected = p == NULL ? -1 : p - t;
                ASSERT_EQUAL((int_obj){array_string_rabinKarp(t, s)}, (int_obj){expected});
        }
        {
                const char *t = "hello how are you?";
                const char *s = "how are";
                char *p = strstr(t, s);
                int expected = p == NULL ? -1 : p - t;
                ASSERT_EQUAL((int_obj){array_string_rabinKarp(t, s)}, (int_obj){expected});
        }
        {
                const char *t = " hello world is the first code of every programmer";
                const char *s = "first";
                char *p = strstr(t, s);
                int expected = p == NULL ? -1 : p - t;
                ASSERT_EQUAL((int_obj){array_string_rabinKarp(t, s)}, (int_obj){expected});
        }
}
