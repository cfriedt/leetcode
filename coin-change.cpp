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
  int coinChange(vector<int> &coins, int amount) {
/*
If we look at the lowest coin value we could possibly have, 1,
then it's easy to turn this problem into a 1-D DP problem, where
we have an array of possible amounts in the range [0,amount].

A base case is FC(0) - fewest coins to make $0 is obviously 0.

The recursion is:
FC(n) = 0, if n <= 0
      = 1, if n in coins
      = 1 + min(FC(n - c)), for c in coins
      = inf, if no coins can sum up to amount n
*/
    // we choose inf to be INT_MAX because below we add 1 to dp[.]. If the value
    // were INT_MAX, then it would roll over to INT_MIN.
    constexpr int inf = INT_MAX - 1;
    vector<int> dp(amount + 1, inf);
    dp[0] = 0;

/*
say coins = [1, 2, 5], amount = 11
n  c  FC(n-c) min  FC(n)  comment
0  -    -     -    0      zero coins for amount zero
1  -    -     -    1      1 coin for anything in coins
2  -    -     -    1      "
5  -    -     -    1      "
6  1    1     2    2      5 + 1 => 2 coins
6  2   inf    2    2      '
6  5    1     2    2      '
7  1    2     3    3      5 + 1 + 1 => 3 coins
7  2    1     2    2      5 + 2 => 2 coins
7  5   inf    2    2      '
...
*/

    // O(N)
    for (int n = 1; n <= amount; ++n) {
      // O(1) - maximum number of different types of coins is 12
      for (auto& c: coins) {
        if (n - c >= 0) {
          // choose inf to avoid integer rollover here.
          dp[n] = min(dp[n], 1 + dp[n - c]);
        }
      }
    }

    if (dp[amount] == inf) {
      // we were unable to arrive at amount using any sum from any coins
      return -1;
    }

    // the fewest coins to get amount, or FC(n)
    return dp[amount];
  }
};
