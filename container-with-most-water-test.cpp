/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

using namespace std;

#include "container-with-most-water.cpp"

TEST(ContainerWithMostWater, Test_1_8_6_2_5_4_8_3_7) {
  vector<int> height({1, 8, 6, 2, 5, 4, 8, 3, 7});
  int expected_int = 49;
  int actual_int = Solution().maxArea(height);
  EXPECT_EQ(actual_int, expected_int);
}
