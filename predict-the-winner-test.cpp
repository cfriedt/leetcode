/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "predict-the-winner.cpp"

TEST(PredictTheWinner, Test_1_5_2) {
  vector<int> nums({1, 5, 2});
  bool expected_bool(false);
  bool actual_bool = Solution().PredictTheWinner(nums);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(PredictTheWinner, Test_1_5_233_7) {
  vector<int> nums({1, 5, 233, 7});
  bool expected_bool(true);
  bool actual_bool = Solution().PredictTheWinner(nums);
  EXPECT_EQ(actual_bool, expected_bool);
}
