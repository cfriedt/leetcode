/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "valid-palindrome-ii.cpp"

TEST(ValidPalindromeIi, Test_x) {
  string s = "x";
  bool expected_bool = true;
  bool actual_bool = Solution().validPalindrome(s);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(ValidPalindromeIi, Test_abba) {
  string s = "abba";
  bool expected_bool = true;
  bool actual_bool = Solution().validPalindrome(s);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(ValidPalindromeIi, Test_abca) {
  string s = "abca";
  bool expected_bool = true;
  bool actual_bool = Solution().validPalindrome(s);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(ValidPalindromeIi, Test_abcdefg) {
  string s = "abcdefg";
  bool expected_bool = false;
  bool actual_bool = Solution().validPalindrome(s);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(ValidPalindromeIi, Test_dabbcacd) {
  string s = "dabbcacd";
  bool expected_bool = false;
  bool actual_bool = Solution().validPalindrome(s);
  EXPECT_EQ(actual_bool, expected_bool);
}
