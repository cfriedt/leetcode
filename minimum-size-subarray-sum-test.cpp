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

#include <gtest.h>

#include "minimum-size-subarray-sum.cpp"

TEST( MinimumSizeSubarray, Test_7__2_3_1_2_4_3 ) {
	int s = 7;
	vector<int> nums({2,3,1,2,4,3});
	int expected_int = 2;
	int actual_int = Solution().minSubArrayLen(s, nums);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( MinimumSizeSubarray, Test_nil ) {
	int s = 7;
	vector<int> nums;
	int expected_int = 0;
	int actual_int = Solution().minSubArrayLen(s, nums);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( MinimumSizeSubarray, Test_7__2_3_1_2_4_3_1 ) {
	int s = 7;
	vector<int> nums({2,3,1,2,4,3,1});
	int expected_int = 2;
	int actual_int = Solution().minSubArrayLen(s, nums);
	EXPECT_EQ(actual_int, expected_int);
}

// early finish (in middle of array, length is 1)
TEST( MinimumSizeSubarray, Test_4__1_4_4 ) {
	int s = 4;
	vector<int> nums({1,4,4});
	int expected_int = 1;
	int actual_int = Solution().minSubArrayLen(s, nums);
	EXPECT_EQ(actual_int, expected_int);
}
