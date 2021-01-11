/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "two-sum.cpp"

TEST(TwoSum, Test_2_7_11_15_9) {
  vector<int> nums({2, 7, 11, 15});
  int target(9);
  vector<int> expected_vi({0, 1});
  vector<int> actual_vi = Solution().twoSum(nums, target);
  EXPECT_EQ(actual_vi, expected_vi);
}

TEST(TwoSum, Test_3_2_4_6) {
  vector<int> nums({3, 2, 4});
  int target(6);
  vector<int> expected_vi({1, 2});
  vector<int> actual_vi = Solution().twoSum(nums, target);
  EXPECT_EQ(actual_vi, expected_vi);
}

TEST(TwoSum, Test_3_3_6) {
  vector<int> nums({3, 3});
  int target(6);
  vector<int> expected_vi({0, 1});
  vector<int> actual_vi = Solution().twoSum(nums, target);
  EXPECT_EQ(actual_vi, expected_vi);
}
