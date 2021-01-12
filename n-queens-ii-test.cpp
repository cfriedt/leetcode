/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "n-queens-ii.cpp"

using namespace std;

TEST(NQueensIi, 1) {
  int n = 1;
  EXPECT_EQ(1, Solution().totalNQueens(n));
}

TEST(NQueensIi, 2) {
  int n = 2;
  EXPECT_EQ(0, Solution().totalNQueens(n));
}

TEST(NQueensIi, 3) {
  int n = 3;
  EXPECT_EQ(0, Solution().totalNQueens(n));
}

TEST(NQueensIi, 4) {
  int n = 4;
  EXPECT_EQ(2, Solution().totalNQueens(n));
}

TEST(NQueensIi, 5) {
  int n = 5;
  EXPECT_EQ(10, Solution().totalNQueens(n));
}

TEST(NQueensIi, 6) {
  int n = 6;
  EXPECT_EQ(4, Solution().totalNQueens(n));
}

TEST(NQueensIi, 7) {
  int n = 7;
  EXPECT_EQ(40, Solution().totalNQueens(n));
}

TEST(NQueensIi, 8) {
  int n = 8;
  EXPECT_EQ(92, Solution().totalNQueens(n));
}

TEST(NQueensIi, 9) {
  int n = 9;
  EXPECT_EQ(352, Solution().totalNQueens(n));
}
