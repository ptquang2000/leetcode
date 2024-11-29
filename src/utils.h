void utils_assert_equal_int(char* i_file, const char* i_func, int i_line, int i_actual, int i_expect);
void utils_assert_equal_int_array(char* i_file, const char* i_func, int i_line, int* i_actual, int* i_expect,
                                  int i_size);

#define UTILS_ASSERT_EQUAL(actual, ...)                                                                                \
    _Generic((actual), int: utils_assert_equal_int, int*: utils_assert_equal_int_array)(__FILE__, __func__, __LINE__,  \
                                                                                        actual, __VA_ARGS__)
