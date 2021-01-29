/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "the-skyline-problem.cpp"

using namespace std;

TEST(TheSkylineProblem, 2_9_10__3_7_15__5_12_12__15_20_10__19_24_8) {
  vector<vector<int>> buildings = {
      {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
  vector<vector<int>> expected = {{2, 10},  {3, 15}, {7, 12}, {12, 0},
                                  {15, 10}, {20, 8}, {24, 0}};
  EXPECT_EQ(expected, Solution().getSkyline(buildings));
}

TEST(TheSkylineProblem, 0_2_3__2_5_3) {
  vector<vector<int>> buildings = {{0, 2, 3}, {2, 5, 3}};
  vector<vector<int>> expected = {{0, 3}, {5, 0}};
  EXPECT_EQ(expected, Solution().getSkyline(buildings));
}

#if 0
TEST(TheSkylineProblem, 0_2147483647_2147483647) {
  vector<vector<int>> buildings = {{0, 2147483647, 2147483647}};
  vector<vector<int>> expected = {{2147483647, 0}};
  EXPECT_EQ(expected, Solution().getSkyline(buildings));
}
#endif
