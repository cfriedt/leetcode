/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "letter-combinations-of-a-phone-number.cpp"

TEST(LetterCombinationsOfAPhoneNumber, Test_23) {
  string digits = "23";
  vector<string> expected_vs(
      {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"});
  vector<string> actual_vs = Solution().letterCombinations(digits);
  EXPECT_EQ(actual_vs, expected_vs);
}
