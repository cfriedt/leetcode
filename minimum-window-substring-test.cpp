/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "minimum-window-substring.cpp"

TEST(MinimumWindowSubstring, Test_ADOBECODEBANC_ABC) {
  string s("ADOBECODEBANC");
  string t("ABC");
  string expected_string("BANC");
  string actual_string = Solution().minWindow(s, t);
  EXPECT_EQ(actual_string, expected_string);
}

TEST(MinimumWindowSubstring, Test_aa_aa) {
  string s("aa");
  string t("aa");
  string expected_string("aa");
  string actual_string = Solution().minWindow(s, t);
  EXPECT_EQ(actual_string, expected_string);
}

TEST(MinimumWindowSubstring, Test_bbaa_aba) {
  string s("bbaa");
  string t("aba");
  string expected_string("baa");
  string actual_string = Solution().minWindow(s, t);
  EXPECT_EQ(actual_string, expected_string);
}
