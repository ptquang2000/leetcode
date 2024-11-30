#include "pch.h"
#include "utils.h"

// Declaration:
void ArrayString_applyPermutation(int* perm, int permSize, char* A, int ASize);

void test_ArrayString_applyPermutation()
{
	printf("hello from applyPermutation\n");

	char* A;
	const char expected1[] = {'d', 'c', 'b', 'a'};
	const char expected2[] = {'b', 'c', 'a', 'd' };

	A = malloc(4 * sizeof(*A));

	UTILS_ASSERT_EQUAL(A, expected1, 4);
	UTILS_ASSERT_EQUAL(A, expected2, 4);

	free(A);
}
