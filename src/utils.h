#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef enum UtilsType
{
        UTYPE_BOOL,
        UTYPE_CHAR,
        UTYPE_INT,
        UTYPE_UINT64,
        UTYPE_PTR,
        UTYPE_STRING,
        UTYPE_COUNT,
} UtilsType;

#define UTYPE(value)                                                                                                   \
        _Generic((value),                                                                                              \
                bool: UTYPE_BOOL,                                                                                      \
                char: UTYPE_CHAR,                                                                                      \
                int: UTYPE_INT,                                                                                        \
                uint64_t: UTYPE_UINT64,                                                                                \
                const char*: UTYPE_STRING,                                                                             \
                bool*: UTYPE_PTR,                                                                                      \
                char*: UTYPE_PTR,                                                                                      \
                int*: UTYPE_PTR,                                                                                       \
                void*: UTYPE_PTR),                                                                                     \
                value
#define UARRAY(value, size)                                                                                            \
        _Generic((value),                                                                                              \
                bool*: UTYPE_BOOL ^ 0x80,                                                                              \
                char*: UTYPE_CHAR ^ 0x80,                                                                              \
                int*: UTYPE_INT ^ 0x80,                                                                                \
                uint64_t*: UTYPE_UINT64 ^ 0x80,                                                                        \
                const char**: UTYPE_STRING ^ 0x80,                                                                     \
                void**: UTYPE_PTR ^ 0x80),                                                                             \
                value, (size_t)size

void utils_print(const char* i_format, ...);
#define UTILS_LOG(...) utils_print(__VA_ARGS__);

typedef enum UtilsOp
{
        UOP_EQUAL,
        UOP_LESS,
        UOP_LESS_EQUAL,
        UOP_GREATER,
        UOP_GREATER_EQUAL,
        UOP_IN,
        UOP_COUNT,
} UtilsOp;

void utils_Assert(const char*, const char*, int, UtilsOp, ...);
void utils_AssertInArray(const char*, const char*, int, UtilsType, ...);
// void utils_AssertCountEqual(const char*, const char*, int, UtilsType, ...);

#define UTILS_ASSERT_EQUAL(actual, ...)                                                                                \
        utils_Assert(__FILE__, __FUNCTION__, __LINE__, UOP_EQUAL,                                                      \
                     _Generic((actual),                                                                                \
                             bool: UTYPE_BOOL,                                                                         \
                             char: UTYPE_CHAR,                                                                         \
                             int: UTYPE_INT,                                                                           \
                             void*: UTYPE_PTR,                                                                         \
                             const char*: UTYPE_STRING,                                                                \
                             bool*: UTYPE_BOOL ^ 0x80,                                                                 \
                             char*: UTYPE_CHAR ^ 0x80,                                                                 \
                             int*: UTYPE_INT ^ 0x80,                                                                   \
                             const char**: UTYPE_STRING ^ 0x80,                                                        \
                             void**: UTYPE_PTR ^ 0x80),                                                                \
                     actual, __VA_ARGS__)
#define UTILS_ASSERT_LESS(actual, ...)                                                                                 \
        utils_Assert(__FILE__, __FUNCTION__, __LINE__, UOP_LESS,                                                       \
                     _Generic((actual),                                                                                \
                             bool: UTYPE_BOOL,                                                                         \
                             char: UTYPE_CHAR,                                                                         \
                             int: UTYPE_INT,                                                                           \
                             void*: UTYPE_PTR,                                                                         \
                             const char*: UTYPE_STRING,                                                                \
                             bool*: UTYPE_BOOL ^ 0x80,                                                                 \
                             char*: UTYPE_CHAR ^ 0x80,                                                                 \
                             int*: UTYPE_INT ^ 0x80,                                                                   \
                             const char**: UTYPE_STRING ^ 0x80,                                                        \
                             void**: UTYPE_PTR ^ 0x80),                                                                \
                     actual, __VA_ARGS__)
#define UTILS_ASSERT_GREATER(actual, ...)                                                                              \
        utils_Assert(__FILE__, __FUNCTION__, __LINE__, UOP_GREATER,                                                    \
                     _Generic((actual),                                                                                \
                             bool: UTYPE_BOOL,                                                                         \
                             char: UTYPE_CHAR,                                                                         \
                             int: UTYPE_INT,                                                                           \
                             void*: UTYPE_PTR,                                                                         \
                             const char*: UTYPE_STRING,                                                                \
                             bool*: UTYPE_BOOL ^ 0x80,                                                                 \
                             int*: UTYPE_INT ^ 0x80,                                                                   \
                             char*: UTYPE_CHAR ^ 0x80,                                                                 \
                             const char**: UTYPE_STRING ^ 0x80,                                                        \
                             void**: UTYPE_PTR ^ 0x80),                                                                \
                     actual, __VA_ARGS__)
#define UTILS_ASSERT_TRUE(actual) UTILS_ASSERT_EQUAL((bool)actual, true)
#define UTILS_ASSERT_FALSE(actual) UTILS_ASSERT_EQUAL((bool)actual, false)
#define UTILS_ASSERT_IS(actual, expected) UTILS_ASSERT_EQUAL((void*)actual, (void*)expected);
#define UTILS_ASSERT_IS_NONE(actual) UTILS_ASSERT_EQUAL((void*)actual, 0);
#define UTILS_ASSERT_IN(actual, ...)                                                                                   \
        utils_AssertInArray(__FILE__, __FUNCTION__, __LINE__,                                                          \
                            _Generic((actual),                                                                         \
                                    bool: UTYPE_BOOL,                                                                  \
                                    char: UTYPE_CHAR,                                                                  \
                                    int: UTYPE_INT,                                                                    \
                                    void*: UTYPE_PTR,                                                                  \
                                    const char*: UTYPE_STRING),                                                        \
                            actual, __VA_ARGS__)

#define IsArray(p)                                                                                                     \
        _Generic((p),                                                                                                  \
                bool*: true,                                                                                           \
                char*: true,                                                                                           \
                int*: true,                                                                                            \
                void**: true,                                                                                          \
                uint8_t*: true,                                                                                        \
                uint16_t*: true,                                                                                       \
                uint32_t*: true,                                                                                       \
                uint64_t*: true,                                                                                       \
                const char**: true,                                                                                    \
                default: false)
#define Stride(p)                                                                                                      \
        _Generic((p),                                                                                                  \
                bool*: sizeof(bool),                                                                                   \
                char*: sizeof(char),                                                                                   \
                int*: sizeof(int),                                                                                     \
                uint8_t*: sizeof(uint8_t),                                                                             \
                uint16_t*: sizeof(uint16_t),                                                                           \
                uint32_t*: sizeof(uint32_t),                                                                           \
                uint64_t*: sizeof(uint64_t),                                                                           \
                void**: sizeof(void*),                                                                                 \
                const char**: sizeof(const char*),                                                                     \
                default: 0)
#define PointerType(p)                                                                                                 \
        _Generic((*p),                                                                                                 \
                bool: UTYPE_BOOL,                                                                                      \
                char: UTYPE_CHAR,                                                                                      \
                int: UTYPE_INT,                                                                                        \
                uint8_t: UTYPE_CHAR,                                                                                   \
                uint16_t: UTYPE_CHAR,                                                                                  \
                uint32_t: UTYPE_INT,                                                                                   \
                uint64_t: UTYPE_UINT64,                                                                                \
                void*: UTYPE_PTR,                                                                                      \
                const char*: UTYPE_STRING)

void utils_assert_count_equal(const char* i_file, const char* i_func, int i_line, UtilsType i_type, size_t i_actual,
                              size_t i_expected, size_t i_size, size_t i_stride);
void utils_assert_count_equal_array(const char* i_file, const char* i_func, int i_line, UtilsType i_type,
                                    size_t i_actual, size_t i_acutal_size, size_t i_expected, size_t i_expected_size,
                                    size_t i_count, size_t i_stride, size_t i_size_stride);
#define UTILS_ASSERT_COUNT_EQUAL(actual, expected, count)                                                              \
        utils_assert_count_equal(__FILE__, __FUNCTION__, __LINE__, PointerType(actual), (size_t)actual,                \
                                 (size_t)expected, (size_t)count, Stride(actual));
#define UTILS_ASSERT_COUNT_EQUAL_ARRAY(actual, actual_size, expected, expected_size, count)                            \
        utils_assert_count_equal_array(__FILE__, __FUNCTION__, __LINE__, PointerType(*actual), (size_t)actual,         \
                                       (size_t)actual_size, (size_t)expected, (size_t)expected_size, (size_t)count,    \
                                       Stride(*actual), Stride(actual_size));
#endif
