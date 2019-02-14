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

#include "word-break.cpp"

TEST( WordBreak, Test_leetcode__leet_code ) {
	string s = "leetcode";
	vector<string> wordDict({
		"leet",
		"code",
	});
	bool expected_bool = true;
	bool actual_bool = Solution().wordBreak(s, wordDict);

	EXPECT_EQ( actual_bool, expected_bool );
}

TEST( WordBreak, Test_applepenapple__apple_pen ) {
	string s = "applepenapple";
	vector<string> wordDict({
		"apple",
		"pen",
	});
	bool expected_bool = true;
	bool actual_bool = Solution().wordBreak(s, wordDict);

	EXPECT_EQ( actual_bool, expected_bool );
}

TEST( WordBreak, Test_catsandog__cats_dog_sand_and_cat ) {
	string s = "catsandog";
	vector<string> wordDict({
		"cats",
		"dog",
		"sand",
		"and",
		"cat",
	});
	bool expected_bool = false;
	bool actual_bool = Solution().wordBreak(s, wordDict);

	EXPECT_EQ( actual_bool, expected_bool );
}


TEST( WordBreak, Test_a__a ) {
	string s = "a";
	vector<string> wordDict({
		"a",
	});
	bool expected_bool = true;
	bool actual_bool = Solution().wordBreak(s, wordDict);

	EXPECT_EQ( actual_bool, expected_bool );
}

TEST( WordBreak, Test_aaaaaaaa__aaaa__aa ) {
	string s = "aaaaaaa";
	vector<string> wordDict({
		"aaaa",
		"aa",
	});
	bool expected_bool = false;
	bool actual_bool = Solution().wordBreak(s, wordDict);

	EXPECT_EQ( actual_bool, expected_bool );
}

TEST( WordBreak, Test_aaaaaaaa__aaaa__aaa ) {
	string s = "aaaaaaa";
	vector<string> wordDict({
		"aaaa",
		"aaa",
	});
	bool expected_bool = true;
	bool actual_bool = Solution().wordBreak(s, wordDict);

	EXPECT_EQ( actual_bool, expected_bool );
}


TEST( WordBreak, Test_aaab__a_aa ) {
	 string s = "aaab";
	 vector<string> wordDict({
		 "a","aa",
	 });
	bool expected_bool = false;
	bool actual_bool = Solution().wordBreak(s, wordDict);

	EXPECT_EQ( actual_bool, expected_bool );
}

TEST( WordBreak, Test_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab__a_aa_aaa_aaaa_aaaaa_aaaaaa_aaaaaaa_aaaaaaaa_aaaaaaaaa_aaaaaaaaaa ) {
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	vector<string> wordDict({
		"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa",
	});
	bool expected_bool = false;
	bool actual_bool = Solution().wordBreak(s, wordDict);

	EXPECT_EQ( actual_bool, expected_bool );
}

TEST( WordBreak, Test_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa__aa_aaa_aaaa_aaaaa_aaaaaa_aaaaaaa_aaaaaaaa_aaaaaaaaa_aaaaaaaaaa_ba ) {
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	vector<string> wordDict({
		"aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba",
	});
	bool expected_bool = false;
	bool actual_bool = Solution().wordBreak(s, wordDict);

	EXPECT_EQ( actual_bool, expected_bool );
}
