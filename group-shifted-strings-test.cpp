/*
 * MIT License
 *
 * Copyright (c) 2018 Christopher Friedt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <gtest/gtest.h>

#include "group-shifted-strings.cpp"

TEST( GroupShiftedStrings, Test_abc_bcd_acef_xyz_az_ba_a_z ) {

	vector<string> strings{ "abc", "bcd", "acef", "xyz", "az", "ba", "a", "z" };
	vector<vector<string>> expected_vvs{{ "abc", "bcd", "xyz" }, {"az", "ba"}, { "acef" }, {"a", "z"} };

	vector<vector<string>> actual_vvs = Solution().groupStrings(strings);

	EXPECT_EQ( actual_vvs, expected_vvs );
}

TEST( GroupShiftedStrings, Test_empty ) {
	vector<string> strings;
	vector<vector<string>> expected_vvs;

	vector<vector<string>> actual_vvs = Solution().groupStrings(strings);

	EXPECT_EQ( actual_vvs, expected_vvs );
}

TEST( GroupShiftedStrings, Test_ab_ba ) {
	vector<string> strings{ "ab", "ba" };
	vector<vector<string>> expected_vvs{ { "ba" }, { "ab" } };

	vector<vector<string>> actual_vvs = Solution().groupStrings(strings);

	EXPECT_EQ( actual_vvs, expected_vvs );
}

TEST( GroupShiftedStrings, Test_fpbnsbrkbcyzdmmmoisaa_cpjtwqcdwbldwwrryuclcngw_a_fnuqwejouqzrif_js_qcpr_zghmdiaqmfelr_iedda_l_dgwlvcyubde_lpt_qzq_zkddvitlk_xbogegswmad_mkndeyrh_llofdjckor_lebzshcb_firomjjlidqpsdeqyn_dclpiqbypjpfafukqmjnjg_lbpabjpcmkyivbtgdwhzlxa_wmalmuanxvjtgmerohskwil_yxgkdlwtkekavapflheieb_oraxvssurmzybmnzhw_ohecvkfe_kknecibjnq_wuxnoibr_gkxpnpbfvjm_lwpphufxw_sbs_txb_ilbqahdzgij_i_zvuur_yfglchzpledkq_eqdf_nw_aiplrzejplumda_d_huoybvhibgqibbwwdzhqhslb_rbnzendwnoklpyyyauemm ) {
	vector<string> strings{ "fpbnsbrkbcyzdmmmoisaa","cpjtwqcdwbldwwrryuclcngw","a","fnuqwejouqzrif","js","qcpr","zghmdiaqmfelr","iedda","l","dgwlvcyubde","lpt","qzq","zkddvitlk","xbogegswmad","mkndeyrh","llofdjckor","lebzshcb","firomjjlidqpsdeqyn","dclpiqbypjpfafukqmjnjg","lbpabjpcmkyivbtgdwhzlxa","wmalmuanxvjtgmerohskwil","yxgkdlwtkekavapflheieb","oraxvssurmzybmnzhw","ohecvkfe","kknecibjnq","wuxnoibr","gkxpnpbfvjm","lwpphufxw","sbs","txb","ilbqahdzgij","i","zvuur","yfglchzpledkq","eqdf","nw","aiplrzejplumda","d","huoybvhibgqibbwwdzhqhslb","rbnzendwnoklpyyyauemm" };
	vector<vector<string>> expected_vvs{ { "dgwlvcyubde", "ilbqahdzgij" }, { "lebzshcb", "ohecvkfe" }, { "mkndeyrh", "wuxnoibr" }, { "dclpiqbypjpfafukqmjnjg", "yxgkdlwtkekavapflheieb" }, { "xbogegswmad", "gkxpnpbfvjm" }, { "lpt", "txb" }, { "zkddvitlk", "lwpphufxw" }, { "llofdjckor", "kknecibjnq" }, { "qzq", "sbs" }, { "lbpabjpcmkyivbtgdwhzlxa", "wmalmuanxvjtgmerohskwil" }, { "cpjtwqcdwbldwwrryuclcngw", "huoybvhibgqibbwwdzhqhslb" }, { "fpbnsbrkbcyzdmmmoisaa", "rbnzendwnoklpyyyauemm" }, { "firomjjlidqpsdeqyn", "oraxvssurmzybmnzhw" }, { "fnuqwejouqzrif", "aiplrzejplumda" }, { "iedda", "zvuur" }, { "qcpr", "eqdf" }, { "js", "nw" }, { "zghmdiaqmfelr", "yfglchzpledkq" }, { "a", "l", "i", "d" } };

	vector<vector<string>> actual_vvs = Solution().groupStrings(strings);

	EXPECT_EQ( actual_vvs, expected_vvs );
}
