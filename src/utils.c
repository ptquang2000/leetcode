#include "utils.h"

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifndef TEST_UTILS
#define UTILS_TRAP __builtin_trap()
#else
#define UTILS_TRAP break
#endif

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatBool(uint64_t i_value)
{
        bool value = i_value;
        if (value)
                printf("true");
        else
                printf("false");
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatBoolPointer(uint64_t i_value)
{
        bool* value = (bool*)i_value;
        if (*value)
                printf("true");
        else
                printf("false");
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatInt(uint64_t i_value)
{
        int value = i_value;
        printf("%d", value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatIntPointer(uint64_t i_value)
{
        int* value = (int*)i_value;
        printf("%d", *value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatChar(uint64_t i_value)
{
        char value = i_value;
        printf("'%c'", value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatCharPointer(uint64_t i_value)
{
        char* value = (char*)i_value;
        printf("\"%c\"", *value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatString(uint64_t i_value)
{
        typedef const char* string;
        string value = (string)i_value;
        printf("\"%s\"", value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatPointer(uint64_t i_value)
{
        typedef void* pointer;
        pointer value = (pointer)i_value;
        printf("\"%p\"", value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatBoolArray(uint64_t i_value, int i_size)
{
        bool* arr = (bool*)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++)
        {
                printf("%s", arr[i] ? "true" : "false");
                if (i != i_size - 1)
                {
                        printf(", ");
                }
        }
        printf("]");
}
////////////////////////////////////////////////////////////////////////////////

static void utils_FormatCharArray(uint64_t i_value, int i_size)
{
        char* arr = (char*)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++)
        {
                printf("'%c'", arr[i]);
                if (i != i_size - 1)
                {
                        printf(", ");
                }
        }
        printf("]");
}
////////////////////////////////////////////////////////////////////////////////

static void utils_FormatIntArray(uint64_t i_value, int i_size)
{
        int* arr = (int*)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++)
        {
                printf("%d", arr[i]);
                if (i != i_size - 1)
                {
                        printf(", ");
                }
        }
        printf("]");
}
////////////////////////////////////////////////////////////////////////////////

static void utils_FormatStringArray(uint64_t i_value, int i_size)
{
        typedef const char* string;
        string* arr = (string*)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++)
        {
                printf("\"%s\"", arr[i]);
                if (i != i_size - 1)
                {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatPointerArray(uint64_t i_value, int i_size)
{
        typedef void* ptr;
        ptr* arr = (ptr*)i_value;
        printf("[");
        for (int i = 0; i < i_size; i++)
        {
                printf("%p", arr[i]);
                if (i != i_size - 1)
                {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

typedef union FormatType_struct {
        UtilsType type;
        struct
        {
                int basicType : 7;
                bool isArray : 1;
        };
} FormatType;

////////////////////////////////////////////////////////////////////////////////

void utils_print(const char* i_format, ...)
{
        static void (*printFormatFunctions[UTYPE_COUNT])(uint64_t) = {
                utils_FormatBool, utils_FormatChar, utils_FormatInt, utils_FormatPointer, utils_FormatString,
        };
        static void (*printArrarFormatFunctions[UTYPE_COUNT])(uint64_t, int) = {
                utils_FormatBoolArray,    utils_FormatCharArray,   utils_FormatIntArray,
                utils_FormatPointerArray, utils_FormatStringArray,
        };

        size_t formatSize = strlen(i_format);
        const char target = '{';
        const char *next = i_format, *last = i_format;

        va_list args;
        va_start(args, i_format);
        while ((next = strchr(next, target)) != NULL && next - i_format < formatSize)
        {
                printf("%.*s", (int)(next - last), last);

                next++;
                if (*next != '}')
                {
                        printf("{");
                        last = next;
                        continue;
                }
                else
                {
                        next++;
                        last = next;
                }

                FormatType type = va_arg(args, FormatType);
                uint64_t value = va_arg(args, uint64_t);
                if (type.isArray)
                {
                        int size = va_arg(args, int);
                        printArrarFormatFunctions[type.basicType](value, size);
                }
                else
                {
                        printFormatFunctions[type.basicType](value);
                }
        }
        va_end(args);

        if (last == i_format)
        {
                printf("%s", i_format);
        }

        printf("\n");
}

////////////////////////////////////////////////////////////////////////////////

static bool CompareInt(UtilsOp op, UtilsType type, uint64_t lhs, uint64_t rhs)
{
        int a = lhs;
        int b = rhs;
        switch (op)
        {
        case UOP_EQUAL:
                return a == b;
        case UOP_LESS:
                return a < b;
        case UOP_LESS_EQUAL:
                return a <= b;
        case UOP_GREATER:
                return a > b;
        case UOP_GREATER_EQUAL:
                return a >= b;
        default:
                UTILS_LOG("Unsupported operation {} for type {}", op, type);
                assert(false);
        }
}

////////////////////////////////////////////////////////////////////////////////

static bool CompareString(UtilsOp op, UtilsType type, uint64_t lhs, uint64_t rhs)
{
        typedef const char* string;
        string a = (string)lhs;
        string b = (string)rhs;
        int result = strcmp(a, b);
        switch (op)
        {
        case UOP_EQUAL:
                return result == 0;
        case UOP_LESS:
                return result < 0;
        case UOP_GREATER:
                return result > 0;
        default:
                UTILS_LOG("Unsupported operation {} for type {}", op, type);
                assert(false);
        }
}

////////////////////////////////////////////////////////////////////////////////

static bool CompareBoolArray(UtilsOp op, UtilsType type, uint64_t lhs, uint64_t rhs, int size, int* index)
{
        assert(size > 0);
        if (lhs == rhs && rhs == 0 && size == 0)
        {
                return true;
        }

        bool* a = (bool*)lhs;
        bool* b = (bool*)rhs;
        for (int i = 0; i < size; i++)
        {
                *index = i;
                switch (op)
                {
                case UOP_EQUAL:
                        if (a[i] != b[i])
                                return false;
                        else
                                break;
                default:
                        UTILS_LOG("Unsupported operation {} for type {}", op, type);
                        assert(false);
                }
        }
        return true;
}

////////////////////////////////////////////////////////////////////////////////

static bool CompareCharArray(UtilsOp op, UtilsType type, uint64_t lhs, uint64_t rhs, int size, int* index)
{
        assert(size > 0);
        if (lhs == rhs && rhs == 0 && size == 0)
        {
                return true;
        }

        char* a = (char*)lhs;
        char* b = (char*)rhs;
        for (int i = 0; i < size; i++)
        {
                *index = i;
                switch (op)
                {
                case UOP_EQUAL:
                        if (a[i] != b[i])
                                return false;
                        else
                                break;
                case UOP_LESS:
                        if (a[i] >= b[i])
                                return false;
                        else
                                break;
                case UOP_LESS_EQUAL:
                        if (a[i] > b[i])
                                return false;
                        else
                                break;
                case UOP_GREATER:
                        if (a[i] <= b[i])
                                return false;
                        else
                                break;
                case UOP_GREATER_EQUAL:
                        if (a[i] < b[i])
                                return false;
                        else
                                break;
                default:
                        UTILS_LOG("Unsupported operation {} for type {}", op, type);
                        assert(false);
                }
        }
        return true;
}

////////////////////////////////////////////////////////////////////////////////

static bool CompareIntArray(UtilsOp op, UtilsType type, uint64_t lhs, uint64_t rhs, int size, int* index)
{
        assert(size > 0);
        if (lhs == rhs && rhs == 0 && size == 0)
        {
                return true;
        }

        int* a = (int*)lhs;
        int* b = (int*)rhs;
        for (int i = 0; i < size; i++)
        {
                *index = i;
                switch (op)
                {
                case UOP_EQUAL:
                        if (a[i] != b[i])
                                return false;
                        else
                                break;
                case UOP_LESS:
                        if (a[i] >= b[i])
                                return false;
                        else
                                break;
                case UOP_LESS_EQUAL:
                        if (a[i] > b[i])
                                return false;
                        else
                                break;
                case UOP_GREATER:
                        if (a[i] <= b[i])
                                return false;
                        else
                                break;
                case UOP_GREATER_EQUAL:
                        if (a[i] < b[i])
                                return false;
                        else
                                break;
                default:
                        UTILS_LOG("Unsupported operation {} for type {}", op, type);
                        assert(false);
                }
        }
        return true;
}

////////////////////////////////////////////////////////////////////////////////

static bool CompareStringArray(UtilsOp op, UtilsType type, uint64_t lhs, uint64_t rhs, int size, int* index)
{
        typedef const char* string;
        assert(size > 0);

        if (lhs == rhs && rhs == 0 && size == 0)
        {
                return true;
        }

        string* a = (string*)lhs;
        string* b = (string*)rhs;
        for (int i = 0; i < size; i++)
        {
                *index = i;
                int result = strcmp(a[i], b[i]);
                switch (op)
                {
                case UOP_EQUAL:
                        if (result != 0)
                                return false;
                        else
                                break;
                case UOP_LESS:
                        if (result >= 0)
                                return false;
                        else
                                break;
                case UOP_GREATER:
                        if (result <= 0)
                                return false;
                        else
                                break;
                default:
                        UTILS_LOG("Unsupported operation {} for type {}", op, type);
                        assert(false);
                }
        }
        return true;
}

////////////////////////////////////////////////////////////////////////////////

static bool CompareBoolInArray(UtilsType type, uint64_t lhs, uint64_t rhs, int size)
{
        assert(size > 0 && rhs != 0);

        bool a = lhs;
        bool* b = (bool*)rhs;
        for (int i = 0; i < size; i++)
        {
                if (a == b[i])
                {
                        return true;
                }
        }
        return false;
}

////////////////////////////////////////////////////////////////////////////////

static bool CompareCharInArray(UtilsType type, uint64_t lhs, uint64_t rhs, int size)
{
        assert(size > 0 && rhs != 0);

        char a = lhs;
        char* b = (char*)rhs;
        for (int i = 0; i < size; i++)
        {
                if (a == b[i])
                {
                        return true;
                }
        }
        return false;
}

////////////////////////////////////////////////////////////////////////////////

static bool CompareIntInArray(UtilsType type, uint64_t lhs, uint64_t rhs, int size)
{
        assert(size > 0 && rhs != 0);

        int a = lhs;
        int* b = (int*)rhs;
        for (int i = 0; i < size; i++)
        {
                if (a == b[i])
                {
                        return true;
                }
        }
        return false;
}

////////////////////////////////////////////////////////////////////////////////

static bool ComparePointerInArray(UtilsType type, uint64_t lhs, uint64_t rhs, int size)
{
        assert(size > 0 && rhs != 0);

        typedef void* pointer;
        pointer a = (pointer)lhs;
        pointer* b = (pointer*)rhs;
        for (int i = 0; i < size; i++)
        {
                if (a == b[i])
                {
                        return true;
                }
        }
        return false;
}

////////////////////////////////////////////////////////////////////////////////

static bool CompareStringInArray(UtilsType type, uint64_t lhs, uint64_t rhs, int size)
{
        typedef const char* string;
        assert(size > 0 && rhs != 0);

        string a = (string)lhs;
        string* b = (string*)rhs;
        for (int i = 0; i < size; i++)
        {
                if (strcmp(a, b[i]) == 0)
                {
                        return true;
                }
        }
        return false;
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageBool(const char* format, uint64_t actual, uint64_t expected)
{
        bool a = actual;
        bool e = expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageChar(const char* format, uint64_t actual, uint64_t expected)
{
        char a = actual;
        char e = expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageInt(const char* format, uint64_t actual, uint64_t expected)
{
        int a = actual;
        int e = expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageString(const char* format, uint64_t actual, uint64_t expected)
{
        typedef const char* string;
        string a = (string)actual;
        string e = (string)expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessagePointer(const char* format, uint64_t actual, uint64_t expected)
{
        typedef void* pointer;
        pointer a = (pointer)actual;
        pointer e = (pointer)expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageBoolArray(const char* format, uint64_t actual, uint64_t expected, int index)
{
        bool* a = (bool*)actual;
        bool* e = (bool*)expected;
        UTILS_LOG(format, UTYPE(e[index]), UTYPE(a[index]), UTYPE(index));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageCharArray(const char* format, uint64_t actual, uint64_t expected, int index)
{
        char* a = (char*)actual;
        char* e = (char*)expected;
        UTILS_LOG(format, UTYPE(e[index]), UTYPE(a[index]), UTYPE(index));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageIntArray(const char* format, uint64_t actual, uint64_t expected, int index)
{
        int* a = (int*)actual;
        int* e = (int*)expected;
        UTILS_LOG(format, UTYPE(e[index]), UTYPE(a[index]), UTYPE(index));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageStringArray(const char* format, uint64_t actual, uint64_t expected, int index)
{
        typedef const char* string;
        string* a = (string*)actual;
        string* e = (string*)expected;
        UTILS_LOG(format, UTYPE(e[index]), UTYPE(a[index]), UTYPE(index));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessagePointerArray(const char* format, uint64_t actual, uint64_t expected, int index)
{
        typedef void* pointer;
        pointer* a = (pointer*)actual;
        pointer* e = (pointer*)expected;
        UTILS_LOG(format, UTYPE(e[index]), UTYPE(a[index]), UTYPE(index));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageBoolInArray(const char* format, uint64_t actual, uint64_t expected, int size)
{
        bool a = actual;
        bool* e = (bool*)expected;
        UTILS_LOG(format, UARRAY(e, size), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageCharInArray(const char* format, uint64_t actual, uint64_t expected, int size)
{
        char a = actual;
        char* e = (char*)expected;
        UTILS_LOG("char in array {}", UTYPE(e));
        UTILS_LOG("expected={}", UTYPE_CHAR ^ 0x80, e, 3);
        UTILS_LOG(format, UARRAY(e, size), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageIntInArray(const char* format, uint64_t actual, uint64_t expected, int size)
{
        int a = actual;
        int* e = (int*)expected;
        UTILS_LOG(format, UARRAY(e, size), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessagePointerInArray(const char* format, uint64_t actual, uint64_t expected, int size)
{
        typedef void* pointer;
        pointer a = (pointer)actual;
        pointer* e = (pointer*)expected;
        UTILS_LOG(format, UARRAY(e, size), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageStringInArray(const char* format, uint64_t actual, uint64_t expected, int size)
{
        typedef const char* string;
        string a = (string)actual;
        string* e = (string*)expected;
        UTILS_LOG(format, UARRAY(e, size), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert(const char* file, const char* func, int line, UtilsOp operation, ...)
{
        va_list args;
        va_start(args, operation);

        FormatType type = va_arg(args, FormatType);
        uint64_t lhs = va_arg(args, uint64_t);
        uint64_t rhs = va_arg(args, uint64_t);

        if (operation == UOP_IN)
        {
                int size = va_arg(args, int);

                static const char* printFormats[UOP_COUNT] = {
                        "Expected {} got {}.", "Expected {} got {}.", "Expected {} got {}.",
                        "Expected {} got {}.", "Expected {} got {}.", "Expected {} got {}.",
                };
                static bool (*compareFunctions[UTYPE_COUNT])(UtilsType, uint64_t, uint64_t, int) = {
                        CompareBoolInArray,    CompareCharInArray,   CompareIntInArray,
                        ComparePointerInArray, CompareStringInArray,
                };
                static void (*printFunctions[UTYPE_COUNT])(const char*, uint64_t, uint64_t, int) = {
                        PrintAssertExpectedMessageBoolInArray,   PrintAssertExpectedMessageCharInArray,
                        PrintAssertExpectedMessageIntInArray,    PrintAssertExpectedMessagePointerInArray,
                        PrintAssertExpectedMessageStringInArray,
                };

                bool (*compareFunction)(UtilsType, uint64_t, uint64_t, int) = compareFunctions[type.basicType];
                void (*printFunction)(const char*, uint64_t, uint64_t, int) = printFunctions[type.basicType];
                while (!compareFunction(type.basicType, lhs, rhs, size))
                {
                        UTILS_LOG("\n-----------------------------------------------------");
                        UTILS_LOG("FAILED: {}", UTYPE(func));
                        UTILS_LOG("File {} at line {}:", UTYPE(file), UTYPE(line));
                        printFunction(printFormats[operation], lhs, rhs, size);
                        UTILS_LOG("-----------------------------------------------------\n");
                        UTILS_TRAP;
                }
        }
        else if (type.isArray)
        {
                int size = va_arg(args, int);

                static const char* printFormats[UOP_COUNT] = {
                        "Expected {} got {} at index {}.",
                        "Expected less than {} got {} at index {}.",
                        "Expected less or equal than {} got {} at index {}.",
                        "Expected greater than {} got {} at index {}.",
                        "Expected greater or equal than {} got {} at index {}.",
                        "Expected {} in {} at index {}.",
                };
                static bool (*compareFunctions[UTYPE_COUNT])(UtilsOp, UtilsType, uint64_t, uint64_t, int, int*) = {
                        CompareBoolArray, CompareCharArray, CompareIntArray, CompareIntArray, CompareStringArray,
                };
                static void (*printFunctions[UTYPE_COUNT])(const char*, uint64_t, uint64_t, int) = {
                        PrintAssertExpectedMessageBoolArray,   PrintAssertExpectedMessageCharArray,
                        PrintAssertExpectedMessageIntArray,    PrintAssertExpectedMessagePointerArray,
                        PrintAssertExpectedMessageStringArray,
                };

                bool (*compareFunction)(UtilsOp, UtilsType, uint64_t, uint64_t, int, int*) =
                        compareFunctions[type.basicType];
                void (*printFunction)(const char*, uint64_t, uint64_t, int) = printFunctions[type.basicType];
                int index;
                while (!compareFunction(operation, type.basicType, lhs, rhs, size, &index))
                {
                        UTILS_LOG("\n-----------------------------------------------------");
                        UTILS_LOG("FAILED: {}", UTYPE(func));
                        UTILS_LOG("File {} at line {}:", UTYPE(file), UTYPE(line));
                        printFunction(printFormats[operation], lhs, rhs, index);
                        UTILS_LOG("-----------------------------------------------------\n");
                        UTILS_TRAP;
                }
        }
        else
        {
                static const char* printFormats[UOP_COUNT] = {
                        "Expected {} got {}.",
                        "Expected less than {} got {}.",
                        "Expected less or equal than {} got {}.",
                        "Expected greater than {} got {}.",
                        "Expected greater or equal than {} got {}.",
                        "Expected {} in {}.",
                };
                static bool (*compareFunctions[UTYPE_COUNT])(UtilsOp, UtilsType, uint64_t, uint64_t) = {
                        CompareInt, CompareInt, CompareInt, CompareInt, CompareString,
                };
                static void (*printFunctions[UTYPE_COUNT])(const char*, uint64_t, uint64_t) = {
                        PrintAssertExpectedMessageBool,   PrintAssertExpectedMessageChar,
                        PrintAssertExpectedMessageInt,    PrintAssertExpectedMessagePointer,
                        PrintAssertExpectedMessageString,
                };

                bool (*compareFunction)(UtilsOp, UtilsType, uint64_t, uint64_t) = compareFunctions[type.basicType];
                void (*printFunction)(const char*, uint64_t, uint64_t) = printFunctions[type.basicType];
                while (!compareFunction(operation, type.basicType, lhs, rhs))
                {
                        UTILS_LOG("\n-----------------------------------------------------");
                        UTILS_LOG("FAILED: {}", UTYPE(func));
                        UTILS_LOG("File {} at line {}:", UTYPE(file), UTYPE(line));
                        printFunction(printFormats[operation], lhs, rhs);
                        UTILS_LOG("-----------------------------------------------------\n");
                        UTILS_TRAP;
                }
        }
        va_end(args);
}

////////////////////////////////////////////////////////////////////////////////
