/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "longest-substring-without-repeating-characters.cpp"

TEST(LongestSubstringWithoutRepeatingCharacters, Test_abcabcbb) {
  string s("abcabcbb");
  int expected_int = 3;
  int actual_int = Solution().lengthOfLongestSubstring(s);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(LongestSubstringWithoutRepeatingCharacters, Test_bbbbb) {
  string s("bbbbb");
  int expected_int = 1;
  int actual_int = Solution().lengthOfLongestSubstring(s);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(LongestSubstringWithoutRepeatingCharacters, Test_pwwkew) {
  string s("pwwkew");
  int expected_int = 3;
  int actual_int = Solution().lengthOfLongestSubstring(s);
  EXPECT_EQ(actual_int, expected_int);
}

TEST(LongestSubstringWithoutRepeatingCharacters, Test_dvdf) {
  string s("dvdf");
  int expected_int = 3;
  int actual_int = Solution().lengthOfLongestSubstring(s);
  EXPECT_EQ(actual_int, expected_int);
}
