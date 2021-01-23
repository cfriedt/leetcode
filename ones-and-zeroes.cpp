/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: ones-and-zeros
// url: https://leetcode.com/problems/ones-and-zeroes
// difficulty: 2
// clang-format on

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  // this is a 2D 1-0 Knapsack problem where
  // each item is either included or not included
  // in the optimal subset and there are 2 different weights
  int findMaxForm(vector<string> &strs, int m, int n) {
    int N = strs.size();

    // create the weight vectors
    w0 = vector<int>(N);
    w1 = vector<int>(N);
    for (int i = 0; i < N; ++i) {
      w0[i] = count(strs[i].begin(), strs[i].end(), '0');
      w1[i] = strs[i].size() - w0[i];
    }

    // create the values vectors
    // this is mainly for "muscle memory" - with the
    // 0-1 Knapsack problem, elements can still have
    // different weights.
    val = vector<int>(N, 1);

    // create a DP area
    dp = vector<vector<vector<int>>>(
        N + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

    // after we have counted 0's and 1's in strs, it is actually not needed
    // anymore
    return KS(N, m, n);
  }

protected:
  // "weight" in 0's of strs[i]
  vector<int> w0;
  // "weight" in 1's of strs[i]
  vector<int> w1;
  // values of each item
  vector<int> val;

  // memoization area for Dynamic Programming solution
  vector<vector<vector<int>>> dp;

  int KS(int i, int m, int n) {

    // cout << "looking up dp[" << i << "][" << m << "][" << n << "]" << endl;
    auto &result = dp[i][m][n];
    if (result != -1) {
      return result;
    }

    if (i == 0) {
      result = 0;
      return 0;
    }

    if (m == 0 && n == 0) {
      result = 0;
      return 0;
    }

    if (w0[i - 1] > m || w1[i - 1] > n) {
      result = KS(i - 1, m, n);
      return result;
    }

    auto t1 = KS(i - 1, m, n);
    auto t2 = val[i - 1] + KS(i - 1, m - w0[i - 1], n - w1[i - 1]);

    result = max(t1, t2);
    return result;
  }
};
