/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: integer-break
// url: https://leetcode.com/problems/integer-break
// difficulty: 2
// clang-format on

#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  using dp_t = unordered_map<int, int>;
  int integerBreak(int n) {
    /*
    Let's say we're given the number 3. How many different ways can we generate
    the number 3 from the sum of at least two positive integers?
    1 + 1 + 1, product is 1
    2 + 1, product is 2
    1 + 2, product is 2
    So MP(3) is 2.

             MP(3)
          -1 /  \ -2
        MP(2)    MP(1)

    We know that MP(2) is 1 and we can extrapolate that MP(1) is also 1. Then we
    can figure out that

    MP(n) = max(i * MP(n - i), i * (n - i)), for i in [1, n)
          = 1, if n <= 2

    It becomes evident, that for larger numbers, there is very obvious
    overlapping of subproblems.
    */
    dp_t dp;
    dp[1] = 1;
    dp[2] = 1;

    return MP(dp, n);
  }

  int MP(dp_t &dp, int n) {
    auto it = dp.find(n);
    if (dp.end() != it) {
      return it->second;
    }

    int max_product = INT_MIN;
    for (int i = 1; i < n; ++i) {
      max_product = max(max_product, i * MP(dp, n - i));
      max_product = max(max_product, i * (n - i));
    }

    dp[n] = max_product;
    return max_product;
  }
};
