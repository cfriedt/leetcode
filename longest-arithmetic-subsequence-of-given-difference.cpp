/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: longest-arithmetic-subsequence-of-given-difference
// url: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference
// difficulty: 2
// clang-format on

#include <climits>
#include <vector>

using namespace std;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (size_t i = 0, N = v.size(); i < N; ++i) {
    os << v[i];
    if (i < N - 1) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    /*
    Let's say that arr is length 1, e.g. A = [1], and difference is -42.

    Would the longest subsequence be 1 as a base case? What if A had length
    0? Would the longest subsequence be 0 as a base case?

    Say A = [1,2,3,4] and difference == 1

    i  j  A[i]  A[j]  d  LS(i)  LS(j)
    ---------------------------------
    0  -  1     -     -  1      -
    1  0  2     1     1  2      1
    2  0  3     1     2  1      1
    2  1  3     2     1  3      2
    3  0  4     1     3  1      1
    3  1  4     2     2  1      2
    3  2  4     3     1  4      3

    LS(i) = 1 + max(LS(j)), 0 < j < i and d = A[i] - A[j] == difference
          = 1 if no such j exists

    There is a problem though, in that we still need to remember the max
    of LS(.), because the max will not necessarily be at the last position.
    To solve that, maintain a max_len variable initialized to INT_MIN.
    */
    int N = arr.size();
    vector<int> dp(N, 1);
    int max_len = INT_MIN;

    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < i; ++j) {
        if (arr[i] - arr[j] == difference) {
          dp[i] = max(dp[i], 1 + dp[j]);
        }
      }
      max_len = max(max_len, dp[i]);
    }

    // cout << "arr: " << arr << ", difference: " << difference << endl;
    // cout << "dp: " << dp << endl;

    return max_len;
  }
};
