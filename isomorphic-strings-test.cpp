/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "isomorphic-strings.cpp"

using namespace std;

TEST(IsomorphicStrings, egg_add) {
  EXPECT_EQ(true, Solution().isIsomorphic("egg", "add"));
}

TEST(IsomorphicStrings, foo_bar) {
  EXPECT_EQ(false, Solution().isIsomorphic("foo", "bar"));
}

TEST(IsomorphicStrings, paper_title) {
  EXPECT_EQ(true, Solution().isIsomorphic("paper", "title"));
}

TEST(IsomorphicStrings, badc_bada) {
  EXPECT_EQ(false, Solution().isIsomorphic("badc", "bada"));
}
