#define TEST_UTILS
#include "utils/utils.c"
#include <stddef.h>
#include <stdint.h>

int main()
{
        bool trueValue = true;
        bool falseValue = false;
        int intValue = 69420;
        char xValue = 'x';
        char charValue = '=';
        char DValue = 'D';
        const char *stringValue = "B==D";
        const char *B0085 = "B0085";
        void *noneValue = 0;
        bool boolArrayExpected[3] = {true, false, true};
        bool boolArrayActual1[3] = {true, false, true};
        bool boolArrayActual2[3] = {true, true, true};
        char charArrayExpected[3] = {'x', 'x', 'x'};
        char charArrayActual1[3] = {'x', 'x', 'x'};
        char charArrayActual2[3] = {'x', 'y', 'x'};
        int intArrayExpected[3] = {69, 69, 69};
        int intArrayActual1[3] = {69, 69, 69};
        int intArrayActual2[3] = {69, 420, 69};
        const char *stringArrayExpected[3] = {"B==D", "B==D", "B==D"};
        const char *stringArrayActual1[3] = {"B==D", "B==D", "B==D"};
        const char *stringArrayActual2[3] = {"B==D", "B0085", "B==D"};
        int intArrayIn[3] = {69420, 69420, 69420};

        UTILS_LOG("\nTest UTILS_LOG\n");
        UTILS_LOG("bool:{}/{}, char:{}, int:{}, string:{}", UTYPE(trueValue), UTYPE(falseValue), UTYPE(charValue),
                  UTYPE(intValue), UTYPE(stringValue));
        UTILS_LOG("bool array:{}, char array:{}, int array:{}, string array:{}", UARRAY(intArrayActual2, 3),
                  UARRAY(charArrayActual2, 3), UTYPE(intValue), UARRAY(stringArrayExpected, 3));

        UTILS_LOG("\nTest UTILS_ASSERT_EQUAL bool");
        UTILS_ASSERT_EQUAL(trueValue, trueValue);
        UTILS_ASSERT_EQUAL(trueValue, falseValue);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL char");
        UTILS_ASSERT_EQUAL(xValue, xValue);
        UTILS_ASSERT_EQUAL(charValue, DValue);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL int");
        UTILS_ASSERT_EQUAL(69, 69);
        UTILS_ASSERT_EQUAL(420, 69);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL string");
        UTILS_ASSERT_EQUAL(B0085, B0085);
        UTILS_ASSERT_EQUAL(B0085, stringValue);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL bool array");
        UTILS_ASSERT_EQUAL_ARRAY(boolArrayActual1, boolArrayExpected, 3);
        UTILS_ASSERT_EQUAL_ARRAY(boolArrayActual2, boolArrayExpected, 3);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL char array");
        UTILS_ASSERT_EQUAL_ARRAY(charArrayActual1, charArrayExpected, 3);
        UTILS_ASSERT_EQUAL_ARRAY(charArrayActual2, charArrayExpected, 3);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL int array");
        UTILS_ASSERT_EQUAL_ARRAY(intArrayActual1, intArrayExpected, 3);
        UTILS_ASSERT_EQUAL_ARRAY(intArrayActual2, intArrayExpected, 3);

        UTILS_LOG("Test UTILS_ASSERT_EQUAL string array");
        UTILS_ASSERT_EQUAL_ARRAY(stringArrayActual1, stringArrayExpected, 3);
        UTILS_ASSERT_EQUAL_ARRAY(stringArrayActual2, stringArrayExpected, 3);

        UTILS_LOG("Test UTILS_ASSERT_IS");
        UTILS_ASSERT_IS(stringArrayExpected, stringArrayExpected);
        UTILS_ASSERT_IS(stringArrayActual1, stringArrayExpected);

        UTILS_LOG("Test UTILS_ASSERT_IS_NONE");
        UTILS_ASSERT_IS_NONE(noneValue);
        UTILS_ASSERT_IS_NONE(stringArrayExpected);

        UTILS_LOG("Test UTILS_ASSERT_IN bool array");
        UTILS_ASSERT_IN(trueValue, boolArrayActual2, 3);
        UTILS_ASSERT_IN(falseValue, boolArrayActual2, 3);

        UTILS_LOG("Test UTILS_ASSERT_IN char array");
        UTILS_ASSERT_IN(xValue, charArrayExpected, 3);
        UTILS_ASSERT_IN(charValue, charArrayExpected, 3);

        UTILS_LOG("Test UTILS_ASSERT_IN int array");
        UTILS_ASSERT_IN(intValue, intArrayIn, 3);
        UTILS_ASSERT_IN(intValue, intArrayExpected, 3);

        UTILS_LOG("Test UTILS_ASSERT_IN string array");
        UTILS_ASSERT_IN(stringValue, stringArrayExpected, 3);
        UTILS_ASSERT_IN(B0085, stringArrayExpected, 3);

        bool trues[] = {true, true, true, true, true};
        bool falses[] = {false, false, false, false, false};
        bool alt_bool[] = {true, false, true, false, true};
        size_t trues_size = sizeof(trues) / sizeof(*trues);

        UTILS_LOG("Test UTILS_ASSERT_COUNT_EQUAL bool");
        UTILS_ASSERT_COUNT_EQUAL(trues, trues, trues_size);
        UTILS_ASSERT_COUNT_EQUAL(trues, falses, trues_size);
        UTILS_ASSERT_COUNT_EQUAL(trues, alt_bool, trues_size);

        char abcde[] = {'a', 'b', 'c', 'd', 'e'};
        char fghij[] = {'f', 'g', 'h', 'i', 'j'};
        char edcba[] = {'e', 'd', 'c', 'b', 'a'};
        char bfdde[] = {'b', 'f', 'd', 'd', 'e'};
        size_t abc_size = sizeof(abcde) / sizeof(*abcde);

        UTILS_LOG("Test UTILS_ASSERT_COUNT_EQUAL char");
        UTILS_ASSERT_COUNT_EQUAL(abcde, fghij, abc_size);
        UTILS_ASSERT_COUNT_EQUAL(abcde, edcba, abc_size);
        UTILS_ASSERT_COUNT_EQUAL(abcde, bfdde, abc_size);

        UTILS_LOG("Test UTILS_ASSERT_COUNT_EQUAL_ARRAY char");
        char aa[] = {'a', 'a'};
        char bbb[] = {'b', 'b', 'b'};
        char cccc[] = {'c', 'c', 'c', 'c', 'c'};
        char ddddd[] = {'d', 'd', 'd', 'd', 'd'};
        char e[] = {'e'};
        size_t aa_size = sizeof(aa) / sizeof(*aa);
        size_t bbb_size = sizeof(bbb) / sizeof(*bbb);
        size_t cccc_size = sizeof(cccc) / sizeof(*cccc);
        size_t ddddd_size = sizeof(ddddd) / sizeof(*ddddd);
        size_t e_size = sizeof(e) / sizeof(*e);
        char *abcd_array[] = {aa, bbb, cccc, ddddd};
        size_t abcd_array_size[] = {aa_size, bbb_size, cccc_size, ddddd_size};
        char *bdac_array[] = {bbb, ddddd, aa, cccc};
        size_t bdac_array_size[] = {bbb_size, ddddd_size, aa_size, cccc_size};
        char *bdeac_array[] = {bbb, ddddd, e, aa, cccc};
        size_t bdeac_array_size[] = {bbb_size, ddddd_size, e_size, aa_size, cccc_size};
        char *bceac_array[] = {bbb, cccc, e, cccc, aa};
        size_t bceac_array_size[] = {bbb_size, cccc_size, e_size, cccc_size, aa_size};
        size_t abcd_array_count = sizeof(abcd_array_size) / sizeof(*abcd_array_size);
        size_t bdeac_array_count = sizeof(bdeac_array_size) / sizeof(*bdeac_array_size);
        UTILS_ASSERT_COUNT_EQUAL_ARRAY(abcd_array, abcd_array_size, abcd_array, abcd_array_size, abcd_array_count);
        UTILS_ASSERT_COUNT_EQUAL_ARRAY(abcd_array, abcd_array_size, bdac_array, bdac_array_size, abcd_array_count);
        UTILS_ASSERT_COUNT_EQUAL_ARRAY(bdeac_array, bdeac_array_size, bceac_array, bceac_array_size, bdeac_array_count);

        int ones[] = {1, 1, 1, 1, 1};
        int twos[] = {2, 2, 2, 2, 2};
        int alt_ints[] = {1, 2, 3, 2, 3};
        size_t ones_size = sizeof(ones) / sizeof(*ones);

        UTILS_LOG("Test UTILS_ASSERT_COUNT_EQUAL int");
        UTILS_ASSERT_COUNT_EQUAL(ones, ones, ones_size);
        UTILS_ASSERT_COUNT_EQUAL(ones, twos, ones_size);
        UTILS_ASSERT_COUNT_EQUAL(ones, alt_ints, ones_size);

        int two_ones[] = {1, 1};
        int two_ones_size = sizeof(two_ones) / sizeof(*two_ones);
        int three_twos[] = {2, 2, 2};
        int three_twos_size = sizeof(three_twos) / sizeof(*three_twos);
        int one_three[] = {3};
        int one_three_size = sizeof(one_three) / sizeof(*one_three);
        int *one_two_three[] = {two_ones, three_twos, one_three};
        int one_two_three_size[] = {two_ones_size, three_twos_size, one_three_size};
        int *reverse_one_two_three[] = {one_three, three_twos, two_ones};
        int reverse_one_two_three_size[] = {one_three_size, three_twos_size, two_ones_size};
        int *one_one_three[] = {two_ones, two_ones, one_three};
        int one_one_three_size[] = {two_ones_size, two_ones_size, one_three_size};
        int int_array_count = sizeof(one_two_three_size) / sizeof(*one_two_three_size);

        UTILS_LOG("Test UTILS_ASSERT_COUNT_EQUAL_ARRAY int");
        UTILS_ASSERT_COUNT_EQUAL_ARRAY(one_two_three, one_two_three_size, one_two_three, one_two_three_size,
                                       int_array_count);
        UTILS_ASSERT_COUNT_EQUAL_ARRAY(one_two_three, one_two_three_size, reverse_one_two_three,
                                       reverse_one_two_three_size, int_array_count);
        UTILS_ASSERT_COUNT_EQUAL_ARRAY(one_two_three, one_two_three_size, one_one_three, one_one_three_size,
                                       int_array_count);

        const char *strings[] = {"69", "420", "69420"};
        uint32_t strings_size = sizeof(strings) / sizeof(*strings);
        const char *reversed_strings[] = {"69420", "420", "69"};
        uint32_t reversed_strings_size = sizeof(reversed_strings) / sizeof(*reversed_strings);
        const char *different_strings[] = {"80085", "B==D", "69420"};
        uint32_t different_strings_size = sizeof(different_strings) / sizeof(*different_strings);

        UTILS_LOG("Test UTILS_ASSERT_COUNT_EQUAL string");
        UTILS_ASSERT_COUNT_EQUAL(strings, strings, strings_size);
        UTILS_ASSERT_COUNT_EQUAL(strings, reversed_strings, strings_size);
        UTILS_ASSERT_COUNT_EQUAL(strings, different_strings, strings_size);

        int *matrix1[] = {
                (int[]){2, 5, 6, 69, 420, 69420},
                (int[]){1, 3, 9, 69, 420, 69420},
                (int[]){10, 24, 21, 69, 420, 69420},
        };
        int *matrix2[] = {
                (int[]){10, 24, 21, 69, 420, 69420},
                (int[]){2, 5, 6, 69, 420, 69420},
                (int[]){1, 3, 9, 69, 420, 69420},
        };
        int matrix_size[] = {6, 6, 6};

        UTILS_LOG("Test UTILS_ASSERT_EQUAL_MD_ARRAY int");
        UTILS_ASSERT_EQUAL_MD_ARRAY(matrix1, matrix1, matrix_size, ARRAY_SIZE(matrix_size));
        UTILS_ASSERT_EQUAL_MD_ARRAY(matrix1, matrix2, matrix_size, ARRAY_SIZE(matrix_size));
}
