/*
 * Copyright (c) 2021, Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

// clang-format off
// name: isomorphic-strings
// url: https://leetcode.com/problems/isomorphic-strings
// difficulty: 1
// clang-format on

#include <array>

using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    const size_t N = s.size();
    const size_t M = t.size();

    if (N != M) {
      return false;
    }

    array<char, 128> lut;
    lut.fill(-1);
    array<char, 128> rlut;
    rlut.fill(-1);

    // i           0   1   2
    // s[i]        e   g   g
    // t[i]        a   d   d
    // lut[s[i]]  -1  -1   d
    // rlut[t[i]] -1  -1   g
    //
    // lut[]      e:a g:d
    // rlut[]     a:e d:g

    for (size_t i = 0; i < N; ++i) {
      if (lut[s[i]] == char(-1)) {
        if (rlut[t[i]] != char(-1)) {
          return false;
        }
        lut[s[i]] = t[i];
        rlut[t[i]] = s[i];
        continue;
      }

      if (s[i] != rlut[t[i]]) {
        return false;
      }

      if (t[i] != lut[s[i]]) {
        return false;
      }
    }

    return true;
  }
};
