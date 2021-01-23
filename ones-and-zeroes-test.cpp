/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "ones-and-zeroes.cpp"

using namespace std;

TEST(OnesAndZeros, 10_0001_111001_1_0__5__3) {
  vector<string> strs = {"10", "0001", "111001", "1", "0"};
  int m = 5;
  int n = 3;
  EXPECT_EQ(4, Solution().findMaxForm(strs, m, n));
}

TEST(OnesAndZeros, 10_0_1__1__1) {
  vector<string> strs = {"10", "0", "1"};
  int m = 1;
  int n = 1;
  EXPECT_EQ(2, Solution().findMaxForm(strs, m, n));
}

TEST(OnesAndZeros, 10_0001_111001_1_0__4__3) {
  vector<string> strs = {"10", "0001", "111001", "1", "0"};
  int m = 4;
  int n = 3;
  EXPECT_EQ(3, Solution().findMaxForm(strs, m, n));
}
