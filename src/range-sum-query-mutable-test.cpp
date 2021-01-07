/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "range-sum-query-mutable.cpp"

TEST( RangeSumQueryMutable, Test_1_3_5 ) {
	int expected_int;
	int actual_int;

	vector<int> nums({1,3,5});
	NumArray na( nums );

	expected_int = 9;
	actual_int = na.sumRange(0, 2);

	EXPECT_EQ(actual_int, expected_int);

	na.update(1, 2);

	expected_int = 8;
	actual_int = na.sumRange(0, 2);

	EXPECT_EQ(actual_int, expected_int);
}
