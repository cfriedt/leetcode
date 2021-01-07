/*
 * Copyright (c) 2020 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <gtest/gtest.h>

#include "best-time-to-buy-and-sell-stock.cpp"

using namespace std;

TEST(BestTimeToBuyAndSellStock, 7_1_5_3_6_4) {
  auto prices = vector<int>{7, 1, 5, 3, 6, 4};
  EXPECT_EQ(5, Solution().maxProfit(prices));
}

TEST(BestTimeToBuyAndSellStock, 7_6_4_3_1) {
  auto prices = vector<int>{7, 6, 4, 3, 1};
  EXPECT_EQ(0, Solution().maxProfit(prices));
}
