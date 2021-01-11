/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "median-of-two-sorted-arrays.cpp"

TEST(MedianOfTwoSortedArrays, Test_1_3__2) {
  vector<int> nums1({1, 3});
  vector<int> nums2({2});
  double expected_double = 2.0;
  double actual_double = Solution().findMedianSortedArrays(nums1, nums2);
  EXPECT_EQ(actual_double, expected_double);
}

TEST(MedianOfTwoSortedArrays, Test_1_2_3__1_2_3) {
  vector<int> nums1({1, 2, 3});
  vector<int> nums2({1, 2, 3});
  double expected_double = 2.0;
  double actual_double = Solution().findMedianSortedArrays(nums1, nums2);
  EXPECT_EQ(actual_double, expected_double);
}

TEST(MedianOfTwoSortedArrays, Test_1_2__3_4) {
  vector<int> nums1({1, 2});
  vector<int> nums2({3, 4});
  double expected_double = 2.5;
  double actual_double = Solution().findMedianSortedArrays(nums1, nums2);
  EXPECT_EQ(actual_double, expected_double);
}
