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

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    const size_t N = s.size();
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
    fill(dp[0].begin(), dp[0].end(), 0);
    for (size_t i = 1; i <= N; ++i) {
      dp[0][i] = 0;
    }

    int ret = lps(dp, s, 0, N - 1);
    if ((N & 1) == 0) {
      // even length
      ret = min(1, ret);
    }
    return ret;
  }

  int lps(vector<vector<int>> &dp, const string &s, const int L, const int R) {
    const int N = s.size();

    if (R < 0 || L >= N || L > R) {
      return 0;
    }

    if (dp[L + 1][R + 1] != -1) {
      return dp[L + 1][R + 1];
    }

    int _lps;
    if (s[L] == s[R]) {
      if ((N & 1) == 0) {
        // even length
        if (L == R) {
          return 0;
        }
      } else {
        // odd length
        if (L == R) {
          dp[L + 1][R + 1] = 1;
          return 1;
        }
      }
      if (L == R && (N & 1) == 1) {
        _lps = 1;
      } else {
        _lps = lps(dp, s, L + 1, R - 1) + 2;
      }
    } else {
      _lps = max(lps(dp, s, L, R - 1), lps(dp, s, L + 1, R));
    }

    dp[L + 1][R + 1] = _lps;
    return _lps;
  }
};
