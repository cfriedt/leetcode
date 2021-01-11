/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "valid-word-abbreviation.cpp"

TEST(ValidWordAbbreviation, Test_internationalization_i5a11o1) {
  string word = "internationalization";
  string abbr = "i5a11o1";
  bool expected_bool = true;
  bool actual_bool = Solution().validWordAbbreviation(word, abbr);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(ValidWordAbbreviation, Test_a_01) {
  string word = "a";
  string abbr = "01";
  bool expected_bool = false;
  bool actual_bool = Solution().validWordAbbreviation(word, abbr);
  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(ValidWordAbbreviation, Test_internationalization_i12iz4n) {
  string word = "internationalization";
  string abbr = "i12iz4n";
  bool expected_bool = true;
  bool actual_bool = Solution().validWordAbbreviation(word, abbr);
  EXPECT_EQ(actual_bool, expected_bool);
}

// tests that the number does not go beyond the length of the string
TEST(ValidWordAbbreviation, Test_apple_a5) {
  string word = "apple";
  string abbr = "a5";
  bool expected_bool = false;
  bool actual_bool = Solution().validWordAbbreviation(word, abbr);
  EXPECT_EQ(actual_bool, expected_bool);
}

// tests that the word and abbr do not have trailing data
TEST(ValidWordAbbreviation, Test_apple_a4g) {
  string word = "apple";
  string abbr = "a4g";
  bool expected_bool = false;
  bool actual_bool = Solution().validWordAbbreviation(word, abbr);
  EXPECT_EQ(actual_bool, expected_bool);
}
