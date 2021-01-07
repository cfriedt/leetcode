/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "missing-number.cpp"

TEST( MissingNumber, Test_3_0_1 ) {
	vector<int> nums({3,0,1});
	int expected_int( 2 );
	int actual_int = Solution().missingNumber( nums );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( MissingNumber, Test_0 ) {
	vector<int> nums({0});
	int expected_int( 1 );
	int actual_int = Solution().missingNumber( nums );
	EXPECT_EQ(actual_int, expected_int);
}
