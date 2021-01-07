/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "spiral-matrix-ii.cpp"

TEST( SpiralMatrixIi, Test_1 ) {
	int n = 1;
	vector<vector<int>> expected_vvi({{1}});
	vector<vector<int>> actual_vvi = Solution().generateMatrix(n);
	EXPECT_EQ(actual_vvi, expected_vvi);
}

TEST( SpiralMatrixIi, Test_2 ) {
	int n = 2;
	vector<vector<int>> expected_vvi({{1,2},{4,3}});
	vector<vector<int>> actual_vvi = Solution().generateMatrix(n);
	EXPECT_EQ(actual_vvi, expected_vvi);
}

TEST( SpiralMatrixIi, Test_3 ) {
	int n = 3;
	vector<vector<int>> expected_vvi({{1,2,3},{8,9,4},{7,6,5}});
	vector<vector<int>> actual_vvi = Solution().generateMatrix(n);
	EXPECT_EQ(actual_vvi, expected_vvi);
}

TEST( SpiralMatrixIi, Test_4 ) {
	int n = 4;
	vector<vector<int>> expected_vvi({{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}});
	vector<vector<int>> actual_vvi = Solution().generateMatrix(n);
	EXPECT_EQ(actual_vvi, expected_vvi);
}
