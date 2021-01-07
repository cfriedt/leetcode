/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
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
