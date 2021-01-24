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

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int> &arr, int difference) {
    /*
    If we proceed from the 0th element in arr to the end
    we can check if arr[i] - difference already exists in O(1) time
    by using an unordered_map<int,int>, where the key is the
    value from arr[j], 0 <= j < i, and the value is the length
    of the subsequence finishing with arr[j].

    If the key exists, then simply add a one to it for a new entry, arr[i].
    if the key does not exist, then simply set it to one (the same as adding one
    to a value not already in the map with the [] operator).

    Keep track of the maximum subsequence length with a separate variable.

    O(N)
    */

    int max_len = 0;
    unordered_map<int, int> dp;

    for (auto &a : arr) {
      dp[a] = dp[a - difference] + 1;
      max_len = max(max_len, dp[a]);
    }

    return max_len;
  }
};
