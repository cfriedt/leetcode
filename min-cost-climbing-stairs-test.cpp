/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "min-cost-climbing-stairs.cpp"

using namespace std;

TEST(MinCostClimbingStairs, 10_15_20) {
  vector<int> cost = {10, 15, 20};
  EXPECT_EQ(15, Solution().minCostClimbingStairs(cost));
}

TEST(MinCostClimbingStairs, 1_100_1_1_1_100_1_1_100_1) {
  vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  EXPECT_EQ(6, Solution().minCostClimbingStairs(cost));
}

TEST(MinCostClimbingStairs, 0_1_1_1_1) {
  vector<int> cost = {0, 1, 1, 1};
  EXPECT_EQ(1, Solution().minCostClimbingStairs(cost));
}
