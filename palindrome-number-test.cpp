/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

using namespace std;

#include "palindrome-number.cpp"

TEST( PalindromeNumber, Test_121 ) {
	int x = 121;
	bool expected_bool = true;
	bool actual_bool = Solution().isPalindrome(x);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( PalindromeNumber, Test_n121 ) {
	int x = -121;
	bool expected_bool = false;
	bool actual_bool = Solution().isPalindrome(x);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( PalindromeNumber, Test_10 ) {
	int x = 10;
	bool expected_bool = false;
	bool actual_bool = Solution().isPalindrome(x);
	EXPECT_EQ(actual_bool, expected_bool);
}
