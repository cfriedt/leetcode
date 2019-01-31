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

#include "top-k-frequent-elements.cpp"

TEST( TopKFrequentElements, Test_1_1_1_2_2_3__2 ) {
	vector<int> nums({1,1,1,2,2,3});
	int k = 2;
	vector<int> expected_vi({1,2});
	vector<int> actual_vi = Solution().topKFrequent(nums, k);
	EXPECT_EQ(actual_vi, expected_vi);
}

TEST( TopKFrequentElements, Test_1__1 ) {
	vector<int> nums({1});
	int k = 1;
	vector<int> expected_vi({1});
	vector<int> actual_vi = Solution().topKFrequent(nums, k);
	EXPECT_EQ(actual_vi, expected_vi);
}
