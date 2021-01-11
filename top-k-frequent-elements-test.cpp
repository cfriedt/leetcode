/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "top-k-frequent-elements.cpp"

TEST(TopKFrequentElements, Test_1_1_1_2_2_3__2) {
  vector<int> nums({1, 1, 1, 2, 2, 3});
  int k = 2;
  vector<int> expected_vi({1, 2});
  vector<int> actual_vi = Solution().topKFrequent(nums, k);
  EXPECT_EQ(actual_vi, expected_vi);
}

TEST(TopKFrequentElements, Test_1__1) {
  vector<int> nums({1});
  int k = 1;
  vector<int> expected_vi({1});
  vector<int> actual_vi = Solution().topKFrequent(nums, k);
  EXPECT_EQ(actual_vi, expected_vi);
}
