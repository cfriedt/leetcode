/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "divisor-game.cpp"

using namespace std;

TEST(DivisorGame, 2) { EXPECT_EQ(true, Solution().divisorGame(2)); }

TEST(DivisorGame, 3) { EXPECT_EQ(false, Solution().divisorGame(3)); }

TEST(DivisorGame, 4) { EXPECT_EQ(true, Solution().divisorGame(4)); }

TEST(DivisorGame, 5) { EXPECT_EQ(false, Solution().divisorGame(5)); }
