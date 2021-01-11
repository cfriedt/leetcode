/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

using namespace std;

#include "longest-common-prefix.cpp"

TEST(LongestCommonPrefix, Test_flower_flow_flight) {
  vector<string> strs{"flower", "flow", "flight"};
  string expected_string = "fl";
  string actual_string = Solution().longestCommonPrefix(strs);
  EXPECT_EQ(actual_string, expected_string);
}

TEST(LongestCommonPrefix, Test_dog_racecar_car) {
  vector<string> strs{"dog", "racecar", "car"};
  string expected_string = "";
  string actual_string = Solution().longestCommonPrefix(strs);
  EXPECT_EQ(actual_string, expected_string);
}
