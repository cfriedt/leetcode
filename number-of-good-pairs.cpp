/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <sstream>

#include <array>
#include <unordered_map>
#include <vector>

using namespace std;

// name: number-of-good-pairs
// url: https://leetcode.com/problems/number-of-good-pairs
// difficulty: 1

static int choose(int n, int k) {

  // C(n, k) := n! / (k!*(n - k)!)
  //     := n(n-1)(n-2)..(n-k+1)/(k(k-1)(k-2)..1)
  // C(n, k) == C(n, k - n) (binomial theorem)
  if (n - k < k) {
    k = n - k;
  }

  int val = 1;

  for (int i = 0; i < k; ++i) {
    val *= (n - i);
    val /= (i + 1);
  }

  return val;
}

class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    array<int, 101> hist;
    hist.fill(0);
    array<int, 101> dp;
    dp.fill(0);

    // O(N)
    for (auto &n : nums) {
      hist[n]++;
    }

    int r = 0;
    for (const auto &n : hist) {
      if (n >= 2) {
        if (dp[n] == 0) {
          dp[n] = choose(n, 2);
        }
        r += dp[n];
      }
    }

    return r;
  }
};
