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
