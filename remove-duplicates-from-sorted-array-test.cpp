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

#include "remove-duplicates-from-sorted-array.cpp"

TEST( RemoveDuplicatesFromSortedArray, Test_1_1_2 ) {
	vector<int> nums({1,1,2});
	vector<int> expected_vi({1,2});
	int expected_int = 2;
	int actual_int = Solution().removeDuplicates(nums);
	vector<int> & actual_vi = nums;
	actual_vi.resize( actual_int );
	EXPECT_EQ(actual_int, expected_int);
	EXPECT_EQ(actual_vi, expected_vi);
}

TEST( RemoveDuplicatesFromSortedArray, Test_0_0_1_1_1_2_2_3_3_4 ) {
	vector<int> nums({0,0,1,1,1,2,2,3,3,4});
	vector<int> expected_vi({0,1,2,3,4});
	int expected_int = 5;
	int actual_int = Solution().removeDuplicates(nums);
	vector<int> & actual_vi = nums;
	actual_vi.resize( actual_int );
	EXPECT_EQ(actual_int, expected_int);
	EXPECT_EQ(actual_vi, expected_vi);
}

TEST( RemoveDuplicatesFromSortedArray, Test_1_2 ) {
	vector<int> nums({1,2});
	vector<int> expected_vi({1,2});
	int expected_int = 2;
	int actual_int = Solution().removeDuplicates(nums);
	vector<int> & actual_vi = nums;
	actual_vi.resize( actual_int );
	EXPECT_EQ(actual_int, expected_int);
	EXPECT_EQ(actual_vi, expected_vi);
}
