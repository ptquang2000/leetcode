#include "utils.h"

// Declaration:
int** Recursion_combinations(int n, int k, int* o_size);

void test_Recursion_combinations()
{
        {
                const int k = 2;
                int expected[][2] = {
                        {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4},
                };
                int actualSize;
                int** actual = Recursion_combinations(4, k, &actualSize);
                UTILS_ASSERT_EQUAL(actualSize, sizeof(expected) / sizeof(*expected));
                //UTILS_ASSERT_EQUAL(actual, expected, sizeof(expected) / sizeof(*expected), k);
        }
}
