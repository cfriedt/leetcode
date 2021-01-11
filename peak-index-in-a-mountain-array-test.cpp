/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <vector>

#include <gtest/gtest.h>

#include "peak-index-in-a-mountain-array.cpp"

using namespace std;

TEST(PeakIndexInMountainArray, Test_0_1_0) {
  vector<int> A{{0, 1, 0}};
  int expected_int = 1;
  int actual_int = Solution().peakIndexInMountainArray(A);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(PeakIndexInMountainArray, Test_0_2_1_0) {
  vector<int> A{{0, 2, 1, 0}};
  int expected_int = 1;
  int actual_int = Solution().peakIndexInMountainArray(A);
  EXPECT_EQ(actual_int, expected_int);
}
