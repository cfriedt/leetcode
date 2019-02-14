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

#include "find-peak-element.cpp"

TEST( FindPeakElement, Test_1_2_3_1 ) {
	vector<int> nums({1,2,3,1});
	int expected_int = 2;
	int actual_int = Solution().findPeakElement(nums);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( FindPeakElement, Test_1_2_1_3_5_6_4 ) {
	vector<int> nums({1,2,1,3,5,6,4});
	EXPECT_TRUE( 1 == Solution().findPeakElement(nums) || 5 == Solution().findPeakElement(nums) );
}

TEST( FindPeakElement, Test_nil ) {
	vector<int> nums;
	int expected_int = -1;
	int actual_int = Solution().findPeakElement(nums);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( FindPeakElement, Test_0 ) {
	vector<int> nums({0});
	int expected_int = 0;
	int actual_int = Solution().findPeakElement(nums);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( FindPeakElement, Test_INT_MIN ) {
	vector<int> nums({INT_MIN});
	int expected_int = 0;
	int actual_int = Solution().findPeakElement(nums);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( FindPeakElement, Test_1_2 ) {
	vector<int> nums({1,2});
	int expected_int = 1;
	int actual_int = Solution().findPeakElement(nums);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( FindPeakElement, Test_2_1 ) {
	vector<int> nums({2,1});
	int expected_int = 0;
	int actual_int = Solution().findPeakElement(nums);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( FindPeakElement, Test_1_2_1 ) {
	vector<int> nums({1,2,1});
	int expected_int = 1;
	int actual_int = Solution().findPeakElement(nums);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( FindPeakElement, Test_INT_MIN_INT_MIN ) {
	vector<int> nums({INT_MIN,INT_MIN});
	int expected_int = -1;
	int actual_int = Solution().findPeakElement(nums);
	EXPECT_EQ(actual_int, expected_int);
}
