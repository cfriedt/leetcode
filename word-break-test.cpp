/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "word-break.cpp"

TEST(WordBreak, Test_leetcode__leet_code) {
  string s = "leetcode";
  vector<string> wordDict({
      "leet",
      "code",
  });
  bool expected_bool = true;
  bool actual_bool = Solution().wordBreak(s, wordDict);

  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(WordBreak, Test_applepenapple__apple_pen) {
  string s = "applepenapple";
  vector<string> wordDict({
      "apple",
      "pen",
  });
  bool expected_bool = true;
  bool actual_bool = Solution().wordBreak(s, wordDict);

  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(WordBreak, Test_catsandog__cats_dog_sand_and_cat) {
  string s = "catsandog";
  vector<string> wordDict({
      "cats",
      "dog",
      "sand",
      "and",
      "cat",
  });
  bool expected_bool = false;
  bool actual_bool = Solution().wordBreak(s, wordDict);

  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(WordBreak, Test_a__a) {
  string s = "a";
  vector<string> wordDict({
      "a",
  });
  bool expected_bool = true;
  bool actual_bool = Solution().wordBreak(s, wordDict);

  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(WordBreak, Test_aaaaaaaa__aaaa__aa) {
  string s = "aaaaaaa";
  vector<string> wordDict({
      "aaaa",
      "aa",
  });
  bool expected_bool = false;
  bool actual_bool = Solution().wordBreak(s, wordDict);

  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(WordBreak, Test_aaaaaaaa__aaaa__aaa) {
  string s = "aaaaaaa";
  vector<string> wordDict({
      "aaaa",
      "aaa",
  });
  bool expected_bool = true;
  bool actual_bool = Solution().wordBreak(s, wordDict);

  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(WordBreak, Test_aaab__a_aa) {
  string s = "aaab";
  vector<string> wordDict({
      "a",
      "aa",
  });
  bool expected_bool = false;
  bool actual_bool = Solution().wordBreak(s, wordDict);

  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(
    WordBreak,
    Test_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab__a_aa_aaa_aaaa_aaaaa_aaaaaa_aaaaaaa_aaaaaaaa_aaaaaaaaa_aaaaaaaaaa) {
  string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
             "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
             "aaaaaaaaaaaaaaaaaaaab";
  vector<string> wordDict({
      "a",
      "aa",
      "aaa",
      "aaaa",
      "aaaaa",
      "aaaaaa",
      "aaaaaaa",
      "aaaaaaaa",
      "aaaaaaaaa",
      "aaaaaaaaaa",
  });
  bool expected_bool = false;
  bool actual_bool = Solution().wordBreak(s, wordDict);

  EXPECT_EQ(actual_bool, expected_bool);
}

TEST(
    WordBreak,
    Test_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa__aa_aaa_aaaa_aaaaa_aaaaaa_aaaaaaa_aaaaaaaa_aaaaaaaaa_aaaaaaaaaa_ba) {
  string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
             "aaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
             "aaaaaaaaaaaaaaaaaaaaa";
  vector<string> wordDict({
      "aa",
      "aaa",
      "aaaa",
      "aaaaa",
      "aaaaaa",
      "aaaaaaa",
      "aaaaaaaa",
      "aaaaaaaaa",
      "aaaaaaaaaa",
      "ba",
  });
  bool expected_bool = false;
  bool actual_bool = Solution().wordBreak(s, wordDict);

  EXPECT_EQ(actual_bool, expected_bool);
}
