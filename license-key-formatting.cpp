/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <algorithm>
#include <string>

using namespace std;

// https://leetcode.com/problems/license-key-formatting/

class Solution {
public:
  string licenseKeyFormatting(string S, int K) {
    string R;

    // filter dashes and convert S to uppercase, also reverse it
    for (int i = S.size() - 1; i >= 0; --i) {
      if ('-' == S[i])
        continue;
      R += ::toupper(S[i]);
    }
    S = R;
    R.clear();

    // format R so that it is in sets of K separated by a dash
    for (size_t i = 0, I = S.size(), k = 0; i < I; ++i, ++k, k %= K) {
      R += S[i];
      if (int(k) == K - 1 && i < I - 1) {
        R += '-';
      }
    }

    reverse(R.begin(), R.end());

    return R;
  }
};
