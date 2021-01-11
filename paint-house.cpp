/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/paint-house/

  int minCost(vector<vector<int>> &costs) {

    // The most important thing to understand here is the
    // recurrance:
    //
    // When you *choose* to paint the final house, i, a certain colour,
    // j, then costs[ i ][ j ] inherits the additional cost of the *minimum*
    // of costs[ i - 1 ][ (j + 1) % 3 ] and costs[ i - 1 ][ (j + 2) % 3 ].
    //
    // That recurrance has to be calculated from 0 to i - 1 before i is
    // calculated.
    //
    // You then have to *choose* the minimum of the costs that have percolated
    // up to house i.
    //
    // That was not at all clear to my when I tried this question.
    //
    // My solution was adapted from some Java code I saw online.
    //
    // O( N ) time and O( 1 ) space.

    const int N = costs.size();

    if (0 == N) {
      return 0;
    }

    for (int i = 1; i < N; i++) {
      costs[i][0] += min(costs[i - 1][1], costs[i - 1][2]);
      costs[i][1] += min(costs[i - 1][0], costs[i - 1][2]);
      costs[i][2] += min(costs[i - 1][0], costs[i - 1][1]);
    }

    return min(costs[N - 1][0], min(costs[N - 1][1], costs[N - 1][2]));
  }
};
