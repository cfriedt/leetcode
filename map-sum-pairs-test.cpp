/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "map-sum-pairs.cpp"

TEST( MapSumPairs, Test_Example1 ) {
	int expected_int;
	int actual_int;
	MapSum ms;

	ms.insert("apple", 3);
	expected_int = 3;
	actual_int = ms.sum("ap");
	EXPECT_EQ( actual_int, expected_int );

	ms.insert("app", 2);
	expected_int = 5;
	actual_int = ms.sum("ap");
	EXPECT_EQ( actual_int, expected_int );
}
