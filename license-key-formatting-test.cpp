/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "license-key-formatting.cpp"

TEST(LicenseKeyFormatting, Test_5F3Z_2e_9_w__4) {
  string S = "5F3Z-2e-9-w";
  int K = 4;
  string expected_string = "5F3Z-2E9W";
  string actual_string = Solution().licenseKeyFormatting(S, K);

  EXPECT_EQ(actual_string, expected_string);
}

TEST(LicenseKeyFormatting, Test_2_5g_3_J__2) {
  string S = "2-5g-3-J";
  int K = 2;
  string expected_string = "2-5G-3J";
  string actual_string = Solution().licenseKeyFormatting(S, K);

  EXPECT_EQ(actual_string, expected_string);
}
