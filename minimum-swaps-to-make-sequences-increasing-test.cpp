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

#include "minimum-swaps-to-make-sequences-increasing.cpp"

TEST( MinimumSwapToMakeSequencesIncreasing, Test_1_3_5_4__1_2_3_7 ) {
	vector<int> A({1,3,5,4});
	vector<int> B({1,2,3,7});
	int expected_int = 1;
	int actual_int = Solution().minSwap(A, B);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( MinimumSwapToMakeSequencesIncreasing, Test_0_4_4_5_9__0_1_6_8_10 ) {
	vector<int> A({0,4,4,5,9});
	vector<int> B({0,1,6,8,10});
	int expected_int = 1;
	int actual_int = Solution().minSwap(A, B);
	EXPECT_EQ(actual_int, expected_int);
}

TEST( MinimumSwapToMakeSequencesIncreasing, Test_0_3_5_8_9__2_1_4_6_9 ) {
	vector<int> A({0,3,5,8,9});
	vector<int> B({2,1,4,6,9});
	int expected_int = 1;
	int actual_int = Solution().minSwap(A, B);
	EXPECT_EQ(actual_int, expected_int);
}
