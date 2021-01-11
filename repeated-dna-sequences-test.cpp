/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "repeated-dna-sequences.cpp"

TEST(RepeatedDnaSequences, Test_AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT) {
  string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  vector<string> expected_vs = {"AAAAACCCCC", "CCCCCAAAAA"};
  vector<string> actual_vs = Solution().findRepeatedDnaSequences(s);
  EXPECT_EQ(actual_vs, expected_vs);
}
