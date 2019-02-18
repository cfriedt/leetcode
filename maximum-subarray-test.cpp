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

#include "maximum-subarray.cpp"

TEST( MaximumSubarray, Test_n2_1_n3_4_n1_2_1_n5_4 ) {
	vector<int> nums({-2,1,-3,4,-1,2,1,-5,4});
	int expected_int = 6;
	int actual_int = Solution().maxSubArray(nums);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximumSubarray, Test_n1_0_n2 ) {
	vector<int> nums({-1,0,-2});
	int expected_int = 0;
	int actual_int = Solution().maxSubArray(nums);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximumSubarray, Test_2_0_3_n2 ) {
	vector<int> nums({2,0,3,-2});
	int expected_int = 5;
	int actual_int = Solution().maxSubArray(nums);
	EXPECT_EQ( actual_int, expected_int );
}

TEST( MaximumSubarray, Test_nil ) {
	vector<int> nums;
	int expected_int = 0;
	int actual_int = Solution().maxSubArray(nums);
	EXPECT_EQ( actual_int, expected_int );
}
