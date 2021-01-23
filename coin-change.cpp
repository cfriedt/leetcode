/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: coin-change
// url: https://leetcode.com/problems/coin-change
// difficulty: 2
// clang-format on

#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int FC(unordered_map<int, int> &dp, const vector<int> &coins, int n) {

    auto it = dp.find(n);
    if (dp.end() != it) {
      return it->second;
    }

    int mmin = INT_MAX;
    for (auto &c : coins) {
      if (c > n) {
        continue;
      }

      int r = FC(dp, coins, n - c);
      if (r != -1) {
        mmin = min(mmin, r);
      }
    }

    if (mmin == INT_MAX) {
      dp[n] = -1;
      return -1;
    }

    dp[n] = 1 + mmin;
    return 1 + mmin;
  }

  int coinChange(vector<int> &coins, int amount) {
    /*
    Let's think about a greedy algorithm first

    if we first sort the coins, then start at the higher end
    we take off the largest amount possible until amount is less than the
    highest-valued coin.

    that would certainly minimize the number of coins we needed to
    give out in change.

    Is there a possibility that we might not be able to provide exact change
    using the greedy algorithm? Maybe?

    An alternative is to start at the other end - so a not greedy algorithm.

    We could potentially create an unordered_map<int,int> where the key is
    the amount and the value is the fewest coins for amount n. We could start
    out with FC(0) = 0, and for each coin, say FC(coin[i]) = 1. Then with the
    recursion, we would be looking at FC(n) = min(FC(n), FC(n - coins[i])), for
    all i. Use recursion first, and then potentially look at optimizing with a
    stack. This would be kind of like a depth-first search.

    Since amount is limited to 10000, it might be a viable option to go bottom
    up.
    */

    unordered_map<int, int> dp;
    dp[0] = 0;
    for (auto &c : coins) {
      dp[c] = 1;
    }

    return FC(dp, coins, amount);
  }
};
