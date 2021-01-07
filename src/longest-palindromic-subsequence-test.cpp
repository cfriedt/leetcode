/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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
