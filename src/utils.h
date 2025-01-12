#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

struct btree_node;

typedef enum UtilsType {
        UTYPE_BOOL,
        UTYPE_CHAR,
        UTYPE_INT,
        UTYPE_UINT64,
        UTYPE_PTR,
        UTYPE_STRING,
        UTYPE_BTREE,
        UTYPE_COUNT,
} UtilsType;

#define UTYPE(value)                                                                                                   \
        _Generic((value),                                                                                              \
                bool: UTYPE_BOOL,                                                                                      \
                char: UTYPE_CHAR,                                                                                      \
                int: UTYPE_INT,                                                                                        \
                uint64_t: UTYPE_UINT64,                                                                                \
                const char *: UTYPE_STRING,                                                                            \
                struct btree_node *: UTYPE_BTREE,                                                                      \
                bool *: UTYPE_PTR,                                                                                     \
                char *: UTYPE_PTR,                                                                                     \
                int *: UTYPE_PTR,                                                                                      \
                void *: UTYPE_PTR),                                                                                    \
                value
#define UARRAY(value, size)                                                                                            \
        _Generic((value),                                                                                              \
                bool *: UTYPE_BOOL ^ 0x80,                                                                             \
                char *: UTYPE_CHAR ^ 0x80,                                                                             \
                int *: UTYPE_INT ^ 0x80,                                                                               \
                uint64_t *: UTYPE_UINT64 ^ 0x80,                                                                       \
                const char **: UTYPE_STRING ^ 0x80,                                                                    \
                void **: UTYPE_PTR ^ 0x80),                                                                            \
                value, (size_t)size
#define FORMAT_UTYPE(utype, value) utype, value
#define FORMAT_UARRAY(utype, value, size) utype ^ 0x80, value, (size_t)size

void utils_print(const char *i_format, ...);
#define UTILS_LOG(...) utils_print(__VA_ARGS__);

void utils_assert_equal(const char *i_file, const char *i_func, int i_line, UtilsType i_type, size_t i_actual,
                        size_t i_expected, size_t i_stride);
void utils_assert_less(const char *i_file, const char *i_func, int i_line, UtilsType i_type, size_t i_actual,
                       size_t i_expected, size_t i_stride);
void utils_assert_greater(const char *i_file, const char *i_func, int i_line, UtilsType i_type, size_t i_actual,
                          size_t i_expected, size_t i_stride);
void utils_assert_equal_array(const char *i_file, const char *i_func, int i_line, UtilsType i_type, size_t i_actual,
                              size_t i_expected, size_t i_size, size_t i_stride);
void utils_assert_less_array(const char *i_file, const char *i_func, int i_line, UtilsType i_type, size_t i_actual,
                             size_t i_expected, size_t i_size, size_t i_stride);
void utils_assert_greater_array(const char *i_file, const char *i_func, int i_line, UtilsType i_type, size_t i_actual,
                                size_t i_expected, size_t i_size, size_t i_stride);
void utils_assert_in_array(const char *i_file, const char *i_func, int i_line, UtilsType i_type, size_t i_expected,
                           size_t i_actual, size_t i_size, size_t i_stride);
void utils_assert_count_equal(const char *i_file, const char *i_func, int i_line, UtilsType i_type, size_t i_actual,
                              size_t i_expected, size_t i_size, size_t i_stride);
void utils_assert_count_equal_array(const char *i_file, const char *i_func, int i_line, UtilsType i_type,
                                    size_t i_actual, size_t i_acutal_size, size_t i_expected, size_t i_expected_size,
                                    size_t i_count, size_t i_stride, size_t i_size_stride);

#define PTR_STRIDE(p)                                                                                                  \
        _Generic((p),                                                                                                  \
                bool *: sizeof(bool),                                                                                  \
                char *: sizeof(char),                                                                                  \
                int *: sizeof(int),                                                                                    \
                uint8_t *: sizeof(uint8_t),                                                                            \
                uint16_t *: sizeof(uint16_t),                                                                          \
                uint32_t *: sizeof(uint32_t),                                                                          \
                uint64_t *: sizeof(uint64_t),                                                                          \
                void **: sizeof(void *),                                                                               \
                const char **: sizeof(const char *),                                                                   \
                default: 0)
#define TO_UTYPE(p)                                                                                                    \
        _Generic((p),                                                                                                  \
                bool: UTYPE_BOOL,                                                                                      \
                char: UTYPE_CHAR,                                                                                      \
                int: UTYPE_INT,                                                                                        \
                uint8_t: UTYPE_CHAR,                                                                                   \
                uint16_t: UTYPE_CHAR,                                                                                  \
                uint32_t: UTYPE_INT,                                                                                   \
                uint64_t: UTYPE_UINT64,                                                                                \
                void *: UTYPE_PTR,                                                                                     \
                const char *: UTYPE_STRING,                                                                            \
                default: (size_t)-1)
#define PTR_UTYPE(p) TO_UTYPE(*p)
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define free_array(x, n)                                                                                               \
        do {                                                                                                           \
                while (n)                                                                                              \
                        free(x[--n]);                                                                                  \
                free(x);                                                                                               \
        } while (0);

#define UTILS_ASSERT_EQUAL(actual, expected)                                                                           \
        utils_assert_equal(__FILE__, __FUNCTION__, __LINE__, TO_UTYPE(actual), (size_t)actual, (size_t)expected,       \
                           sizeof(typeof(actual)))
#define UTILS_ASSERT_LESS(actual, expected)                                                                            \
        utils_assert_less(__FILE__, __FUNCTION__, __LINE__, TO_UTYPE(actual), (size_t)actual, (size_t)expected,        \
                          sizeof(typeof(actual)))
#define UTILS_ASSERT_GREATER(actual, expected)                                                                         \
        utils_assert_greater(__FILE__, __FUNCTION__, __LINE__, TO_UTYPE(actual), (size_t)actual, (size_t)expected,     \
                             sizeof(typeof(actual)))
#define UTILS_ASSERT_EQUAL_ARRAY(actual, expected, size)                                                               \
        utils_assert_equal_array(__FILE__, __FUNCTION__, __LINE__, PTR_UTYPE(actual), (size_t)actual,                  \
                                 (size_t)expected, size, PTR_STRIDE(actual))
#define UTILS_ASSERT_LESS_ARRAY(actual, expected, size)                                                                \
        utils_assert_less_array(__FILE__, __FUNCTION__, __LINE__, PTR_UTYPE(actual), (size_t)actual, (size_t)expected, \
                                size, PTR_STRIDE(actual))
#define UTILS_ASSERT_GREATER_ARRAY(actual, expected, size)                                                             \
        utils_assert_greater_array(__FILE__, __FUNCTION__, __LINE__, PTR_UTYPE(actual), (size_t)actual,                \
                                   (size_t)expected, size, PTR_STRIDE(actual))
#define UTILS_ASSERT_TRUE(actual) UTILS_ASSERT_EQUAL((bool)actual, true)
#define UTILS_ASSERT_FALSE(actual) UTILS_ASSERT_EQUAL((bool)actual, false)
#define UTILS_ASSERT_IS(actual, expected) UTILS_ASSERT_EQUAL((void *)actual, (void *)expected);
#define UTILS_ASSERT_IS_NONE(actual) UTILS_ASSERT_EQUAL((void *)actual, 0);
#define UTILS_ASSERT_IN(actual, expected, size)                                                                        \
        utils_assert_in_array(__FILE__, __FUNCTION__, __LINE__, TO_UTYPE(actual), (size_t)actual, (size_t)expected,    \
                              size, PTR_STRIDE(expected))
#define UTILS_ASSERT_COUNT_EQUAL(actual, expected, count)                                                              \
        utils_assert_count_equal(__FILE__, __FUNCTION__, __LINE__, PTR_UTYPE(actual), (size_t)actual,                  \
                                 (size_t)expected, (size_t)count, PTR_STRIDE(actual));
#define UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, count)                            \
        utils_assert_count_equal_array(__FILE__, __FUNCTION__, __LINE__, PTR_UTYPE(*actual), (size_t)actual,           \
                                       (size_t)actual_size, (size_t)expected, (size_t)expected_size, (size_t)count,    \
                                       PTR_STRIDE(*actual), PTR_STRIDE(actual_size));
#endif
