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
