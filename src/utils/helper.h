#ifndef UTILS_HELPER_H
#define UTILS_HELPER_H

#define PARENS ()
#define EMPTY

#define __expand__(...) __expand4__(__expand4__(__expand4__(__expand4__(__VA_ARGS__))))
#define __expand4__(...) __expand3__(__expand3__(__expand3__(__expand3__(__VA_ARGS__))))
#define __expand3__(...) __expand2__(__expand2__(__expand2__(__expand2__(__VA_ARGS__))))
#define __expand2__(...) __expand1__(__expand1__(__expand1__(__expand1__(__VA_ARGS__))))
#define __expand1__(...) __VA_ARGS__
#define ___expand___() __expand__

#define parse_args(...) __VA_OPT__(__expand__(__parse_args_helper(__VA_ARGS__)))
#define __parse_args_helper(arg, ...) typeof(arg) __VA_OPT__(, __parse_args_recursion PARENS(__VA_ARGS__))
#define __parse_args_recursion() __parse_args_helper

#define __function_decl(macro, ...) __VA_OPT__(__expand__(__function_decl_helper(macro, __VA_ARGS__)))
#define __function_decl_helper(macro, type, ...)                                                                       \
        macro(type) __VA_OPT__(__function_decl_recursion PARENS(macro, __VA_ARGS__))
#define __function_decl_recursion() __function_decl_helper

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))

#define free_array(x, n)                                                                                               \
        do {                                                                                                           \
                size_t __i = n;                                                                                        \
                while (__i)                                                                                            \
                        free(x[--__i]);                                                                                \
                free(x);                                                                                               \
        } while (0);

#endif
