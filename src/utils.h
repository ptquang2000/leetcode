#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

typedef enum UtilsType_enum
{
        UTYPE_BOOL,
        UTYPE_BOOL_PTR,
        UTYPE_INT,
        UTYPE_INT_PTR,
        UTYPE_CHAR,
        UTYPE_CHAR_PTR,
        UTYPE_STRING,
        UTYPE_COUNT,
} UtilsType;

void utils_print(const char* i_format, ...);

#define UTILS_LOG(...) utils_print(__VA_ARGS__);

void utils_assert_equal(const char*, const char*, int, UtilsType, ...);
void utils_assert_equal_array(const char*, const char*, int, UtilsType, ...);

#define UTYPE(value)                                                                                                   \
        _Generic((value),                                                                                              \
                bool: UTYPE_BOOL,                                                                                      \
                bool*: UTYPE_BOOL_PTR,                                                                                 \
                int: UTYPE_INT,                                                                                        \
                int*: UTYPE_INT_PTR,                                                                                   \
                char: UTYPE_CHAR,                                                                                      \
                char*: UTYPE_CHAR_PTR,                                                                                 \
                const char*: UTYPE_STRING),                                                                            \
                &value

#define UTILS_ASSERT_EQUAL(actual, ...)                                                                                \
        _Generic((actual),                                                                                             \
                bool: utils_assert_equal(__FILE__, __func__, __LINE__, UTYPE_BOOL, actual, __VA_ARGS__),               \
                bool*: utils_assert_equal_array(__FILE__, __func__, __LINE__, UTYPE_BOOL, actual, __VA_ARGS__),        \
                int: utils_assert_equal(__FILE__, __func__, __LINE__, UTYPE_INT, actual, __VA_ARGS__),                 \
                int*: utils_assert_equal_array(__FILE__, __func__, __LINE__, UTYPE_INT, actual, __VA_ARGS__),          \
                char: utils_assert_equal(__FILE__, __func__, __LINE__, UTYPE_CHAR, actual, __VA_ARGS__),               \
                char*: utils_assert_equal_array(__FILE__, __func__, __LINE__, UTYPE_CHAR, actual, __VA_ARGS__),        \
                const char*: utils_assert_equal_array(__FILE__, __func__, __LINE__, UTYPE_STRING, actual,              \
                                                      __VA_ARGS__))

#define UTILS_ASSERT_TRUE(actual) utils_assert_equal(__FILE__, __func__, __LINE__, UTYPE_BOOL, actual, true)
#define UTILS_ASSERT_FALSE(actual) utils_assert_equal(__FILE__, __func__, __LINE__, UTYPE_BOOL, actual, false)

#endif
