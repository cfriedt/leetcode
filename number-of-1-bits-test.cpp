/*
 * Copyright (c) 2020 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "number-of-1-bits.cpp"

TEST(NumberOfOneBits, 11) { EXPECT_EQ(3, Solution().hammingWeight(11)); }

TEST(NumberOfOneBits, 128) { EXPECT_EQ(1, Solution().hammingWeight(128)); }

TEST(NumberOfOneBits, FFFFFFFD) {
  EXPECT_EQ(31, Solution().hammingWeight(0xFFFFFFFD));
}
