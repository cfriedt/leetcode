/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "longest-arithmetic-subsequence.cpp"

using namespace std;

TEST(LongestArithmeticSubsequence, 3_6_9_12) {
  vector<int> A = {3, 6, 9, 12};
  EXPECT_EQ(4, Solution().longestArithSeqLength(A));
}

TEST(LongestArithmeticSubsequence, 9_4_7_2_10) {
  vector<int> A = {9, 4, 7, 2, 10};
  EXPECT_EQ(3, Solution().longestArithSeqLength(A));
}

TEST(LongestArithmeticSubsequence, 20_1_15_3_10_5_8) {
  vector<int> A = {20, 1, 15, 3, 10, 5, 8};
  EXPECT_EQ(4, Solution().longestArithSeqLength(A));
}

TEST(LongestArithmeticSubsequence, 83_20_17_43_52_78_68_45) {
  vector<int> A = {83, 20, 17, 43, 52, 78, 68, 45};
  EXPECT_EQ(2, Solution().longestArithSeqLength(A));
}
