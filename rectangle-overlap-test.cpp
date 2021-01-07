/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "rectangle-overlap.cpp"

TEST( RectangleOverlap, Test_0_0_2_2__1_1_3_3 ) {
	vector<int> rec1({0,0,2,2});
	vector<int> rec2({1,1,3,3});
	bool expected_bool = true;
	bool actual_bool = Solution().isRectangleOverlap(rec1, rec2);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( RectangleOverlap, Test_0_0_1_1__1_0_2_1 ) {
	vector<int> rec1({0,0,1,1});
	vector<int> rec2({1,0,2,1});
	bool expected_bool = false;
	bool actual_bool = Solution().isRectangleOverlap(rec1, rec2);
	EXPECT_EQ(actual_bool, expected_bool);
}

// zero area
TEST( RectangleOverlap, Test_0_0_3_3__1_1_1_1 ) {
	vector<int> rec1({0,0,3,3});
	vector<int> rec2({1,1,1,1});
	bool expected_bool = false;
	bool actual_bool = Solution().isRectangleOverlap(rec1, rec2);
	EXPECT_EQ(actual_bool, expected_bool);
}
