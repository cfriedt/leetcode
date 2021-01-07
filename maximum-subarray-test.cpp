/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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
