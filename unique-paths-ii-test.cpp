/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "unique-paths-ii.cpp"

TEST( UniquePathsII, Test_nil ) {
	vector<vector<int>> obstacleGrid;
	int expected_int = 1;
	int actual_int = Solution().uniquePathsWithObstacles( obstacleGrid );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( UniquePathsII, Test_0 ) {
	vector<vector<int>> obstacleGrid({
		{0},
	});
	int expected_int = 1; // 0!/(1!0!)
	int actual_int = Solution().uniquePathsWithObstacles( obstacleGrid );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( UniquePathsII, Test_1 ) {
	vector<vector<int>> obstacleGrid({
		{1},
	});
	int expected_int = 0;
	int actual_int = Solution().uniquePathsWithObstacles( obstacleGrid );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( UniquePathsII, Test_1_0__0_0 ) {
	vector<vector<int>> obstacleGrid({
		{1,0},
		{0,0},
	});
	int expected_int = 0;
	int actual_int = Solution().uniquePathsWithObstacles( obstacleGrid );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( UniquePathsII, Test_0_0__0_1 ) {
	vector<vector<int>> obstacleGrid({
		{0,0},
		{0,1},
	});
	int expected_int = 0;
	int actual_int = Solution().uniquePathsWithObstacles( obstacleGrid );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( UniquePathsII, Test_0_0_0__0_0_0__0_0_0 ) {
	vector<vector<int>> obstacleGrid({
		{0,0,0},
		{0,0,0},
		{0,0,0},
	});
	int expected_int = 6; // 4C2
	int actual_int = Solution().uniquePathsWithObstacles( obstacleGrid );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( UniquePathsII, Test_0_0_0__0_1_0__0_0_0 ) {
	vector<vector<int>> obstacleGrid({
		{0,0,0},
		{0,1,0},
		{0,0,0},
	});
	int expected_int = 2;
	int actual_int = Solution().uniquePathsWithObstacles( obstacleGrid );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( UniquePathsII, Test_0_0_0_0__0_0_1_0__0_1_1_0__0_0_0_0 ) {
	vector<vector<int>> obstacleGrid({
		{0,0,0,0},
		{0,0,1,0},
		{0,1,1,0},
		{0,0,0,0},
	});
	int expected_int = 2; // 4 when UP and LEFT are allowed
	int actual_int = Solution().uniquePathsWithObstacles( obstacleGrid );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( UniquePathsII, Test_0_0_0_0__0_1_0_0__0_0_0_0__0_0_1_0__0_0_0_0) {
	vector<vector<int>> obstacleGrid({{0,0,0,0},{0,1,0,0},{0,0,0,0},{0,0,1,0},{0,0,0,0}});
	int expected_int = 7; // 17 when UP and LEFT are allowed
	int actual_int = Solution().uniquePathsWithObstacles( obstacleGrid );
	EXPECT_EQ(actual_int, expected_int);
}

TEST( UniquePathsII, Test_0_0_0_0_0_0_0_0_1_0_1_0_0_0_0_0_0_0_0_1_0_0_0_0_0_1_0_0_0_0_0_0_0__0_0_0_0_0_0_0_0_0_0_0_0_1_0_0_0_0_1_0_0_0_0_0_0_0_0_0_0_0_0_0_0_1__0_0_0_0_0_1_0_1_0_0_0_0_0_0_0_0_0_0_0_0_0_1_0_0_0_0_1_0_0_0_0_0_0__1_1_1_0_0_0_0_1_0_0_0_0_0_0_0_0_1_0_0_1_1_0_0_0_0_0_0_0_0_1_0_0_1__0_0_1_0_0_1_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_1_0_0_0_1_0_0_0_0_0__0_0_0_1_0_1_0_0_0_0_1_1_0_0_0_0_0_0_0_0_1_0_0_0_0_0_0_0_0_0_1_1_0__1_0_1_1_1_0_0_0_0_1_0_0_0_0_0_0_0_0_1_0_0_0_0_0_1_0_0_0_0_0_0_0_0__0_0_1_0_0_0_0_0_0_0_0_0_0_0_0_1_0_0_1_0_1_0_0_0_1_0_1_0_0_0_0_0_0__0_0_0_0_0_0_0_0_0_0_1_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_1_1_0_0_1_0__0_0_0_0_0_0_0_0_0_1_1_0_0_0_0_0_0_0_0_0_0_0_1_1_0_0_0_1_0_0_0_0_0__0_1_1_0_0_0_0_0_0_0_0_0_0_0_0_0_1_0_0_0_1_0_0_0_0_0_0_0_0_0_0_0_0__1_0_1_0_0_0_0_0_0_0_0_1_0_0_1_0_0_0_0_1_0_1_0_0_0_1_0_1_0_0_0_0_1__0_0_0_0_0_0_0_0_0_0_0_1_0_0_0_0_0_1_0_1_0_0_0_0_0_0_1_1_0_0_0_0_0__0_1_0_1_0_0_0_0_1_0_0_1_0_0_0_0_0_0_0_1_1_0_0_0_0_0_0_1_0_0_0_0_0__0_1_0_0_0_0_0_0_1_0_0_1_1_0_0_0_0_0_0_0_0_0_0_0_0_0_1_0_0_1_1_0_1__1_0_0_0_0_1_0_0_1_0_0_0_0_0_0_0_1_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0_0__0_0_0_0_0_0_0_0_0_0_0_0_0_0_1_0_0_1_0_0_0_0_1_1_0_0_1_0_0_0_0_0_0__0_0_1_0_0_0_0_0_0_0_1_0_0_1_0_0_1_0_0_0_0_0_0_1_1_0_1_0_0_0_0_1_1__0_1_0_0_1_0_0_0_0_0_0_0_0_1_0_0_0_0_0_0_0_0_0_0_0_1_0_1_1_0_1_0_1__1_1_1_0_1_0_0_0_0_1_0_0_0_0_0_0_1_0_1_0_1_1_0_0_0_0_0_0_0_0_0_0_0__0_0_0_0_1_1_0_0_0_0_0_0_0_0_0_0_0_1_0_0_0_1_0_0_0_0_0_0_0_0_0_1_1__0_0_0_1_0_0_0_0_0_0_0_0_0_0_0_0_0_1_0_0_0_0_0_1_0_1_0_0_0_1_0_0_0) {
	vector<vector<int>> obstacleGrid(
		{{0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},{0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0},{1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,1},{0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0},{0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0},{1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,0},{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0},{0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1},{0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,0},{0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0},{0,1,0,0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1},{1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,1,1},{0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1},{1,1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1},{0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0}}
	);
	int expected_int = 1637984640;
	int actual_int = Solution().uniquePathsWithObstacles( obstacleGrid );
	EXPECT_EQ(actual_int, expected_int);
}
