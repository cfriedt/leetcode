/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "n-queens.cpp"

using namespace std;

TEST(NQueens, diag_up) {
  EXPECT_EQ(size_t(0), Solution::diag_up(0, 0));
  EXPECT_EQ(size_t(1), Solution::diag_up(1, 0));
  EXPECT_EQ(size_t(1), Solution::diag_up(0, 1));
  EXPECT_EQ(size_t(2), Solution::diag_up(2, 0));
  EXPECT_EQ(size_t(2), Solution::diag_up(1, 1));
  EXPECT_EQ(size_t(2), Solution::diag_up(0, 2));
  EXPECT_EQ(size_t(4), Solution::diag_up(2, 2));
}

TEST(NQueens, diag_down) {
  EXPECT_EQ(size_t(2), Solution::diag_down(3, 0, 0));
  EXPECT_EQ(size_t(1), Solution::diag_down(3, 2, 1));
  EXPECT_EQ(size_t(4), Solution::diag_down(3, 0, 2));
  EXPECT_EQ(size_t(2), Solution::diag_down(3, 2, 2));
}

TEST(NQueens, 1) {
  int n = 1;
  vector<vector<string>> expected = {{"Q"}};
  EXPECT_EQ(expected, Solution().solveNQueens(n));
}

TEST(NQueens, 2) {
  int n = 2;
  EXPECT_EQ(size_t(0), Solution().solveNQueens(n).size());
}

TEST(NQueens, 3) {
  int n = 3;
  EXPECT_EQ(size_t(0), Solution().solveNQueens(n).size());
}

TEST(NQueens, 4) {
  int n = 4;
  vector<vector<string>> expected = {{".Q..", "...Q", "Q...", "..Q."},
                                     {"..Q.", "Q...", "...Q", ".Q.."}};
  EXPECT_EQ(expected, Solution().solveNQueens(n));
}

TEST(NQueens, 5) {
  int n = 5;
  EXPECT_EQ(size_t(10), Solution().solveNQueens(n).size());
}

TEST(NQueens, 6) {
  int n = 6;
  EXPECT_EQ(size_t(4), Solution().solveNQueens(n).size());
}

TEST(NQueens, 7) {
  int n = 7;
  EXPECT_EQ(size_t(40), Solution().solveNQueens(n).size());
}

TEST(NQueens, 8) {
  int n = 8;
  EXPECT_EQ(size_t(92), Solution().solveNQueens(n).size());
}

TEST(NQueens, 9) {
  int n = 9;
  EXPECT_EQ(size_t(352), Solution().solveNQueens(n).size());
}
