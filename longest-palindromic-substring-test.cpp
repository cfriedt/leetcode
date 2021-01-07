/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "longest-palindromic-substring.cpp"

TEST( LongestPalindromicSubstring, Test_babad ) {
	string s("babad");
	string expected_string("bab");
	string actual_string = Solution().longestPalindrome(s);
	EXPECT_EQ(actual_string, expected_string);
}
