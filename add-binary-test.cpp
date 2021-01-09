/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "add-binary.cpp"

using namespace std;

TEST(AddBinary, 11_1) { EXPECT_EQ("100", Solution().addBinary("11", "1")); }

TEST(AddBinary, 1_11) { EXPECT_EQ("100", Solution().addBinary("1", "11")); }

// multiplication by 2
TEST(AddBinary, 11_11) { EXPECT_EQ("110", Solution().addBinary("11", "11")); }

TEST(AddBinary, 1010_1011) {
  EXPECT_EQ("10101", Solution().addBinary("1010", "1011"));
}
