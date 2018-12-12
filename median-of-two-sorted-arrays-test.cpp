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

#include "median-of-two-sorted-arrays.cpp"

TEST( MedianOfTwoSortedArrays, Test_1_3__2 ) {
	vector<int> nums1({1,3});
	vector<int> nums2({2});
	double expected_double = 2.0;
	double actual_double = Solution().findMedianSortedArrays(nums1, nums2);
	EXPECT_EQ( actual_double, expected_double );
}

TEST( MedianOfTwoSortedArrays, Test_1_2_3__1_2_3 ) {
	vector<int> nums1({1,2,3});
	vector<int> nums2({1,2,3});
	double expected_double = 2.0;
	double actual_double = Solution().findMedianSortedArrays(nums1, nums2);
	EXPECT_EQ( actual_double, expected_double );
}

TEST( MedianOfTwoSortedArrays, Test_1_2__3_4 ) {
	vector<int> nums1({1,2});
	vector<int> nums2({3,4});
	double expected_double = 2.5;
	double actual_double = Solution().findMedianSortedArrays(nums1, nums2);
	EXPECT_EQ( actual_double, expected_double );
}
