/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "number-of-good-pairs.cpp"

using namespace std;

TEST(NumberOfGoodPairs, 1_2_3_1_1_3) {
	vector<int> nums = {
		1,2,3,1,1,3,
	};
	EXPECT_EQ(4, Solution().numIdenticalPairs(nums));
}

TEST(NumberOfGoodPairs, 1_1_1_1) {
	vector<int> nums = {
		1,1,1,1,
	};
	EXPECT_EQ(6, Solution().numIdenticalPairs(nums));
}

TEST(NumberOfGoodPairs, 1_2_3) {
	vector<int> nums = {
		1,2,3,
	};
	EXPECT_EQ(0, Solution().numIdenticalPairs(nums));
}

TEST(NumberOfGoodPairs, 6_5_1_5_7_7_9_1_5_7_1_6_10_9_7_4_1_8_7_1_1_8_6_4_7_4_10_5_3_9_10_1_9_5_5_4_1_7_4_2_9_2_6_6_4_2_10_3_5_3_6_4_7_4_6_4_4_6_3_4_10_1_10_6_10_4_9_6_6_4_8_6_9_5_4) {
	vector<int> nums = {
6,5,1,5,7,7,9,1,5,7,1,6,10,9,7,4,1,8,7,1,1,8,6,4,7,4,10,5,3,9,10,1,9,5,5,4,1,7,4,2,9,2,6,6,4,2,10,3,5,3,6,4,7,4,6,4,4,6,3,4,10,1,10,6,10,4,9,6,6,4,8,6,9,5,4
	};
	EXPECT_EQ(303, Solution().numIdenticalPairs(nums));
}
