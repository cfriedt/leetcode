/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: greatest-sum-divisible-by-three
// url: https://leetcode.com/problems/greatest-sum-divisible-by-three
// difficulty: 2
// clang-format on

#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSumDivThree(vector<int> &nums) {
    constexpr int M = 3;
    array<int, M> dp;
    dp.fill(INT_MIN);
    dp[0] = 0;

    for (auto &num : nums) {
      auto prev = dp;
      for (int k = 0; k < M; ++k) {
        int x = (k - num % M + M) % M;
        dp[k] = max(prev[k], num + prev[x]);
      }
    }

    return dp[0] < 0 ? 0 : dp[0];
  }
};
