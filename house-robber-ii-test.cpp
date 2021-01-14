/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "house-robber-ii.cpp"

using namespace std;

TEST(HouseRobberIi, 2_3_2) {
  vector<int> nums = {2, 3, 2};
  EXPECT_EQ(3, Solution().rob(nums));
}

TEST(HouseRobberIi, 1_2_3_1) {
  vector<int> nums = {1, 2, 3, 1};
  EXPECT_EQ(4, Solution().rob(nums));
}

TEST(HouseRobberIi, 0) {
  vector<int> nums = {0};
  EXPECT_EQ(0, Solution().rob(nums));
}
