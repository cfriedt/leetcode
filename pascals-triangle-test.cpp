/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "pascals-triangle.cpp"

TEST( PascalsTriangle, Test_5 ) {
	int numRows = 5;
	vector<vector<int>> expected_vvi{
		   {1},
		  {1,1},
		 {1,2,1},
		{1,3,3,1},
	   {1,4,6,4,1},
	};
	vector<vector<int>> actual_vvi = Solution().generate( numRows );
	EXPECT_EQ(actual_vvi, expected_vvi);
}
