/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: longest-arithmetic-subsequence
// url: https://leetcode.com/problems/longest-arithmetic-subsequence
// difficulty: 2
// clang-format on

#include <vector>

using namespace std;

class Solution {
public:
  int longestArithSeqLength(vector<int> &A) {
    /*
    Let N be the length of A.

    Since A[i] is in [0, 500], then we can consider all differences, d,
    to be constrained to the range [-500,500].

    let LASL(i,d) == be the longest arithmetic subsequence in the first
    i ordered elements where the difference between each element is d.

    LASL(0, d) = 0, is a base case for all d
    */
    const int N = A.size();
    constexpr int M = 500 - (-500) + 1;
    constexpr int M_2 = 500;

    vector<vector<int>> dp(N, vector<int>(M, 0));

    int max_len = 1;
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < i; ++j) {
        int d = A[i] - A[j];
        dp[i][d + M_2] = dp[j][d + M_2] + 1;
        max_len = max(max_len, dp[i][d + M_2]);
      }
    }

    return max_len + 1;
  }
};
