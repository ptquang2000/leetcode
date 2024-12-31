#include "utils.h"

#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#ifndef TEST_UTILS
#define UTILS_TRAP __builtin_trap()
#else
#define UTILS_TRAP break
#endif

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatBool(size_t i_value)
{
        bool value = i_value;
        if (value)
                printf("true");
        else
                printf("false");
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatBoolPointer(size_t i_value)
{
        bool* value = (bool*)i_value;
        if (*value)
                printf("true");
        else
                printf("false");
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatInt(size_t i_value)
{
        int value = i_value;
        printf("%d", value);
}
////////////////////////////////////////////////////////////////////////////////

static void utils_FormatUInt64(size_t i_value)
{
        printf("%ld", i_value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatIntPointer(size_t i_value)
{
        int* value = (int*)i_value;
        printf("%d", *value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatChar(size_t i_value)
{
        char value = i_value;
        printf("'%c'", value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatCharPointer(size_t i_value)
{
        char* value = (char*)i_value;
        printf("\"%c\"", *value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatString(size_t i_value)
{
        typedef const char* string;
        string value = (string)i_value;
        printf("\"%s\"", value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatPointer(size_t i_value)
{
        typedef void* pointer;
        pointer value = (pointer)i_value;
        printf("\"%p\"", value);
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatBoolArray(size_t i_value, int i_size)
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

static void utils_FormatCharArray(size_t i_value, int i_size)
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

static void utils_FormatIntArray(size_t i_value, int i_size)
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

static void utils_FormatUInt64Array(size_t i_value, int i_size)
{
        size_t* arr = (size_t*)(i_value);
        printf("[");
        for (int i = 0; i < i_size; i++)
        {
                printf("%ld", arr[i]);
                if (i != i_size - 1)
                {
                        printf(", ");
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

static void utils_FormatStringArray(size_t i_value, int i_size)
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

static void utils_FormatPointerArray(size_t i_value, int i_size)
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
        static void (*printFormatFunctions[UTYPE_COUNT])(size_t) = {
                utils_FormatBool,   utils_FormatChar,    utils_FormatInt,
                utils_FormatUInt64, utils_FormatPointer, utils_FormatString,
        };
        static void (*printArrarFormatFunctions[UTYPE_COUNT])(size_t, int) = {
                utils_FormatBoolArray,   utils_FormatCharArray,    utils_FormatIntArray,
                utils_FormatUInt64Array, utils_FormatPointerArray, utils_FormatStringArray,
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
                size_t value = va_arg(args, size_t);
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

static bool CompareInt(UtilsOp op, UtilsType type, size_t lhs, size_t rhs)
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

static bool CompareString(UtilsOp op, UtilsType type, size_t lhs, size_t rhs)
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

static bool CompareBoolArray(UtilsOp op, UtilsType type, size_t lhs, size_t rhs, size_t size, int* index)
{
        assert(size >= 0);
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

static bool CompareCharArray(UtilsOp op, UtilsType type, size_t lhs, size_t rhs, size_t size, int* index)
{
        assert(size >= 0);
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

static bool CompareIntArray(UtilsOp op, UtilsType type, size_t lhs, size_t rhs, size_t size, int* index)
{
        assert(size >= 0);
        if (lhs == rhs && rhs == 0 && size == 0)
        {
                return true;
        }

        int* a = (int*)lhs;
        int* b = (int*)rhs;
        for (size_t i = 0; i < size; i++)
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

static bool CompareStringArray(UtilsOp op, UtilsType type, size_t lhs, size_t rhs, size_t size, int* index)
{
        typedef const char* string;
        assert(size >= 0);

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

static void PrintAssertExpectedMessageBool(const char* format, size_t actual, size_t expected)
{
        bool a = actual;
        bool e = expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageChar(const char* format, size_t actual, size_t expected)
{
        char a = actual;
        char e = expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageInt(const char* format, size_t actual, size_t expected)
{
        int a = actual;
        int e = expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageString(const char* format, size_t actual, size_t expected)
{
        typedef const char* string;
        string a = (string)actual;
        string e = (string)expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessagePointer(const char* format, size_t actual, size_t expected)
{
        typedef void* pointer;
        pointer a = (pointer)actual;
        pointer e = (pointer)expected;
        UTILS_LOG(format, UTYPE(e), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageBoolArray(const char* format, size_t actual, size_t expected, int index)
{
        bool* a = (bool*)actual;
        bool* e = (bool*)expected;
        UTILS_LOG(format, UTYPE(e[index]), UTYPE(a[index]), UTYPE(index));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageCharArray(const char* format, size_t actual, size_t expected, int index)
{
        char* a = (char*)actual;
        char* e = (char*)expected;
        UTILS_LOG(format, UTYPE(e[index]), UTYPE(a[index]), UTYPE(index));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageIntArray(const char* format, size_t actual, size_t expected, int index)
{
        int* a = (int*)actual;
        int* e = (int*)expected;
        UTILS_LOG(format, UTYPE(e[index]), UTYPE(a[index]), UTYPE(index));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageStringArray(const char* format, size_t actual, size_t expected, int index)
{
        typedef const char* string;
        string* a = (string*)actual;
        string* e = (string*)expected;
        UTILS_LOG(format, UTYPE(e[index]), UTYPE(a[index]), UTYPE(index));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessagePointerArray(const char* format, size_t actual, size_t expected, int index)
{
        typedef void* pointer;
        pointer* a = (pointer*)actual;
        pointer* e = (pointer*)expected;
        UTILS_LOG(format, UTYPE(e[index]), UTYPE(a[index]), UTYPE(index));
}

////////////////////////////////////////////////////////////////////////////////

void utils_Assert(const char* file, const char* func, int line, UtilsOp operation, ...)
{
        va_list args;
        va_start(args, operation);

        FormatType type = va_arg(args, FormatType);
        size_t lhs = va_arg(args, size_t);
        size_t rhs = va_arg(args, size_t);

        if (type.isArray)
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
                static bool (*compareFunctions[UTYPE_COUNT])(UtilsOp, UtilsType, size_t, size_t, size_t, int*) = {
                        CompareBoolArray, CompareCharArray, CompareIntArray,
                        CompareIntArray,  CompareIntArray,  CompareStringArray,
                };
                static void (*printFunctions[UTYPE_COUNT])(const char*, size_t, size_t, int) = {
                        PrintAssertExpectedMessageBoolArray,    PrintAssertExpectedMessageCharArray,
                        PrintAssertExpectedMessageIntArray,     PrintAssertExpectedMessageIntArray,
                        PrintAssertExpectedMessagePointerArray, PrintAssertExpectedMessageStringArray,
                };

                bool (*compareFunction)(UtilsOp, UtilsType, size_t, size_t, size_t, int*) =
                        compareFunctions[type.basicType];
                void (*printFunction)(const char*, size_t, size_t, int) = printFunctions[type.basicType];
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
                static bool (*compareFunctions[UTYPE_COUNT])(UtilsOp, UtilsType, size_t, size_t) = {
                        CompareInt, CompareInt, CompareInt, CompareInt, CompareInt, CompareString,
                };
                static void (*printFunctions[UTYPE_COUNT])(const char*, size_t, size_t) = {
                        PrintAssertExpectedMessageBool,    PrintAssertExpectedMessageChar,
                        PrintAssertExpectedMessageInt,     PrintAssertExpectedMessageInt,
                        PrintAssertExpectedMessagePointer, PrintAssertExpectedMessageString,
                };

                bool (*compareFunction)(UtilsOp, UtilsType, size_t, size_t) = compareFunctions[type.basicType];
                void (*printFunction)(const char*, size_t, size_t) = printFunctions[type.basicType];
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

static bool CompareBoolInArray(UtilsType type, size_t lhs, size_t rhs, int size)
{
        assert(size >= 0 && rhs != 0);

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

static bool CompareCharInArray(UtilsType type, size_t lhs, size_t rhs, int size)
{
        assert(size >= 0 && rhs != 0);

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

static bool CompareIntInArray(UtilsType type, size_t lhs, size_t rhs, int size)
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

static bool ComparePointerInArray(UtilsType type, size_t lhs, size_t rhs, int size)
{
        assert(size >= 0 && rhs != 0);

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

static bool CompareStringInArray(UtilsType type, size_t lhs, size_t rhs, int size)
{
        typedef const char* string;
        assert(size >= 0 && rhs != 0);

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

static void PrintAssertExpectedMessageBoolInArray(const char* format, size_t actual, size_t expected, int size)
{
        bool a = actual;
        bool* e = (bool*)expected;
        UTILS_LOG(format, UARRAY(e, size), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageCharInArray(const char* format, size_t actual, size_t expected, int size)
{
        char a = actual;
        char* e = (char*)expected;
        UTILS_LOG(format, UARRAY(e, size), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageIntInArray(const char* format, size_t actual, size_t expected, int size)
{
        int a = actual;
        int* e = (int*)expected;
        UTILS_LOG(format, UARRAY(e, size), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessagePointerInArray(const char* format, size_t actual, size_t expected, int size)
{
        typedef void* pointer;
        pointer a = (pointer)actual;
        pointer* e = (pointer*)expected;
        UTILS_LOG(format, UARRAY(e, size), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageStringInArray(const char* format, size_t actual, size_t expected, int size)
{
        typedef const char* string;
        string a = (string)actual;
        string* e = (string*)expected;
        UTILS_LOG(format, UARRAY(e, size), UTYPE(a));
}

////////////////////////////////////////////////////////////////////////////////

void utils_AssertInArray(const char* file, const char* func, int line, UtilsType type, ...)
{
        va_list args;
        va_start(args, type);

        size_t lhs = va_arg(args, size_t);
        size_t rhs = va_arg(args, size_t);
        int size = va_arg(args, int);

        va_end(args);

        static bool (*compareFunctions[UTYPE_COUNT])(UtilsType, size_t, size_t, int) = {
                CompareBoolInArray, CompareCharInArray,    CompareIntInArray,
                CompareIntInArray,  ComparePointerInArray, CompareStringInArray,
        };
        static void (*printFunctions[UTYPE_COUNT])(const char*, size_t, size_t, int) = {
                PrintAssertExpectedMessageBoolInArray,    PrintAssertExpectedMessageCharInArray,
                PrintAssertExpectedMessageIntInArray,     PrintAssertExpectedMessageIntInArray,
                PrintAssertExpectedMessagePointerInArray, PrintAssertExpectedMessageStringInArray,
        };

        bool (*compareFunction)(UtilsType, size_t, size_t, int) = compareFunctions[type];
        void (*printFunction)(const char*, size_t, size_t, int) = printFunctions[type];
        while (!compareFunction(type, lhs, rhs, size))
        {
                UTILS_LOG("\n-----------------------------------------------------");
                UTILS_LOG("FAILED: {}", UTYPE(func));
                UTILS_LOG("File {} at line {}:", UTYPE(file), UTYPE(line));
                printFunction("Expected {} got {}.", lhs, rhs, size);
                UTILS_LOG("-----------------------------------------------------\n");
                UTILS_TRAP;
        }
}

////////////////////////////////////////////////////////////////////////////////

bool CompareCountEqual(UtilsType type, size_t* lhs, size_t* lhsSize, size_t* rhs, size_t* rhsSize, size_t count,
                       int* index)
{
        static bool (*compareFunctions[UTYPE_COUNT])(UtilsOp, UtilsType, size_t, size_t, size_t, int*) = {
                CompareBoolArray, CompareCharArray, CompareIntArray,
                CompareIntArray,  CompareIntArray,  CompareStringArray,
        };

        for (int i = 0; i < count; i++)
        {
                bool found = false;
                for (int j = 0; j < count; j++)
                {

                        found = lhsSize[i] == rhsSize[j] &&
                                compareFunctions[type](UOP_EQUAL, type, lhs[i], rhs[j], lhsSize[i], index);
                        if (found)
                                break;
                }
                if (!found)
                {
                        *index = i;
                        return false;
                }
        }
        return true;
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageBoolArrayInArray(size_t actualCount, size_t expectedCount, size_t sample,
                                                       size_t size)
{
        int a = actualCount;
        int e = expectedCount;
        bool* arr = (bool*)sample;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(e), UTYPE(a), UARRAY(arr, size));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageCharArrayInArray(size_t actualCount, size_t expectedCount, size_t sample,
                                                       size_t size)
{
        int a = actualCount;
        int e = expectedCount;
        char* arr = (char*)sample;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(e), UTYPE(a), UARRAY(arr, size));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageIntArrayInArray(size_t actualCount, size_t expectedCount, size_t sample,
                                                      size_t size)
{
        int a = actualCount;
        int e = expectedCount;
        int* arr = (int*)sample;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(e), UTYPE(a), UARRAY(arr, size));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessagePointerArrayInArray(size_t actualCount, size_t expectedCount, size_t sample,
                                                          size_t size)
{
        typedef void* pointer;
        int a = actualCount;
        int e = expectedCount;
        pointer* arr = (pointer*)sample;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(e), UTYPE(a), UARRAY(arr, size));
}

////////////////////////////////////////////////////////////////////////////////

static void PrintAssertExpectedMessageStringArrayInArray(size_t actualCount, size_t expectedCount, size_t sample,
                                                         size_t size)
{
        typedef const char* string;
        int a = actualCount;
        int e = expectedCount;
        string* arr = (string*)sample;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(a), UTYPE(e), UARRAY(arr, size));
}

////////////////////////////////////////////////////////////////////////////////

static bool is_equal(size_t i_actual, size_t i_expected, size_t i_stride, UtilsType i_type)
{
        if (i_type == UTYPE_STRING)
        {
                typedef const char* string;
                string lhs = (string)i_actual;
                string rhs = (string)i_expected;
                return !strcmp(lhs, rhs);
        }
        else
        {
                const size_t mask = ((size_t)-1) >> (sizeof(size_t) - i_stride) * 8;
                const size_t lhs = *(size_t*)i_actual & mask;
                const size_t rhs = *(size_t*)i_expected & mask;
                return lhs == rhs;
        }
}

////////////////////////////////////////////////////////////////////////////////

static bool is_equal_array(size_t i_actual, size_t i_expected, size_t i_size, size_t i_stride, UtilsType i_type)
{
        typedef const char* string;

        const size_t mask = ((size_t)-1) >> (sizeof(size_t) - i_stride) * 8;
        for (size_t i = 0; i < i_size; i += i_stride)
        {
                if (i_type == UTYPE_STRING)
                {
                        const string lhs = (string)(i_actual + i);
                        const string rhs = (string)(i_expected + i);
                        if (!strcmp(lhs, rhs))
                                return false;
                }
                else
                {
                        const size_t lhs = *(size_t*)(i_actual + i) & mask;
                        const size_t rhs = *(size_t*)(i_expected + i) & mask;
                        if (lhs != rhs)
                                return false;
                }
        }
        return true;
}

////////////////////////////////////////////////////////////////////////////////

static size_t* construct_count_set(size_t i_data, size_t i_size, size_t i_stride, UtilsType i_type)
{
        size_t* set = calloc(i_size, sizeof(*set));
        for (size_t i = 0; i < i_size; i++)
        {
                if (set[i] == -1)
                        continue;

                set[i] = 1;
                for (size_t j = i + 1; j < i_size; j++)
                {
                        if (!is_equal(i_data + i * i_stride, i_data + j * i_stride, i_stride, i_type))
                                continue;

                        set[i]++;
                        set[j] = -1;
                }
        }
        return set;
}

////////////////////////////////////////////////////////////////////////////////

static size_t* construct_count_array_set(size_t i_data, size_t i_size, size_t i_count, size_t i_stride,
                                         size_t i_size_stride, UtilsType i_type)
{
        const size_t mask = ((size_t)-1) >> (sizeof(size_t) - i_size_stride) * 8;
        size_t* data = (size_t*)i_data;
        size_t* set = calloc(i_count, sizeof(*set));
        for (size_t i = 0; i < i_count; i++)
        {
                if (set[i] == -1)
                        continue;

                set[i] = 1;
                for (size_t j = i + 1; j < i_count; j++)
                {
                        const size_t size = *(size_t*)(i_size + j * i_size_stride) & mask;
                        if (!is_equal(i_size + i * i_size_stride, i_size + j * i_size_stride, i_size_stride, i_type) ||
                            !is_equal_array(data[i], data[j], size, i_stride, i_type))
                                continue;

                        set[i]++;
                        set[j] = -1;
                }
        }
        return set;
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_fail_bool(size_t i_actual_count, size_t i_expected_count, size_t i_value)
{
        bool value = *(bool*)i_value;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UTYPE(value));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_fail_char(size_t i_actual_count, size_t i_expected_count, size_t i_value)
{
        char value = *(char*)i_value;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UTYPE(value));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_fail_int(size_t i_actual_count, size_t i_expected_count, size_t i_value)
{
        int value = *(int*)i_value;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UTYPE(value));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_fail_uint64(size_t i_actual_count, size_t i_expected_count, size_t i_value)
{
        uint64_t value = *(uint64_t*)i_value;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UTYPE(value));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_fail_pointer(size_t i_actual_count, size_t i_expected_count, size_t i_value)
{
        typedef void* pointer;
        pointer value = *(pointer*)i_value;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UTYPE(value));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_fail_string(size_t i_actual_count, size_t i_expected_count, size_t i_value)
{
        typedef const char* string;
        string value = *(string*)i_value;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UTYPE(value));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_array_fail_bool(size_t i_actual_count, size_t i_expected_count, size_t i_data,
                                              size_t i_size)
{
        bool* data = (bool*)i_data;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UARRAY(data, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_array_fail_char(size_t i_actual_count, size_t i_expected_count, size_t i_data,
                                              size_t i_size)
{
        char* data = (char*)i_data;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UARRAY(data, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_array_fail_int(size_t i_actual_count, size_t i_expected_count, size_t i_data,
                                             size_t i_size)
{
        int* data = (int*)i_data;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UARRAY(data, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_array_fail_uint64(size_t i_actual_count, size_t i_expected_count, size_t i_data,
                                                size_t i_size)
{
        uint64_t* data = (uint64_t*)i_data;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UARRAY(data, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_array_fail_pointer(size_t i_actual_count, size_t i_expected_count, size_t i_data,
                                                 size_t i_size)
{
        typedef void* pointer;
        pointer* data = (pointer*)i_data;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UARRAY(data, i_size));
}

////////////////////////////////////////////////////////////////////////////////

static void print_count_equal_array_fail_string(size_t i_actual_count, size_t i_expected_count, size_t i_data,
                                                size_t i_size)
{
        typedef const char* string;
        string* data = (string*)i_data;
        UTILS_LOG("Expected to have {} but actually got {}: {}", UTYPE(i_expected_count), UTYPE(i_actual_count),
                  UARRAY(data, i_size));
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_count_equal(const char* i_file, const char* i_func, int i_line, UtilsType i_type, size_t i_actual,
                              size_t i_expected, size_t i_size, size_t i_stride)
{
        size_t* actual_set = construct_count_set(i_actual, i_size, i_stride, i_type);
        size_t* expected_set = construct_count_set(i_expected, i_size, i_stride, i_type);

        static void (*print_fail_funtions[UTYPE_COUNT])(size_t, size_t, size_t) = {
                print_count_equal_fail_bool,   print_count_equal_fail_char,    print_count_equal_fail_int,
                print_count_equal_fail_uint64, print_count_equal_fail_pointer, print_count_equal_fail_string,
        };

        bool is_asserted = false;
        for (size_t i = 0; i < i_size; i++)
        {
                if (actual_set[i] == -1)
                        continue;

                size_t j, min = 0, actual_remain = actual_set[i], expected_remain = 0;
                for (j = 0; j < i_size; j++)
                {
                        if (expected_set[j] == -1)
                                continue;

                        if (!is_equal(i_actual + i * i_stride, i_expected + j * i_stride, i_stride, i_type))
                                continue;

                        min = actual_set[i] < expected_set[j] ? actual_set[i] : expected_set[j];
                        actual_remain -= min;
                        expected_remain = expected_set[j] - min;
                        break;
                }

                actual_set[i] = -1;
                if (j < i_size)
                        expected_set[j] = -1;

                if (actual_remain == expected_remain && actual_remain == 0)
                        continue;

                if (!is_asserted)
                {
                        UTILS_LOG("\n-----------------------------------------------------");
                        UTILS_LOG("FAILED: {}", UTYPE(i_func));
                        UTILS_LOG("File {} at line {}:", UTYPE(i_file), UTYPE(i_line));
                        is_asserted = true;
                }

                print_fail_funtions[i_type](actual_remain + min, expected_remain + min, i_actual + i * i_stride);
        }

        for (size_t i = 0; i < i_size; i++)
        {
                if (expected_set[i] == -1)
                        continue;

                print_fail_funtions[i_type](0, expected_set[i], i_expected + i * i_stride);
                expected_set[i] = -1;
        }

        free(actual_set);
        free(expected_set);

        while (is_asserted)
        {
                UTILS_LOG("-----------------------------------------------------\n");
                UTILS_TRAP;
        }
}

////////////////////////////////////////////////////////////////////////////////

void utils_assert_count_equal_array(const char* i_file, const char* i_func, int i_line, UtilsType i_type,
                                    size_t i_actual, size_t i_actual_size, size_t i_expected, size_t i_expected_size,
                                    size_t i_count, size_t i_stride, size_t i_size_stride)
{
        const size_t mask = ((size_t)-1) >> (sizeof(size_t) - i_size_stride) * 8;
        size_t* actual = (size_t*)i_actual;
        size_t* expected = (size_t*)i_expected;
        size_t* actual_set =
                construct_count_array_set(i_actual, i_actual_size, i_count, i_stride, i_size_stride, i_type);
        size_t* expected_set =
                construct_count_array_set(i_expected, i_expected_size, i_count, i_stride, i_size_stride, i_type);

        static void (*print_fail_funtions[UTYPE_COUNT])(size_t, size_t, size_t, size_t) = {
                print_count_equal_array_fail_bool,    print_count_equal_array_fail_char,
                print_count_equal_array_fail_int,     print_count_equal_array_fail_uint64,
                print_count_equal_array_fail_pointer, print_count_equal_array_fail_string,
        };

        bool is_asserted = false;
        for (size_t i = 0; i < i_count; i++)
        {
                if (actual_set[i] == -1)
                        continue;

                size_t j, min = 0, actual_remain = actual_set[i], expected_remain = 0;
                const size_t actual_size = *(size_t*)(i_actual_size + i * i_size_stride) & mask;
                for (j = 0; j < i_count; j++)
                {
                        if (expected_set[j] == -1)
                                continue;

                        if (!is_equal(i_actual_size + i * i_size_stride, i_expected_size + j * i_size_stride,
                                      i_size_stride, i_type) ||
                            !is_equal_array(actual[i], expected[j], actual_size, i_stride, i_type))
                                continue;

                        min = actual_set[i] < expected_set[j] ? actual_set[i] : expected_set[j];
                        actual_remain -= min;
                        expected_remain = expected_set[j] - min;
                        break;
                }

                actual_set[i] = -1;
                if (j < i_count)
                        expected_set[j] = -1;

                if (actual_remain == expected_remain && actual_remain == 0)
                        continue;

                if (!is_asserted)
                {
                        UTILS_LOG("\n-----------------------------------------------------");
                        UTILS_LOG("FAILED: {}", UTYPE(i_func));
                        UTILS_LOG("File {} at line {}:", UTYPE(i_file), UTYPE(i_line));
                        is_asserted = true;
                }

                print_fail_funtions[i_type](actual_remain + min, expected_remain + min, actual[i], actual_size);
        }

        for (size_t i = 0; i < i_count; i++)
        {
                if (expected_set[i] == -1)
                        continue;

                const size_t expected_size = (i * i_size_stride)[(size_t*)i_expected_size] & mask;
                print_fail_funtions[i_type](0, expected_set[i], expected[i], expected_size);
                expected_set[i] = -1;
        }

        free(actual_set);
        free(expected_set);

        while (is_asserted)
        {
                UTILS_LOG("-----------------------------------------------------\n");
                UTILS_TRAP;
        }
}

////////////////////////////////////////////////////////////////////////////////
