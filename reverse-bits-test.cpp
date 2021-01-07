/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "reverse-bits.cpp"

TEST(ReverseBits, 00000010100101000001111010011100) {
  EXPECT_EQ(964176192,
            Solution().reverseBits(0b00000010100101000001111010011100));
}

TEST(ReverseBits, 11111111111111111111111111111101) {
  EXPECT_EQ(3221225471,
            Solution().reverseBits(0b11111111111111111111111111111101));
}
