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
        int_array ia9 = {(int[]){10, 11, 12, 13, 14}, 5};
        int_array ia10 = {(int[]){11, 12, 13, 14, 15}, 5};
        int_array ia11 = {(int[]){12, 13, 14, 15, 16}, 5};
        int_array ia12 = {(int[]){13, 14, 15, 16, 17}, 5};
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

        utils_log("----- loggers -----");
        utils_log("c1={}, s1={}, sh1={}, i1={}, st1={}, d1={}, b1={}", c1, s1, sh1, i1, st1, d1, b1);
        utils_log("c2={}, s2={}, sh2={}, i2={}, st2={}, d2={}, b2={}", c2, s2, sh2, i2, st2, d2, b2);
        utils_log("ca1={}, ca2={}", ca1, ca2);
        utils_log("sa1={}, sa2={}", sa1, sa2);
        utils_log("sha1={}, sha2={}", sha1, sha2);
        utils_log("ia1={}, ia2={}", ia1, ia2);
        utils_log("sta1={}, sta2={}", sta1, sta2);
        utils_log("da1={}, da2={}", da1, da2);
        utils_log("ba1={}, ba2={}", ba1, ba2);
        utils_log("ida1={}, ida2={}", ida1, ida2);

        utils_log("----- assert_equal:passed -----");
        assert_equal(c1, c1);
        assert_equal(c2, c2);
        assert_equal(s1, s1);
        assert_equal(s2, s2);
        assert_equal(sh1, sh1);
        assert_equal(sh2, sh2);
        assert_equal(i1, i1);
        assert_equal(i2, i2);
        assert_equal(st1, st1);
        assert_equal(st2, st2);
        assert_equal(d1, d1);
        assert_equal(d2, d2);
        assert_equal(b1, b1);
        assert_equal(b2, b2);
        assert_equal(ida1, ida1);

        utils_log("----- assert_equal:failed -----");
        assert_equal(ca1, ca1);
        assert_equal(ca2, ca2);
        assert_equal(sa1, sa1);
        assert_equal(sa2, sa2);
        assert_equal(sha1, sha1);
        assert_equal(sha2, sha2);
        assert_equal(ia1, ia1);
        assert_equal(ia2, ia2);
        assert_equal(sta1, sta1);
        assert_equal(sta2, sta2);
        assert_equal(da1, da1);
        assert_equal(da2, da2);
        assert_equal(ba1, ba1);
        assert_equal(ba2, ba2);

        assert_equal(c1, c2);
        assert_equal(s1, s2);
        assert_equal(sh1, sh2);
        assert_equal(i1, i2);
        assert_equal(st1, st2);
        assert_equal(d1, d2);
        assert_equal(b1, b2);

        assert_equal(ca1, ca2);
        assert_equal(sa1, sa2);
        assert_equal(sha1, sha2);
        assert_equal(ia1, ia2);
        assert_equal(sta1, sta2);
        assert_equal(da1, da2);
        assert_equal(ba1, ba2);

        assert_equal(ida1, ida2);

        utils_log("----- assert_in:passed -----");
        assert_in(i3, ia3);
        assert_in(ia6, actnr1);
        assert_in(ida6, dactnr1);

        utils_log("----- assert_in:failed -----");
        assert_in(i3, ia6);
        assert_in(ia6, actnr2);
        assert_in(ida6, dactnr2);
}
