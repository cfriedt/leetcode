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

#include "rectangle-overlap.cpp"

TEST( RectangleOverlap, Test_0_0_2_2__1_1_3_3 ) {
	vector<int> rec1({0,0,2,2});
	vector<int> rec2({1,1,3,3});
	bool expected_bool = true;
	bool actual_bool = Solution().isRectangleOverlap(rec1, rec2);
	EXPECT_EQ(actual_bool, expected_bool);
}

TEST( RectangleOverlap, Test_0_0_1_1__1_0_2_1 ) {
	vector<int> rec1({0,0,1,1});
	vector<int> rec2({1,0,2,1});
	bool expected_bool = false;
	bool actual_bool = Solution().isRectangleOverlap(rec1, rec2);
	EXPECT_EQ(actual_bool, expected_bool);
}

// zero area
TEST( RectangleOverlap, Test_0_0_3_3__1_1_1_1 ) {
	vector<int> rec1({0,0,3,3});
	vector<int> rec2({1,1,1,1});
	bool expected_bool = false;
	bool actual_bool = Solution().isRectangleOverlap(rec1, rec2);
	EXPECT_EQ(actual_bool, expected_bool);
}
