/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

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
