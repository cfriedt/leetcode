/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "reverse-integer.cpp"

TEST( ReverseInteger, Test_123 ) {
	int x = 123;
	int expected_int = 321;
	int actual_int = Solution().reverse(x);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( ReverseInteger, Test_n123 ) {
	int x = -123;
	int expected_int = -321;
	int actual_int = Solution().reverse(x);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( ReverseInteger, Test_120 ) {
	int x = 120;
	int expected_int = 21;
	int actual_int = Solution().reverse(x);
	EXPECT_EQ(actual_int, expected_int);
}
