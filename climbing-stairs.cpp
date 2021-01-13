/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: climbing-stairs
// url: https://leetcode.com/problems/climbing-stairs
// difficulty: 1
// clang-format on

#include <vector>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    // observations
    // * at any step i, the previous step is either going to have been (i - 1)
    // or (i - 2)
    // * simple table shows the recurrance relationship NW(i) = NW(i - 1) + NW(i
    // - 2)
    // * technically there are overlapping subproblems, which makes this 1d dp,
    //   so it could be solved using a 1-d vector, but it's fairly obvious that
    //   there only needs to be a memory of size 2, which produces a solution
    // * O(N) time and O(1) space
    //
    //  i  NW(i)  NW(i-1)  NW(i-2)
    // ---------------------------
    //  1  1       1        0
    //  2  2       1        1
    //  3  3       2        1
    //  4  5       3        2
    int prev_prev = 0;
    int prev = 1;
    int result = 0;

    for (int i = 1; i <= n; prev_prev = prev, prev = result, ++i) {
      result = prev + prev_prev;
    }

    return result;
  }
};
