/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "arithmetic-slices.cpp"

TEST(ArithmeticSlices, Test_1_2_3_4) {
  vector<int> A({1, 2, 3, 4});
  int expected_int = 3;
  int actual_int = Solution().numberOfArithmeticSlices(A);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(ArithmeticSlices, Test_1) {
  vector<int> A({1});
  int expected_int = 0;
  int actual_int = Solution().numberOfArithmeticSlices(A);
  EXPECT_EQ(actual_int, expected_int);
}
