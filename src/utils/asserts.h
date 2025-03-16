#ifndef UTILS_H
#define UTILS_H

#include "compare.h"

#define assert_msg(cond, msg)                                                                                          \
        do {                                                                                                           \
                if (!(cond))                                                                                           \
                        utils_log("{}", (string_obj){msg});                                                            \
        } while (0)

#define assert_equal(a, b)                                                                                             \
        do {                                                                                                           \
                assert_msg(cmp_helper(a, b) == 0, "not equal");                                                        \
        } while (0)

#define assert_count_equal

#define assert_in

struct btree_node;
#define UTILS_ASSERT_MSG(cond, ...)                                                                                    \
        do {                                                                                                           \
                if (!(cond)) {                                                                                         \
                        UTILS_LOG(__VA_ARGS__);                                                                        \
                        __builtin_trap();                                                                              \
                }                                                                                                      \
        } while (0)
#endif
