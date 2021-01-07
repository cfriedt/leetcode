/*
 * Copyright (c) 2020 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "flipping-an-image.cpp"

TEST(FlippingAnImage, 1_1_0__1_0_1__0_0_0) {
  vector<vector<int>> A = {
      {1, 1, 0},
      {1, 0, 1},
      {0, 0, 0},
  };
  vector<vector<int>> expected = {
      {1, 0, 0},
      {0, 1, 0},
      {1, 1, 1},
  };

  EXPECT_EQ(expected, Solution().flipAndInvertImage(A));
}

TEST(FlippingAnImage, 1_1_0_0__1_0_0_1__0_1_1_1__1_0_1_0) {
  vector<vector<int>> A = {
      {1, 1, 0, 0},
      {1, 0, 0, 1},
      {0, 1, 1, 1},
      {1, 0, 1, 0},
  };
  vector<vector<int>> expected = {
      {1, 1, 0, 0},
      {0, 1, 1, 0},
      {0, 0, 0, 1},
      {1, 0, 1, 0},
  };

  EXPECT_EQ(expected, Solution().flipAndInvertImage(A));
}
