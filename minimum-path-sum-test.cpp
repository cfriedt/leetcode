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

#include "minimum-path-sum.cpp"

TEST( MinimumPathSum, Test_1_3_1__1_5_1__4_2_1 ) {
	vector<vector<int>> grid({{1,3,1},{1,5,1},{4,2,1}});
	int expected_int = 7;
	int actual_int = Solution().minPathSum(grid);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( MinimumPathSum, Test_big_one ) {
	vector<vector<int>> grid({{0,2,2,6,4,1,6,2,9,9,5,8,4,4},{0,3,6,4,5,5,9,7,8,3,9,9,5,4},{6,9,0,7,2,2,5,6,3,1,0,4,2,5},{3,8,2,3,2,8,8,7,5,9,6,3,4,5},{4,0,1,3,9,2,0,1,6,7,9,2,8,9},{6,2,7,9,0,9,5,2,7,5,1,4,4,7},{9,8,3,3,0,6,8,0,8,8,3,5,7,3},{7,7,4,5,9,1,5,0,2,2,2,1,7,4},{5,1,3,4,1,6,0,4,3,8,4,3,9,9},{0,6,4,9,4,1,5,5,4,2,5,7,4,0},{0,1,6,6,4,9,2,7,8,2,1,3,3,7},{8,4,9,9,2,3,8,6,6,5,4,1,7,9}});
	int expected_int = 63;
	int actual_int = Solution().minPathSum(grid);
	EXPECT_EQ(actual_int, expected_int);
}
