/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: filling-bookcase-shelves
// url: https://leetcode.com/problems/filling-bookcase-shelves
// difficulty: 2
// clang-format on

#include <climits>
#include <vector>

using namespace std;

class Solution {
public:

  int minHeightShelves(vector<vector<int>> &books, int shelf_width) {
    const size_t N = books.size();
    auto dp = vector<int>(N + 1, INT_MAX);
    dp[0] = 0;
    for(size_t i = 0; i < N; ++i) {
      for(int j = i, width = 0, height = 0; j >= 0; --j) {
        width += books[j][0];
        if (width > shelf_width) {
          break;
        }
        height = max(height, books[j][1]);
        dp[i + 1] = min(dp[i + 1], dp[j] + height);
      }
    }

    return dp[N];
  }
};
