/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "spiral-matrix.cpp"

TEST( SpiralMatrix, Test_1_2_3__4_5_6__7_8_9 ) {
	vector<vector<int>> matrix({
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	});
	vector<int> expected_vi = vector<int>({1,2,3,6,9,8,7,4,5});
	vector<int> actual_vi = Solution().spiralOrder(matrix);
	EXPECT_EQ(actual_vi, expected_vi);
}
