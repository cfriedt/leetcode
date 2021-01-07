/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

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
