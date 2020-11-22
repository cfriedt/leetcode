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

#include <string>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    /*
    So this is a DP question, and therefore we are searching for
    1. Optimal substructure
    2. Overlapping subproblems

    Let's look for the optimal substructure - i.e evidence that the
    problem can be solved using recursion and that it can be broken
    down to similar, smaller subproblems.

    Consider

    === 1 ===
    if the last two entries in 2 different sequences match.
    i.e. x[m] == y[n]. Then

    lcs(x, m, y, n) = lcs(x, m - 1, y, n - 1) + x[m]

    For example,
    x = A
    y = A

    lcs(x, 1, y, 1) = lcs(x, 0, y, 0) + x[1] // this example uses a weird
    indexing convention = "" + "A" Additionally,

    x = ABCE
    y = ABDE

    lcs(x, 4, y, 4) = lcs(x, 3, y, 3) + x[4]
                    = "AB" + "E"
                    = "ABE"

    Otherwise,

    === 2 ===
    if x[m] != y[n], then

    lcs(x, m, y, n) = max(lcs(x, m - 1, n), lcs(x, m, n - 1))

    For example, say
    x = ABC, m = 3
    y = ABD, n = 3

    lcs(x, 4, y, 3) = max(lcs(x, 3, y, 3), lcs(x, 4, 2))
                    = max("AB", "AB")
                    = "AB"

    and additionally,
    x = ABCD
    y = ABE

    lcs(x, 4, y, 3) = max(lcs(x, 3, y, 3), lcs(x, 4, y, 2))
                    = max("AB", "AB")
                    = "AB"

    */
    // map the 'x' size onto the upper 32 bits and the
    // 'y' size onto the lower 32 bits.
    unordered_map<uint64_t, int> dp;
    return lcs(dp, text1, text1.size(), text2, text2.size());
  }

  int lcs(unordered_map<uint64_t, int> &dp, const string &x, int m,
          const string &y, int n) {
    if (m == 0 || n == 0) {
      return 0;
    }

    uint64_t key = (uint64_t(m) << 32) | (uint64_t(n) << 0);
    auto it = dp.find(key);
    if (dp.end() == it) {
      int _lcs;
      if (x[m - 1] == y[n - 1]) {
        _lcs = 1 + lcs(dp, x, m - 1, y, n - 1);
      } else {
        _lcs = max(lcs(dp, x, m - 1, y, n), lcs(dp, x, m, y, n - 1));
      }
      int val = _lcs;
      dp[key] = val;
      return _lcs;
    } else {
      return it->second;
    }
  }
};
