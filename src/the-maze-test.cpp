/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "the-maze.cpp"

TEST( TheMaze, Test_Example1 ) {
	vector<vector<int>> maze({
		{0,0,1,0,0},
		{0,0,0,0,0},
		{0,0,0,1,0},
		{1,1,0,1,1},
		{0,0,0,0,0},
	});
	vector<int> start({0,4});
	vector<int> destination({4,4});
	bool expected_bool = true;
	bool actual_bool = Solution().hasPath(maze, start, destination);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( TheMaze, Test_Example2 ) {
	vector<vector<int>> maze({
		{0,0,1,0,0},
		{0,0,0,0,0},
		{0,0,0,1,0},
		{1,1,0,1,1},
		{0,0,0,0,0},
	});
	vector<int> start({0,4});
	vector<int> destination({3,2});
	bool expected_bool = false;
	bool actual_bool = Solution().hasPath(maze, start, destination);
	EXPECT_EQ(actual_bool, expected_bool);
}
