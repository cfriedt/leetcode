/*
 * MIT License
 *
 * Copyright (c) 2018 Christopher Friedt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <gtest/gtest.h>

#include "3sum.cpp"

/*
TEST( TwoSum, Test_n1_0_1_2_n1_n4 ) {
	vector<int> nums({-1,0,1,2,-1,-4});
	vector<vector<int>> expected_vvi({{-1,0,1},{-1,-1,2}});
	vector<vector<int>> actual_vvi = Solution().threeSum( nums );

	unordered_set<vector<int>> expected_uvi = to_unordered_set( expected_vvi );
	unordered_set<vector<int>> actual_uvi = to_unordered_set( actual_vvi );

	EXPECT_EQ(actual_uvi, expected_uvi);
}

TEST( TwoSum, Test_3_n2_1_0 ) {
	vector<int> nums({3,-2,1,0});
	vector<vector<int>> expected_vvi;
	vector<vector<int>> actual_vvi = Solution().threeSum( nums );

	unordered_set<vector<int>> expected_uvi = to_unordered_set( expected_vvi );
	unordered_set<vector<int>> actual_uvi = to_unordered_set( actual_vvi );

	EXPECT_EQ(actual_uvi, expected_uvi);
}

TEST( TwoSum, Test_n4_n2_n2_0_1_2_2_2_3_3_4_4_6_6 ) {
	vector<int> nums({-4,-2,-2,0,1,2,2,2,3,3,4,4,6,6});
	vector<vector<int>> expected_vvi({{-4,-2,6},{-4,0,4},{-4,1,3},{-4,2,2},{-2,-2,4},{-2,0,2}});
	vector<vector<int>> actual_vvi = Solution().threeSum( nums );

	unordered_set<vector<int>> expected_uvi = to_unordered_set( expected_vvi );
	unordered_set<vector<int>> actual_uvi = to_unordered_set( actual_vvi );

	EXPECT_EQ(actual_uvi, expected_uvi);
}

TEST( TwoSum, Test_n4_n2_1_n5_n4_n4_4_n2_0_4_0_n2_3_1_n5_0 ) {
	vector<int> nums({-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0});
	vector<vector<int>> expected_vvi({{-5,1,4},{-4,0,4},{-4,1,3},{-2,-2,4},{-2,1,1},{0,0,0}});
	vector<vector<int>> actual_vvi = Solution().threeSum( nums );

	unordered_set<vector<int>> expected_uvi = to_unordered_set( expected_vvi );
	unordered_set<vector<int>> actual_uvi = to_unordered_set( actual_vvi );

	EXPECT_EQ(actual_uvi, expected_uvi);
}
*/

TEST( TwoSum, Test_n4_n1_n4_0_2_n2_n4_n3_2_3_3_n4 ) {
	vector<int> nums({-4,-1,-4,0,2,-2,-4,-3,2,-3,2,3,3,-4});
	vector<vector<int>> expected_vvi({{-4,2,2},{-3,0,3},{-2,-1,3},{-2,0,2}});
	vector<vector<int>> actual_vvi = Solution().threeSum( nums );

	unordered_set<vector<int>> expected_uvi = to_unordered_set( expected_vvi );
	unordered_set<vector<int>> actual_uvi = to_unordered_set( actual_vvi );

	EXPECT_EQ(actual_uvi, expected_uvi);
}
