/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "integer-break.cpp"

using namespace std;

TEST(IntegerBreak, 1) { EXPECT_EQ(1, Solution().integerBreak(1)); }

TEST(IntegerBreak, 2) { EXPECT_EQ(1, Solution().integerBreak(2)); }

TEST(IntegerBreak, 3) { EXPECT_EQ(2, Solution().integerBreak(3)); }

TEST(IntegerBreak, 10) { EXPECT_EQ(36, Solution().integerBreak(10)); }
