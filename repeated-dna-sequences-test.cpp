/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <unordered_set>
#include <vector>

#include <gtest/gtest.h>

#include "repeated-dna-sequences.cpp"

template <class T>
static inline unordered_set<T> toSet(vector<T> x) {
  unordered_set<T> y;

  for(auto& xx: x) {
    y.insert(xx);
  }

  return y;
}

TEST(RepeatedDnaSequences, Test_AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT) {
  string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  unordered_set<string> expected_us = {"AAAAACCCCC", "CCCCCAAAAA"};
  unordered_set<string> actual_us = toSet(Solution().findRepeatedDnaSequences(s));
  EXPECT_EQ(actual_us, expected_us);
}
