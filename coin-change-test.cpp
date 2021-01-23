/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "coin-change.cpp"

using namespace std;

TEST(CoinChange, 1_2_5__11) {
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  EXPECT_EQ(3, Solution().coinChange(coins, amount));
}

TEST(CoinChange, 2__3) {
  vector<int> coins = {2};
  int amount = 3;
  EXPECT_EQ(-1, Solution().coinChange(coins, amount));
}

TEST(CoinChange, 1__0) {
  vector<int> coins = {1};
  int amount = 0;
  EXPECT_EQ(0, Solution().coinChange(coins, amount));
}

TEST(CoinChange, 1__1) {
  vector<int> coins = {1};
  int amount = 1;
  EXPECT_EQ(1, Solution().coinChange(coins, amount));
}

TEST(CoinChange, 1__2) {
  vector<int> coins = {1};
  int amount = 2;
  EXPECT_EQ(2, Solution().coinChange(coins, amount));
}
