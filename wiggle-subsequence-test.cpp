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

#include "wiggle-subsequence.cpp"

// this tests out the entire sequence being a wiggle
TEST( WiggleSubsequence, Test_1_7_4_9_2_5 ) {
	vector<int> nums({1,7,4,9,2,5});
	int expected_int = 6;
	int actual_int = Solution().wiggleMaxLength(nums);
	EXPECT_EQ(actual_int, expected_int);
}

// this tests out an even sequence being the longest
TEST( WiggleSubsequence, Test_1_17_5_10_13_15_10_5_16_8 ) {
	vector<int> nums({1,17,5,10,13,15,10,5,16,8});
	int expected_int = 7;
	int actual_int = Solution().wiggleMaxLength(nums);
	EXPECT_EQ(actual_int, expected_int);
}

// this tests out 0 wiggles
TEST( WiggleSubsequence, Test_nil ) {
	vector<int> nums;
	int expected_int = 0;
	int actual_int = Solution().wiggleMaxLength(nums);
	EXPECT_EQ(actual_int, expected_int);
}

// this tests out length 1 vectors wiggles
TEST( WiggleSubsequence, Test_1 ) {
	vector<int> nums({1});
	int expected_int = 1;
	int actual_int = Solution().wiggleMaxLength(nums);
	EXPECT_EQ(actual_int, expected_int);
}

// this tests out 0 wiggles, technically. For some reason, they count this as
// wiggle subsequence length == 1
TEST( WiggleSubsequence, Test_0_0 ) {
	vector<int> nums({0,0});
	int expected_int = 1;
	int actual_int = Solution().wiggleMaxLength(nums);
	EXPECT_EQ(actual_int, expected_int);
}

// this tests out the case where only 1 wiggle is seen but no more after that
TEST( WiggleSubsequence, Test_0_1_1 ) {
	vector<int> nums({0,1,1});
	int expected_int = 2;
	int actual_int = Solution().wiggleMaxLength(nums);
	EXPECT_EQ(actual_int, expected_int);
}

// this tests out an odd sequence being the longest
TEST( WiggleSubsequence, Test_1_0_1_0_1_0 ) {
	// nums 1,0,1,0,1,0
	// d     -,+,-,+,-
	// even 1,1,2,3,4,5
	// odd  1,2,3,4,5,6
	vector<int> nums({1,0,1,0,1,0});
	int expected_int = 6;
	int actual_int = Solution().wiggleMaxLength(nums);
	EXPECT_EQ(actual_int, expected_int);
}

// this tests out not setting the initial sign_last properly
TEST( WiggleSubsequence, Test_3_3_3_2_5 ) {
	vector<int> nums({3,3,3,2,5});
	int expected_int = 3;
	int actual_int = Solution().wiggleMaxLength(nums);
	EXPECT_EQ(actual_int, expected_int);
}
