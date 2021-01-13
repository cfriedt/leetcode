/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "decode-string.cpp"

using namespace std;

TEST(DecodeString, 3_a_2_bc_) {
  EXPECT_EQ("aaabcbc", Solution().decodeString("3[a]2[bc]"));
}

TEST(DecodeString, 3_a2_c__) {
  EXPECT_EQ("accaccacc", Solution().decodeString("3[a2[c]]"));
}

TEST(DecodeString, 2_abc_3_cd_ef) {
  EXPECT_EQ("abcabccdcdcdef", Solution().decodeString("2[abc]3[cd]ef"));
}

TEST(DecodeString, abc3_cd_xyz) {
  EXPECT_EQ("abccdcdcdxyz", Solution().decodeString("abc3[cd]xyz"));
}
