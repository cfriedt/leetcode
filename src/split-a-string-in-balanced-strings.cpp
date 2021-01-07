/*
 * Copyright (c) 2018 Christopher Friedt
 *
 * SPDX-License-Identifier: MIT
 */

#include <string>

using namespace std;

class Solution {
public:
  // https://leetcode.com/problems/split-a-string-in-balanced-strings/

  int balancedStringSplit(string s) {

    /*
     * ex
     * RLRRLLRLRL
     *
     * p1 p2 c1 c2 balance npairs
     * 0  1  R  L  0       1
     * 2  3  R  R  -2      1
     * 2  4  R  L  -1      1
     * 2  5  R  L  0       2
     * 6  7  R  L  0       3
     * 8  9  R  L  0       4
     */

    int r = 0;
    int balance = 0;
    for (size_t p1 = 0, p2 = 1, N = s.size(); p1 + 1 < N && p2 < N;) {
      if ((0 == p1 && 1 == p2) || 0 == balance) {
        balance += (s[p1] == 'R') ? -1 : 1;
      }

      balance += (s[p2] == 'R') ? -1 : 1;

      if (0 == balance) {
        ++r;
        p1 = p2 + 1;
        p2 += 2;
      } else {
        ++p2;
      }
    }

    return r;
  }
};
