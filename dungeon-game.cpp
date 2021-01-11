/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

// https://leetcode.com/problems/minimum-path-sum
//
// I tried a number of solutions, but did not think about going
// backwards. This solution seems to take the cake.
// https://goo.gl/Ji3m4J

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    int M = dungeon.size();
    int N = (0 == M) ? 0 : dungeon[0].size();

    if (0 == M || 0 == N) {
      return 1;
    }

    // hp[i][j] represents the min hp needed at position (i, j)
    // Add dummy row and column at bottom and right side
    vector<vector<int>> hp(M + 1, vector<int>(N + 1, INT_MAX));
    hp[M][N - 1] = 1;
    hp[M - 1][N] = 1;
    for (int i = M - 1; i >= 0; i--) {
      for (int j = N - 1; j >= 0; j--) {
        int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
        hp[i][j] = need <= 0 ? 1 : need;
      }
    }
    return hp[0][0];
  }
};
