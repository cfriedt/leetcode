/*
 * MIT License
 *
 * Copyright (c) 2018 Christopher Friedt
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <unordered_map>
#include <vector>

using namespace std;

// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
  // recursion with memoization
  // non-optimal in terms of space used
  /*
    int helper(int n, unordered_map<int, int>& mem) {
      auto it = mem.find(n);

      if (mem.end() != it) {
        return it->second;
      }

      if (n <= 2) {
        mem[n] = n;
      } else {
        mem[n] = helper(n - 1, mem) + helper(n - 2, mem);
      }

      return mem[n];
    }

    int climbStairs(int n) {
      unordered_map<int, int> mem;
      return helper(n, mem);
    }
  */

  // DP solution:
  // 1. can be broken into subproblems
  // 2. has optimal substructure
  int climbStairs(int n) {
    // number of ways to reach ith step is
    // dp[i] = dp[i-1] + dp[i-2]
    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};
