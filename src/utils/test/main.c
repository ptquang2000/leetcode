#include "utils/asserts.h"
#include "utils/logger.h"

int main()
{
        char_obj c1 = {'x'};
        char_obj c2 = {'y'};
        string_obj s1 = {"8==D"};
        string_obj s2 = {"B00B5"};
        short_obj sh1 = {69};
        short_obj sh2 = {420};
        int_obj i1 = {69420};
        int_obj i2 = {42069};
        size_t_obj st1 = {696969696966969};
        size_t_obj st2 = {420420420420420};
        double_obj d1 = {69.60};
        double_obj d2 = {420.420};
        bool_obj b1 = {true};
        bool_obj b2 = {false};

        char_array ca1 = {(char[]){'B', '0', '0', 'B', '5'}, 5};
        char_array ca2 = {(char[]){'B', '0', 'O', 'B', 'S'}, 5};
        string_array sa1 = {(string[]){"GOAT", "ghosting", "mid", "vibe check", "sus"}, 5};
        string_array sa2 = {(string[]){"slay", "bet", "low-key", "extra", "flex"}, 5};
        short_array sha1 = {(short[]){31, 82, 32, 55, 2}, 5};
        short_array sha2 = {(short[]){42, 51, 75, 31, 53}, 5};
        int_array ia1 = {(int[]){326239, 559855, 445399, 828639, 190305}, 5};
        int_array ia2 = {(int[]){390227, 556859, 992170, 397070, 254049}, 5};
        size_t_array sta1 = {(size_t[]){9957835168, 1633598403, 1951010168, 6105680956, 8459731783}, 5};
        size_t_array sta2 = {(size_t[]){2925128758, 9788141779, 5363541390, 1169019322, 1843586698}, 5};
        double_array da1 = {(double[]){61.45505, 87.13806, 63.85903, 06.66105, 81.98509}, 5};
        double_array da2 = {(double[]){70.27696, 10.38040, 80.59800, 85.91704, 96.60537}, 5};
        bool_array ba1 = {(bool[]){true, false, true, true, false}, 10};
        bool_array ba2 = {(bool[]){false, false, true, false, false}, 10};

        int_obj i3 = {3};
        int_array ia3 = {(int[]){1, 2, 3, 4, 5}, 5};
        int_array ia4 = {(int[]){2, 3, 4, 5, 6}, 5};
        int_array ia5 = {(int[]){3, 4, 5, 6, 7}, 5};
        int_array ia6 = {(int[]){4, 5, 6, 7, 8}, 5};
        int_array ia7 = {(int[]){5, 6, 7, 8, 9}, 5};
        int_array ia8 = {(int[]){6, 7, 8, 9, 10}, 5};
        int_array ia9 = {(int[]){10, 12, 12, 12, 14}, 5};
        int_array ia10 = {(int[]){11, 12, 13, 14, 15}, 5};
        int_array ia11 = {(int[]){12, 13, 14, 15, 16}, 5};
        int_array ia12 = {(int[]){16, 15, 14, 13, 12}, 5};
        int_darray ida1 = {
                (int *[]){
                        (int[]){1, 2, 3, 4, 5, 6},
                        (int[]){1, 2, 3, 4, 5},
                        (int[]){1, 2, 3, 4},
                        (int[]){1, 2, 3},
                        (int[]){1, 2},
                        (int[]){1},
                },
                (int[]){6, 5, 4, 3, 2, 1},
                6,
        };
        int_darray ida2 = {
                (int *[]){
                        (int[]){1},
                        (int[]){1, 2},
                        (int[]){1, 2, 3},
                        (int[]){1, 2, 3, 4},
                        (int[]){1, 2, 3, 4, 5},
                        (int[]){1, 2, 3, 4, 5, 6},
                },
                (int[]){1, 2, 3, 4, 5, 6},
                6,
        };
        int_darray ida3 = {
                (int *[]){
                        (int[]){2, 3, 4, 5, 6, 7},
                        (int[]){3, 4, 5, 6, 7},
                        (int[]){4, 5, 6, 7},
                        (int[]){5, 6, 7},
                        (int[]){6, 7},
                        (int[]){7},
                },
                (int[]){6, 5, 4, 3, 2, 1},
                6,
        };
        int_darray ida4 = {
                (int *[]){
                        (int[]){7},
                        (int[]){6, 7},
                        (int[]){5, 6, 7},
                        (int[]){4, 5, 6, 7},
                        (int[]){3, 4, 5, 6, 7},
                        (int[]){2, 3, 4, 5, 6, 7},
                },
                (int[]){1, 2, 3, 4, 5, 6},
                6,
        };
        int_darray ida5 = {
                (int *[]){
                        (int[]){3, 4, 5, 6, 7, 6},
                        (int[]){3, 4, 5, 6, 7},
                        (int[]){3, 4, 5, 6},
                        (int[]){3, 4, 5},
                        (int[]){3, 4},
                        (int[]){3},
                },
                (int[]){6, 5, 4, 3, 2, 1},
                6,
        };
        int_darray ida6 = {
                (int *[]){
                        (int[]){3},
                        (int[]){3, 4},
                        (int[]){3, 4, 5},
                        (int[]){3, 4, 5, 6},
                        (int[]){3, 4, 5, 6, 7},
                        (int[]){3, 4, 5, 6, 7, 6},
                },
                (int[]){1, 2, 3, 4, 5, 6},
                6,
        };
        _Container actnr1 = {(void *[]){&ia3, &ia4, &ia5, &ia6, &ia7, &ia8}, 5};
        _Container actnr2 = {(void *[]){&ia7, &ia8, &ia9, &ia10, &ia11, &ia12}, 5};
        _Container dactnr1 = {(void *[]){&ida1, &ida2, &ida4, &ida5, &ida6}, 5};
        _Container dactnr2 = {(void *[]){&ida1, &ida2, &ida3, &ida4, &ida5}, 5};

        UTILS_LOG("----- loggers -----");
        UTILS_LOG("c1={}, s1={}, sh1={}, i1={}, st1={}, d1={}, b1={}", c1, s1, sh1, i1, st1, d1, b1);
        UTILS_LOG("c2={}, s2={}, sh2={}, i2={}, st2={}, d2={}, b2={}", c2, s2, sh2, i2, st2, d2, b2);
        UTILS_LOG("ca1={}, ca2={}", ca1, ca2);
        UTILS_LOG("sa1={}, sa2={}", sa1, sa2);
        UTILS_LOG("sha1={}, sha2={}", sha1, sha2);
        UTILS_LOG("ia1={}, ia2={}", ia1, ia2);
        UTILS_LOG("sta1={}, sta2={}", sta1, sta2);
        UTILS_LOG("da1={}, da2={}", da1, da2);
        UTILS_LOG("ba1={}, ba2={}", ba1, ba2);
        UTILS_LOG("ida1={}, ida2={}", ida1, ida2);

        UTILS_LOG("----- assert_equal:passed -----");
        ASSERT_EQUAL(c1, c1);
        ASSERT_EQUAL(c2, c2);
        ASSERT_EQUAL(s1, s1);
        ASSERT_EQUAL(s2, s2);
        ASSERT_EQUAL(sh1, sh1);
        ASSERT_EQUAL(sh2, sh2);
        ASSERT_EQUAL(i1, i1);
        ASSERT_EQUAL(i2, i2);
        ASSERT_EQUAL(st1, st1);
        ASSERT_EQUAL(st2, st2);
        ASSERT_EQUAL(d1, d1);
        ASSERT_EQUAL(d2, d2);
        ASSERT_EQUAL(b1, b1);
        ASSERT_EQUAL(b2, b2);
        ASSERT_EQUAL(ida1, ida1);

        UTILS_LOG("----- assert_equal:failed -----");
        ASSERT_EQUAL(ca1, ca1);
        ASSERT_EQUAL(ca2, ca2);
        ASSERT_EQUAL(sa1, sa1);
        ASSERT_EQUAL(sa2, sa2);
        ASSERT_EQUAL(sha1, sha1);
        ASSERT_EQUAL(sha2, sha2);
        ASSERT_EQUAL(ia1, ia1);
        ASSERT_EQUAL(ia2, ia2);
        ASSERT_EQUAL(sta1, sta1);
        ASSERT_EQUAL(sta2, sta2);
        ASSERT_EQUAL(da1, da1);
        ASSERT_EQUAL(da2, da2);
        ASSERT_EQUAL(ba1, ba1);
        ASSERT_EQUAL(ba2, ba2);

        ASSERT_EQUAL(c1, c2);
        ASSERT_EQUAL(s1, s2);
        ASSERT_EQUAL(sh1, sh2);
        ASSERT_EQUAL(i1, i2);
        ASSERT_EQUAL(st1, st2);
        ASSERT_EQUAL(d1, d2);
        ASSERT_EQUAL(b1, b2);

        ASSERT_EQUAL(ca1, ca2);
        ASSERT_EQUAL(sa1, sa2);
        ASSERT_EQUAL(sha1, sha2);
        ASSERT_EQUAL(ia1, ia2);
        ASSERT_EQUAL(sta1, sta2);
        ASSERT_EQUAL(da1, da2);
        ASSERT_EQUAL(ba1, ba2);

        ASSERT_EQUAL(ida1, ida2);

        UTILS_LOG("----- assert_in:passed -----");
        ASSERT_IN(i3, ia3);
        ASSERT_IN(ia6, actnr1);
        ASSERT_IN(ida6, dactnr1);

        UTILS_LOG("----- assert_in:failed -----");
        ASSERT_IN(i3, ia6);
        ASSERT_IN(ia6, actnr2);
        ASSERT_IN(ida6, dactnr2);

        UTILS_LOG("----- assert_count_equal:passed -----");
        ASSERT_COUNT_EQUAL(ia11, ia11);
        ASSERT_COUNT_EQUAL(ia11, ia12);
        ASSERT_COUNT_EQUAL(ida1, ida2);

        UTILS_LOG("----- assert_count_equal:failed -----");
        ASSERT_COUNT_EQUAL(ia9, ia12);
        ASSERT_COUNT_EQUAL(ia10, ia11);
        ASSERT_COUNT_EQUAL(ida2, ida3);
}
