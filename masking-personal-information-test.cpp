/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "masking-personal-information.cpp"

TEST(MaskingPersonalInformation, Test_LeetCodeATLeedCodeDOTcom) {
  string S = "LeetCode@LeetCode.com";
  string expected_string = "l*****e@leetcode.com";
  string actual_string = Solution().maskPII(S);
  EXPECT_EQ(actual_string, expected_string);
}

TEST(MaskingPersonalInformation, Test_ABATqqDOTcom) {
  string S = "AB@qq.com";
  string expected_string = "a*****b@qq.com";
  string actual_string = Solution().maskPII(S);
  EXPECT_EQ(actual_string, expected_string);
}

TEST(MaskingPersonalInformation, Test_1234567890) {
  string S = "1(234)567-890";
  string expected_string = "***-***-7890";
  string actual_string = Solution().maskPII(S);
  EXPECT_EQ(actual_string, expected_string);
}

TEST(MaskingPersonalInformation, Test_86_10_12345678) {
  string S = "86-(10)12345678";
  string expected_string = "+**-***-***-5678";
  string actual_string = Solution().maskPII(S);
  EXPECT_EQ(actual_string, expected_string);
}
