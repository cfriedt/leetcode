/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "greatest-sum-divisible-by-three.cpp"

using namespace std;

TEST(GreatestSumDivisibleByThree, 3_6_5_1_8) {
  vector<int> nums = {3, 6, 5, 1, 8};
  EXPECT_EQ(18, Solution().maxSumDivThree(nums));
}

TEST(GreatestSumDivisibleByThree, 4) {
  vector<int> nums = {4};
  EXPECT_EQ(0, Solution().maxSumDivThree(nums));
}

TEST(GreatestSumDivisibleByThree, 1_2_3_4_4) {
  vector<int> nums = {1, 2, 3, 4, 4};
  EXPECT_EQ(12, Solution().maxSumDivThree(nums));
}

#if 0
TEST(GreatestSumDivisibleByThree, big) {
  vector<int> nums = {366,809,6,792,822,181,210,588,344,618,341,410,121,864,191,749,637,169,123,472,358,908,235,914,322,946,738,754,908,272,267,326,587,267,803,281,586,707,94,627,724,469,568,57,103,984,787,552,14,545,866,494,263,157,479,823,835,100,495,773,729,921,348,871,91,386,183,979,716,806,639,290,612,322,289,910,484,300,195,546,499,213,8,623,490,473,603,721,793,418,551,331,598,670,960,483,154,317,834,352};
  EXPECT_EQ(12, Solution().maxSumDivThree(nums));
}
#endif
