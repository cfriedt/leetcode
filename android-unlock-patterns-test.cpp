/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "android-unlock-patterns.cpp"

TEST(AndroidUnlockPatterns, Test_1_1) {
  int m = 1;
  int n = 1;
  int expected_int = 9;
  int actual_int = Solution().numberOfPatterns(m, n);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(AndroidUnlockPatterns, Test_1_3) {
  int m = 1;
  int n = 3;
  int expected_int = 385;
  int actual_int = Solution().numberOfPatterns(m, n);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(AndroidUnlockPatterns, Test_1_4) {
  int m = 1;
  int n = 4;
  int expected_int = 2009;
  int actual_int = Solution().numberOfPatterns(m, n);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(AndroidUnlockPatterns, Test_9_9) {
  int m = 9;
  int n = 9;
  int expected_int = 140704;
  int actual_int = Solution().numberOfPatterns(m, n);
  EXPECT_EQ(actual_int, expected_int);
}
