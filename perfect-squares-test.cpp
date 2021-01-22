/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "perfect-squares.cpp"

using namespace std;

TEST(PerfectSquares, 1) {
  EXPECT_EQ(1, Solution().numSquares(1));
}

TEST(PerfectSquares, 2) {
  EXPECT_EQ(2, Solution().numSquares(2));
}

TEST(PerfectSquares, 3) {
  EXPECT_EQ(3, Solution().numSquares(3));
}

TEST(PerfectSquares, 4) {
  EXPECT_EQ(1, Solution().numSquares(4));
}

TEST(PerfectSquares, 9) {
  EXPECT_EQ(1, Solution().numSquares(9));
}

TEST(PerfectSquares, 12) {
  EXPECT_EQ(3, Solution().numSquares(12));
}

TEST(PerfectSquares, 13) {
  EXPECT_EQ(2, Solution().numSquares(13));
}
