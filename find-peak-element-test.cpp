/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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
