/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "unique-morse-code-words.cpp"

using namespace std;

TEST(UniqueMorseCodeWords, gin_zen_gig_msg) {
  vector<string> words = {"gin", "zen", "gig", "msg"};
  EXPECT_EQ(2, Solution().uniqueMorseRepresentations(words));
}
