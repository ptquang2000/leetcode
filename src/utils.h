void utils_assert_equal_int(int i_actual, int i_expect, char* i_file, const char* i_func, int i_line);

#define UTILS_ASSERT_EQUAL(actual, expect) _Generic((actual), \
                                 int: utils_assert_equal_int\
                        )(actual, expect, __FILE__, __func__, __LINE__)
