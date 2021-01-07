/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "reverse-words-in-a-string.cpp"

TEST( TwoSum, Test_the_sky_is_blue ) {
	string s = "the sky is blue";
	string expected_string = "blue is sky the";
	Solution().reverseWords( s );
	string actual_string = s;
	EXPECT_EQ(actual_string, expected_string);
}

TEST( TwoSum, Test_spaces ) {
	string s = "    ";
	string expected_string = "";
	Solution().reverseWords( s );
	string actual_string = s;
	EXPECT_EQ(actual_string, expected_string);
}
