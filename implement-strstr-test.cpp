/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "implement-strstr.cpp"

TEST( ImplementStrStr, Test_empty_empty ) {
	string haystack = "";
	string needle = "";
	int expected_int = 0;
	int actual_int = Solution().strStr(haystack, needle);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( ImplementStrStr, Test_empty_tiny__yuuuuuge ) {
	// needle too big
	string haystack = "tiny";
	string needle = "yuuuuuge";
	int expected_int = -1;
	int actual_int = Solution().strStr(haystack, needle);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( ImplementStrStr, Test_hello_ll ) {
	string haystack = "hello";
	string needle = "ll";
	int expected_int = 2;
	int actual_int = Solution().strStr(haystack, needle);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( ImplementStrStr, Test_aaaaa_bba ) {
	string haystack = "aaaaa";
	string needle = "ba";
	int expected_int = -1;
	int actual_int = Solution().strStr(haystack, needle);
	EXPECT_EQ(actual_int, expected_int);
}
