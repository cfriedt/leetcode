/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "paint-house.cpp"

TEST( PaintHouse, Test_17_2_17__16_16_5__14_3_19 ) {
	vector<vector<int>> costs({{17,2,17},{16,16,5},{14,3,19}});
	int expected_int = 10;
	int actual_int = Solution().minCost(costs);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( PaintHouse, Test_nil ) {
	vector<vector<int>> costs;
	int expected_int = 0;
	int actual_int = Solution().minCost(costs);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( PaintHouse, Test_5_8_6__19_14_13__7_5_12__14_15_17__3_20_10 ) {
	vector<vector<int>> costs({{5,8,6},{19,14,13},{7,5,12},{14,15,17},{3,20,10}});
	int expected_int = 43;
	int actual_int = Solution().minCost(costs);
	EXPECT_EQ(actual_int, expected_int);
}
