/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "rotated-digits.cpp"

TEST( RotatedDigits, Test_10 ) {
	int N = 10;
	int expected_int = 4;
	int actual_int = Solution().rotatedDigits( N );
	EXPECT_EQ( actual_int, expected_int );
}

TEST( RotatedDigits, Test_2 ) {
	int N = 2;
	int expected_int = 1;
	int actual_int = Solution().rotatedDigits( N );
	EXPECT_EQ( actual_int, expected_int );
}
