/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <exception>

#include <gtest/gtest.h>

#include "find-and-replace-pattern.cpp"

TEST(FindAndReplacePattern, Test_abc_deq_mee_aqq_dkd_ccc__abb) {
  vector<string> words({"abc", "deq", "mee", "aqq", "dkd", "ccc"});
  string pattern("abb");

  vector<string> expected_sv({"mee", "aqq"});
  vector<string> actual_sv = Solution().findAndReplacePattern(words, pattern);

  sort(actual_sv.begin(), actual_sv.end());
  sort(expected_sv.begin(), expected_sv.end());

  EXPECT_EQ(actual_sv, expected_sv);
}

TEST(FindAndReplacePattern, Test_boo_boo__see) {
  vector<string> words({"boo", "boo", "bar"});
  string pattern("see");

  vector<string> expected_sv({"boo", "boo"});
  vector<string> actual_sv = Solution().findAndReplacePattern(words, pattern);

  sort(actual_sv.begin(), actual_sv.end());
  sort(expected_sv.begin(), expected_sv.end());

  EXPECT_EQ(actual_sv, expected_sv);
}

TEST(FindAndReplacePattern, Test_t_k_g_n_k__v) {
  vector<string> words({"t", "k", "g", "n", "k"});
  string pattern("v");

  vector<string> expected_sv(words);
  vector<string> actual_sv = Solution().findAndReplacePattern(words, pattern);

  sort(actual_sv.begin(), actual_sv.end());
  sort(expected_sv.begin(), expected_sv.end());

  EXPECT_EQ(actual_sv, expected_sv);
}

TEST(FindAndReplacePattern, Test_abc__d) {
  exception_ptr e = nullptr;
  try {
    vector<string> words({"abc"});
    string pattern("d");

    vector<string> expected_sv(words);
    vector<string> actual_sv = Solution().findAndReplacePattern(words, pattern);

    sort(actual_sv.begin(), actual_sv.end());
    sort(expected_sv.begin(), expected_sv.end());

    EXPECT_EQ(actual_sv, expected_sv);
  } catch (...) {
    e = current_exception();
  }
  EXPECT_FALSE(e == nullptr);
}
