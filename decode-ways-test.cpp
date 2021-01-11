/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "decode-ways.cpp"

TEST(DecodeWays, Test_12) {
  string s = "12";
  int expected_int = 2;
  int actual_int = Solution().numDecodings(s);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(DecodeWays, Test_226) {
  string s = "226";
  int expected_int = 3;
  int actual_int = Solution().numDecodings(s);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(DecodeWays, Test_empty) {
  string s;
  int expected_int = 0;
  int actual_int = Solution().numDecodings(s);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(DecodeWays, Test_122) {
  string s = "242";
  int expected_int = 2;
  int actual_int = Solution().numDecodings(s);
  EXPECT_EQ(actual_int, expected_int);
}
