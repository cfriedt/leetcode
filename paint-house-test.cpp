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
