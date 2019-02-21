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

#include "longest-palindromic-subsequence.cpp"

TEST( LongestPalindromicSubsequence, Test_nil ) {
	string s = "";
	int expected_int = 0;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( LongestPalindromicSubsequence, Test_x ) {
	string s = "x";
	int expected_int = 1;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( LongestPalindromicSubsequence, Test_xxx ) {
	string s = "xxx";
	int expected_int = 3;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( LongestPalindromicSubsequence, Test_aaaa) {
	string s = "aaaa";
	int expected_int = 4;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestPalindromicSubsequence, Test_bbbab ) {
	string s = "bbbab";
	int expected_int = 4;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( LongestPalindromicSubsequence, Test_cbbd ) {
	string s = "cbbd";
	int expected_int = 2;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( LongestPalindromicSubsequence, Test_abcdeb) {
	string s = "abcdeb";
	int expected_int = 3;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestPalindromicSubsequence, Test_abcceb) {
	string s = "abcceb";
	int expected_int = 4;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestPalindromicSubsequence, Test_hijzabcdefgzklm) {
	string s = "hijzabcdefgzklm";
	int expected_int = 3;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestPalindromicSubsequence, Test_hijazbcdefgzklm) {
	string s = "hijazbcdefgzklm";
	int expected_int = 3;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestPalindromicSubsequence, Test_abcdef) {
	string s = "abcdef";
	int expected_int = 1;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestPalindromicSubsequence, Test_abab) {
	string s = "abab";
	int expected_int = 3;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestPalindromicSubsequence, Test_abcabcabcabc) {
	string s = "abcabcabcabc";
	int expected_int = 7;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestPalindromicSubsequence, Test_aabaaba) {
	string s = "aabaaba";
	int expected_int = 6;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestPalindromicSubsequence, Test_babbbbaabbababbaaaaababbaaabbbbaaabbbababbbbabaabababaabaaabbbabababbbabababaababaaaaabbabaaaabaaaab) {
	string s = "babbbbaabbababbaaaaababbaaabbbbaaabbbababbbbabaabababaabaaabbbabababbbabababaababaaaaabbabaaaabaaaab";
	int expected_int = 81;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestPalindromicSubsequence, Test_abaababaab) {
	string s = "abaababaab";
	int expected_int = 9;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( LongestPalindromicSubsequence, Test_abcdabcdabcdabcd) {
	string s = "abcdabcdabcdabcd";
	int expected_int = 7;
	int actual_int = Solution().longestPalindromeSubseq(s);
	EXPECT_EQ( actual_int, expected_int );
}
