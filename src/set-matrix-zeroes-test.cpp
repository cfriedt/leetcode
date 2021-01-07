/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "set-matrix-zeroes.cpp"

TEST( SetMatrixZeroes, Test_1_1_1__1_0_1__1_1_1 ) {
	vector<vector<int>> matrix({
		{1,1,1},
		{1,0,1},
		{1,1,1},
	});

	vector<vector<int>> expected_vvi({
		{1,0,1},
		{0,0,0},
		{1,0,1},
	});
	Solution().setZeroes( matrix );
	vector<vector<int>> actual_vvi = matrix;

	EXPECT_EQ(actual_vvi, expected_vvi);
}

TEST( SetMatrixZeroes, Test_0_1_2_0__3_4_5_2__1_3_1_5 ) {
	vector<vector<int>> matrix({
		{0,1,2,0},
		{3,4,5,2},
		{1,3,1,5},
	});

	vector<vector<int>> expected_vvi({
		{0,0,0,0},
		{0,4,5,0},
		{0,3,1,0},
	});
	Solution().setZeroes( matrix );
	vector<vector<int>> actual_vvi = matrix;

	EXPECT_EQ(actual_vvi, expected_vvi);
}
