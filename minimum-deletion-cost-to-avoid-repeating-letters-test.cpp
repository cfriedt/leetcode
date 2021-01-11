/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "minimum-deletion-cost-to-avoid-repeating-letters.cpp"

using namespace std;

TEST(MinimumDeletionCostToAvoidRepeatingLetters, abaac__1_2_3_4_5) {
  string s = "abaac";
  vector<int> cost = {1, 2, 3, 4, 5};
  EXPECT_EQ(3, Solution().minCost(s, cost));
}

TEST(MinimumDeletionCostToAvoidRepeatingLetters, abc__1_2_3) {
  string s = "abc";
  vector<int> cost = {
      1,
      2,
      3,
  };
  EXPECT_EQ(0, Solution().minCost(s, cost));
}

TEST(MinimumDeletionCostToAvoidRepeatingLetters, aabaa__1_2_3_4_1) {
  string s = "aabaa";
  vector<int> cost = {1, 2, 3, 4, 1};
  EXPECT_EQ(2, Solution().minCost(s, cost));
}
