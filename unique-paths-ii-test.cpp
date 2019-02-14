/*
 * MIT License
 *
 * Copyright (c) 2018 Christopher Friedt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
