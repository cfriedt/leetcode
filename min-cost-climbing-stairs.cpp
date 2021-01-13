/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: min-cost-climbing-stairs
// url: https://leetcode.com/problems/min-cost-climbing-stairs
// difficulty: 1
// clang-format on

#include <vector>

using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    // clang-format off
    // C(i) = min(C(i - 1), C(i - 2)) + cost[i]
    //      = cost[i], i < 2
    //
    // The exit criteria are to successfully arrive at either N-1 or N-2
    // since from N-2 it's possible to climb 2 stairs at once to get to N.
    //
    // Eg.               v--- goal is 1 past the last array element
    // cost = [10,15,20]
    // i  cost[i]  C(i)   C(i - 1)  C(i - 2)  comment
    // ----------------------------------------------
    // 0  10       10     0         0
    // 1  15       15    10         0         stop here, because i >= N - 2 && C(1) < cost[2] OR set C(2) = C(1)
    // 2  20       15*   15         10
    //
    // Eg.
    // cost = [1,100,1,1,1,100,1,1,100,1]
    // i  cost[i]  C(i)   C(i - 1)  C(i - 2)  comment
    // ----------------------------------------------
    // 0  1        1      0         0
    // 1  100      100    1         0
    // 2  1        2      100       1
    // 3  1        3      2         100
    // 4  1        3      3         2
    // 5  100      103    3         3
    // 6  1        4      103       3
    // 7  1        5      4         103
    // 8  100      104    5         4
    // 9  1        6      104       5
	// Eg.
	// cost = [0,1,1,1]
	// i  cost[i]  C(i)   C(i - 1)  C(i - 2)  comment
	// ----------------------------------------------
	// 0  0        0      0         0
	// 1  1        1      0         0
	// 2  1        1      1         0
	// 3  1        1*     1         1
    // clang-format on
    const int N = cost.size();
    for (int i = 2; i < N; ++i) {
      int t = cost[i] + min(cost[i - 1], cost[i - 2]);
      if (i == N - 1) {
        if (cost[i - 1] < t) {
          cost[i] = cost[i - 1];
          break;
        }
      }
      cost[i] = t;
    }

    return cost[N - 1];
  }
};
