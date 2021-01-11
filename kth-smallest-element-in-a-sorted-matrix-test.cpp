/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "kth-smallest-element-in-a-sorted-matrix.cpp"

TEST(KthSmallestElementInASortedMatrix, Test_1_5_9__10_11_13__12_13_15) {
  vector<vector<int>> matrix({
      {1, 5, 9},
      {10, 11, 13},
      {12, 13, 15},
  });
  int k = 8;
  int expected_int = 13;
  int actual_int = Solution().kthSmallest(matrix, k);
  EXPECT_EQ(actual_int, expected_int);
}
