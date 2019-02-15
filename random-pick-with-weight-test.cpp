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

#include "random-pick-with-weight.cpp"

TEST( RandomPickWithWeight, Test_2_7_11_15_9 ) {
	vector<int> nums({2,7,11,15});
	int target( 9 );
	vector<int> expected_vi({0,1});
	vector<int> actual_vi = Solution().twoSum(nums, target);
	EXPECT_EQ(actual_vi, expected_vi);
}

TEST( TwoSum, Test_3_2_4_6 ) {
	vector<int> nums({3,2,4});
	int target( 6 );
	vector<int> expected_vi({1,2});
	vector<int> actual_vi = Solution().twoSum(nums, target);
	EXPECT_EQ(actual_vi, expected_vi);
}

TEST( TwoSum, Test_3_3_6 ) {
	vector<int> nums({3,3});
	int target( 6 );
	vector<int> expected_vi({0,1});
	vector<int> actual_vi = Solution().twoSum(nums, target);
	EXPECT_EQ(actual_vi, expected_vi);
}
