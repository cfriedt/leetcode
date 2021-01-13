/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "climbing-stairs.cpp"

using namespace std;

TEST(ClimbingStairs, 1) { EXPECT_EQ(1, Solution().climbStairs(1)); }

TEST(ClimbingStairs, 2) { EXPECT_EQ(2, Solution().climbStairs(2)); }

TEST(ClimbingStairs, 3) { EXPECT_EQ(3, Solution().climbStairs(3)); }

TEST(ClimbingStairs, 4) { EXPECT_EQ(5, Solution().climbStairs(4)); }
