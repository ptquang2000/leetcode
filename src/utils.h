#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

typedef enum UtilsType_enum
{
        UTYPE_BOOL,
        UTYPE_CHAR,
        UTYPE_INT,
        UTYPE_PTR,
        UTYPE_STRING,
        UTYPE_COUNT,
} UtilsType;

#define UTYPE(value)                                                                                                   \
        _Generic((value),                                                                                              \
                bool: UTYPE_BOOL,                                                                                      \
                char: UTYPE_CHAR,                                                                                      \
                int: UTYPE_INT,                                                                                        \
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
                const char**: UTYPE_STRING ^ 0x80,                                                                     \
                void**: UTYPE_PTR ^ 0x80),                                                                             \
                value, size

void utils_print(const char* i_format, ...);
#define UTILS_LOG(...) utils_print(__VA_ARGS__);

typedef enum UtilsOp_enum
{
        UOP_EQUAL,
        UOP_LESS,
        UOP_LESS_EQUAL,
        UOP_GREATER,
        UOP_GREATER_EQUAL,
        UOP_IN,
        UOP_COUNT,
} UtilsOp;

void utils_assert(const char*, const char*, int, UtilsOp, ...);

#define UTILS_ASSERT_EQUAL(actual, ...)                                                                                \
        utils_assert(__FILE__, __func__, __LINE__, UOP_EQUAL,                                                          \
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
        utils_assert(__FILE__, __func__, __LINE__, UOP_LESS,                                                           \
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
        utils_assert(__FILE__, __func__, __LINE__, UOP_GREATER,                                                        \
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
        utils_assert(__FILE__, __func__, __LINE__, UOP_IN,                                                             \
                     _Generic((actual),                                                                                \
                             bool: UTYPE_BOOL,                                                                         \
                             char: UTYPE_CHAR,                                                                         \
                             int: UTYPE_INT,                                                                           \
                             void*: UTYPE_PTR,                                                                         \
                             const char*: UTYPE_STRING),                                                               \
                     actual, __VA_ARGS__)

#endif
