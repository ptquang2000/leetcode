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

        char_array ca1 = {(char[]){
                                  '4',
                                  'f',
                                  'Q',
                                  'p',
                                  'K',
                                  'y',
                                  'p',
                                  '7',
                                  '4',
                                  '6',
                          },
                          10};
        char_array ca2 = {(char[]){
                                  'q',
                                  'b',
                                  '0',
                                  'n',
                                  'P',
                                  'C',
                                  'G',
                                  'd',
                                  'j',
                                  'B',
                          },
                          10};
        string_array sa1 = {(string[]){
                                    "4fQpKyp746",
                                    "qb0nPCGdjB",
                                    "sITQPD8iV4",
                                    "xKkKnhpa7O",
                                    "jvV7jhOprG",
                                    "GaOS6ubEqK",
                                    "icCg9UY9yM",
                                    "yg83QEM0uo",
                                    "kM1FF1dSOi",
                                    "keYRvfUhRN",
                            },
                            10};
        string_array sa2 = {(string[]){
                                    "VgUmJaI82d",
                                    "ln4M8KVoxn",
                                    "BuoNifpXd7",
                                    "qEGa2vlWIU",
                                    "SY1PJhpcJJ",
                                    "RjJCkfjMLX",
                                    "Eq4UGJHPRp",
                                    "WzctiOUvmM",
                                    "cdv2lSmsiu",
                                    "belwvdiz4L",
                            },
                            10};
        short_array sha1 = {(short[]){
                                    31,
                                    82,
                                    32,
                                    55,
                                    02,
                                    12,
                                    92,
                                    47,
                                    70,
                                    39,
                            },
                            10};
        short_array sha2 = {(short[]){
                                    42,
                                    51,
                                    75,
                                    31,
                                    53,
                                    33,
                                    83,
                                    33,
                                    69,
                                    78,
                            },
                            10};
        int_array ia1 = {(int[]){
                                 326239,
                                 559855,
                                 445399,
                                 828639,
                                 190305,
                                 036316,
                                 601773,
                                 932819,
                                 165302,
                                 103586,
                         },
                         10};
        int_array ia2 = {(int[]){
                                 390227,
                                 556859,
                                 992170,
                                 397070,
                                 254049,
                                 164126,
                                 737516,
                                 194706,
                                 326994,
                                 866113,
                         },
                         10};
        size_t_array sta1 = {(size_t[]){
                                     9957835168,
                                     1633598403,
                                     1951010168,
                                     6105680956,
                                     8459731783,
                                     5939598083,
                                     8420687833,
                                     6742268768,
                                     1952606315,
                                     5025918970,
                             },
                             10};
        size_t_array sta2 = {(size_t[]){
                                     2925128758,
                                     9788141779,
                                     5363541390,
                                     1169019322,
                                     1843586698,
                                     4334811848,
                                     2766719329,
                                     4118601554,
                                     7667159191,
                                     7101044942,
                             },
                             10};
        double_array da1 = {(double[]){
                                    61.45505,
                                    87.13806,
                                    63.85903,
                                    06.66105,
                                    81.98509,
                                    74.22406,
                                    54.75735,
                                    98.56143,
                                    94.26562,
                                    67.37559,
                            },
                            10};
        double_array da2 = {(double[]){
                                    70.27696,
                                    10.38040,
                                    80.59800,
                                    85.91704,
                                    96.60537,
                                    97.62957,
                                    08.60370,
                                    79.16730,
                                    61.05988,
                                    44.17787,
                            },
                            10};
        bool_array ba1 = {(bool[]){
                                  true,
                                  false,
                                  true,
                                  true,
                                  true,
                                  true,
                                  true,
                                  true,
                                  true,
                                  false,
                          },
                          10};
        bool_array ba2 = {(bool[]){
                                  false,
                                  false,
                                  true,
                                  false,
                                  false,
                                  false,
                                  false,
                                  true,
                                  false,
                                  false,
                          },
                          10};

        int_darray ida1 = {
                (int *[]){
                        (int[]){475393, 988570, 87500, 237323, 124432, 178064},
                        (int[]){857455, 310353, 539865, 047706},
                        (int[]){53230},
                        (int[]){522622, 578448, 630848, 250187},
                        (int[]){618149, 815384, 358064, 658980, 56808, 676723, 661455, 235858},
                        (int[]){12689, 932409, 966095, 133571, 610084},
                        (int[]){132628, 2517, 465359, 638961, 595024, 134992, 851962, 829427, 609012},
                        (int[]){959958, 177944, 809177, 255324, 528052, 267128, 124711, 512513, 242088},
                        (int[]){751827, 122692, 850258, 182295, 380328, 206178},
                        (int[]){281338, 442121, 712663, 622850, 341023, 679321, 728249, 593052, 846654},
                },
                (int[]){6, 4, 1, 4, 8, 5, 9, 9, 6, 9},
                10,
        };

        utils_log("c1={}, s1={}, sh1={}, i1={}, st1={}, d1={}, b1={}\n", c1, s1, sh1, i1, st1, d1, b1);
        utils_log("c2={}, s2={}, sh2={}, i2={}, st2={}, d2={}, b2={}\n", c2, s2, sh2, i2, st2, d2, b2);
        utils_log("ca1={}, ca2={}", ca1, ca2);
        utils_log("sa1={}, sa2={}", sa1, sa2);
        utils_log("sha1={}, sha2={}", sha1, sha2);
        utils_log("ia1={}, ia2={}", ia1, ia2);
        utils_log("sta1={}, sta2={}", sta1, sta2);
        utils_log("da1={}, da2={}", da1, da2);
        utils_log("ba1={}, ba2={}", ba1, ba2);

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
}
