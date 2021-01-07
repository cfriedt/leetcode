/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "unique-paths.cpp"

TEST( UniquePaths, Test_3_2 ) {
	int m( 3 );
	int n( 2 );

	int expected_int = 3;
	int actual_int = Solution().uniquePaths(m, n);

	EXPECT_EQ(actual_int, expected_int);
}

TEST( UniquePaths, Test_7_3 ) {
	int m( 7 );
	int n( 3 );

	int expected_int = 28;
	int actual_int = Solution().uniquePaths(m, n);

	EXPECT_EQ(actual_int, expected_int);
}
