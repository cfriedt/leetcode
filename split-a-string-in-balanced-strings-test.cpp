/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "split-a-string-in-balanced-strings.cpp"

TEST(SplitAStringInBalancedStrings, Test_RLRRLLRLRL) {
  string input = "RLRRLLRLRL";
  vector<string> expected_vs = {
      "RL",
      "RRLL",
      "RL",
      "RL",
  };
  int expected_int = expected_vs.size();
  int actual_int = Solution().balancedStringSplit(input);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(SplitAStringInBalancedStrings, Test_RLLLLRRRLR) {
  string input = "RLLLLRRRLR";
  vector<string> expected_vs = {
      "RL",
      "LLLRRR",
      "LR",
  };
  int expected_int = expected_vs.size();
  int actual_int = Solution().balancedStringSplit(input);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(SplitAStringInBalancedStrings, Test_LLLLRRRR) {
  string input = "LLLLRRRR";
  vector<string> expected_vs = {
      "LLLLRRRR",
  };
  int expected_int = expected_vs.size();
  int actual_int = Solution().balancedStringSplit(input);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(SplitAStringInBalancedStrings, Test_RLRRRLLRLL) {
  string input = "RLRRRLLRLL";
  vector<string> expected_vs = {
      "RL",
      "RRRLLRLL",
  };
  int expected_int = expected_vs.size();
  int actual_int = Solution().balancedStringSplit(input);
  EXPECT_EQ(actual_int, expected_int);
}
